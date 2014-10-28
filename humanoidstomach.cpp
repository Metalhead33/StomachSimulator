#include "humanoidstomach.h"

constexpr double HumanoidStomach::GetEnergy()
{
    return (-50.00 * (dws - mdws) * (dws + (mdws * 2.00))) / ((dws + mdws) * (dws + mdws));
}
constexpr double HumanoidStomach::GetDws()
{
    return dws;
}
constexpr double HumanoidStomach::GetMdws()
{
    return mdws;
}
void HumanoidStomach::SetDws(double to_set)
{
    dws = to_set;
}
void HumanoidStomach::SetMdws(double to_set)
{
    mdws = to_set;
}

HumanoidStomach::HumanoidStomach()
    : stomach()
{
    mdws = 4.00;
}
constexpr double HumanoidStomach::GetTotalFatNeed()
{
    return (mdws * 5.25) * FatNeed();
}
constexpr double HumanoidStomach::GetTotalSugarNeed()
{
    return (mdws * 5.25) * SugarNeed();
}
constexpr double HumanoidStomach::GetTotalProteinNeed()
{
    return (mdws * 5.25) * ProteinNeed();
}
constexpr double HumanoidStomach::GetFatExhaustion()
{
    return GetTotalFatNeed() - GetFatContent();
}
constexpr double HumanoidStomach::GetSugarExhaustion()
{
    return GetTotalSugarNeed() - GetSugarContent();
}
constexpr double HumanoidStomach::GetProteinExhaustion()
{
    return GetTotalProteinNeed() - GetProteinContent();
}
constexpr double HumanoidStomach::GetFatExhaustion_indays()
{
    return GetFatExhaustion() / FatNeed();
}
constexpr double HumanoidStomach::GetSugarExhaustion_indays()
{
    return GetSugarExhaustion() / SugarNeed();
}
constexpr double HumanoidStomach::GetProteinExhaustion_indays()
{
    return GetProteinExhaustion() / ProteinNeed();
}
constexpr double HumanoidStomach::GetActualFatLevel()
{
    return (-50.00 * (GetFatExhaustion_indays() - (mdws * 5.25)) * (GetFatExhaustion_indays() + (mdws * 5.25 * 2.00))) / ((GetFatExhaustion_indays() + (mdws * 5.25)) * (GetFatExhaustion_indays() + (mdws * 5.25)));
}
constexpr double HumanoidStomach::GetActualSugarLevel()
{
    return (-50.00 * (GetSugarExhaustion_indays() - (mdws * 5.25)) * (GetSugarExhaustion_indays() + (mdws * 5.25 * 2.00))) / ((GetSugarExhaustion_indays() + (mdws * 5.25)) * (GetSugarExhaustion_indays() + (mdws * 5.25)));
}
constexpr double HumanoidStomach::GetActualProteinLevel()
{
    return (-50.00 * (GetProteinExhaustion_indays() - (mdws * 5.25)) * (GetProteinExhaustion_indays() + (mdws * 5.25 * 2.00))) / ((GetProteinExhaustion_indays() + (mdws * 5.25)) * (GetProteinExhaustion_indays() + (mdws * 5.25)));
}

void HumanoidStomach::DailySubstration(double days)
{
    SubstractFat(FatNeed() * days);
    SubstractProtein(ProteinNeed() * days);
    SubstractSugar(SugarNeed() * days);
    SubstractAlcohol(days * 24.00);
    dws += days;
}
void HumanoidStomach::HourlySubstration(double hours)
{
    SubstractFat(FatNeed() * (hours / 24.00));
    SubstractProtein(ProteinNeed() * (hours / 24.00));
    SubstractSugar(SugarNeed() * (hours / 24.00));
    SubstractAlcohol(hours);
    dws += (hours / 24.00);
}
void HumanoidStomach::TrainingSubstration(double hours, double effort)
{
    SubstractCalories(hours * effort * 8.50);
    SubstractAlcohol(0.01 * (hours * effort * (2.00 / 3.00)));
    dws += (hours / 24.00) * effort * (2.00 / 3.00);
}
