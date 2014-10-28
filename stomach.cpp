#include "stomach.h"
#include "exchange.h"

constexpr double stomach::GetAlcoholResistance()
{
    return alcohol_resistance;
}
void stomach::SetAlcoholResistance(double setto)
{
    alcohol_resistance = setto;
}
void stomach::FeedFat(double fat)
{
    FatContent += fat;
    if (FatContent < 0.00)
        FatContent = 0.00;
}
void stomach::FeedProtein(double protein)
{
    ProteinContent += protein;
    if (ProteinContent < 0.00)
        ProteinContent = 0.00;
}
void stomach::FeedSugar(double sugar)
{
    SugarContent += sugar;
    if (SugarContent < 0.00)
        SugarContent = 0.00;
}
void stomach::FeedAlcohol(double alcohol)
{
    FeedSugar(AlcoholToSugar(alcohol));
    alcohol_blood_content += AlcoholBloodcontent(RealWeight(),alcohol,alcohol_resistance);
    if (alcohol_blood_content < 0.00)
        alcohol_blood_content = 0.00;
}
void stomach::FeedAlcoholDirect(double alcohol)
{
    alcohol_blood_content += alcohol;
    if (alcohol_blood_content < 0.00)
        alcohol_blood_content = 0.00;
}
void stomach::SubstractFat(double fat)
{
    FatContent -= fat;
    if (FatContent < 0.00)
        FatContent = 0.00;
}
void stomach::SubstractProtein(double protein)
{
    ProteinContent -= protein;
    if (ProteinContent < 0.00)
        ProteinContent = 0.00;
}
void stomach::SubstractSugar(double sugar)
{
    SugarContent -= sugar;
    if (SugarContent < 0.00)
        SugarContent = 0.00;
}
void stomach::SubstractAlcohol(double alcohol)
{
    alcohol_blood_content -= alcohol;
    if (alcohol_blood_content < 0.00)
        alcohol_blood_content = 0.00;
}
constexpr double stomach::GetFatContent()
{
    return FatContent;
}
constexpr double stomach::GetProteinContent()
{
    return ProteinContent;
}
constexpr double stomach::GetSugarContent()
{
    return SugarContent;
}
constexpr double stomach::GetAlcoholContent()
{
    return alcohol_blood_content;
}
constexpr double stomach::GetFatMultiplier()
{
    return fat_multiplier;
}
constexpr double stomach::GetSugarMultiplier()
{
    return sugar_multiplier;
}
constexpr double stomach::GetProteinMultiplier()
{
    return protein_multiplier;
}
constexpr double stomach::GetNominalWeight()
{
    return nominal_weight;
}
void stomach::SetFatContent(double setto)
{
    FatContent = setto;
    if (FatContent < 0.00)
        FatContent = 0.00;
}
void stomach::SetProteinContent(double setto)
{
    ProteinContent = setto;
    if (ProteinContent < 0.00)
        ProteinContent = 0.00;
}
void stomach::SetSugarContent(double setto)
{
    SugarContent = setto;
    if (SugarContent < 0.00)
        SugarContent = 0.00;
}
void stomach::SetAlcoholContent(double setto)
{
    alcohol_blood_content = setto;
    if (alcohol_blood_content < 0.00)
        alcohol_blood_content = 0.00;
}
void stomach::SetFatMultiplier(double setto)
{
    fat_multiplier = setto;
}
void stomach::SetSugarMultiplier(double setto)
{
    sugar_multiplier = setto;
}
void stomach::SetProteinMultiplier(double setto)
{
    protein_multiplier = setto;
}
void stomach::SetNominalWeight(double setto)
{
    nominal_weight = setto;
}
stomach::stomach()
{
    FatContent = 0.00;
    ProteinContent = 0.00;
    SugarContent = 0.00;
    alcohol_blood_content = 0.00;
    fat_multiplier = 1.00;
    sugar_multiplier = 1.00;
    protein_multiplier = 1.00;
    nominal_weight = 60.00;
    alcohol_resistance = 0.00;
}
constexpr double TotalContent()
{
    return FatToCalories(FatContent) + ProteinToCalories(ProteinContent) + SugarToCalories(SugarContent);
}
constexpr double stomach::FatNeed()
{
    return WeighttoCalories(nominal_weight) * 0.520711197 * fat_multiplier;
}
constexpr double stomach::ProteinNeed()
{
    return WeighttoCalories(nominal_weight) * 0.21081211 * protein_multiplier;
}
constexpr double stomach::SugarNeed()
{
    return WeighttoCalories(nominal_weight) * 0.26934166 * sugar_multiplier;
}
constexpr double stomach::TotalNeed()
{
    return FatNeed() + ProteinNeed() + SugarNeed();
}
constexpr double stomach::RealWeight()
{
    return CaloriesToWeight(TotalNeed());
}
constexpr double stomach::FatLevel()
{
    return FatContent / FatNeed();
}
constexpr double stomach::ProteinLevel()
{
    return ProteinContent / ProteinNeed();
}
constexpr double stomach::SugarLevel()
{
    return SugarContent / SugarNeed();
}
constexpr unsigned char stomach::AlcoholLevel()
{
    return AlcoholState(alcohol_blood_content);
}
constexpr double stomach::FatRatio()
{
    return FatNeed() / TotalNeed();
}
constexpr double stomach::ProteinRatio()
{
    return ProteinNeed() / TotalNeed();
}
constexpr double stomach::SugarRatio()
{
    return SugarNeed() / TotalNeed();
}
void SubstractCalories(double calories)
{
    SubstractFat(FatRatio() * calories);
    SubstractProtein(ProteinRatio() * calories);
    SubstractSugar(SugarRatio() * calories);
}
