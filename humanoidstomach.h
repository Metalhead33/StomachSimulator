#ifndef HUMANOIDSTOMACH_H
#define HUMANOIDSTOMACH_H
#include "stomach.h"

class HumanoidStomach : public stomach
{
private:
    double dws;
    double mdws;
public:
    constexpr double GetTotalFatNeed();
    constexpr double GetTotalSugarNeed();
    constexpr double GetTotalProteinNeed();
    constexpr double GetFatExhaustion();
    constexpr double GetSugarExhaustion();
    constexpr double GetProteinExhaustion();
    constexpr double GetFatExhaustion_indays();
    constexpr double GetSugarExhaustion_indays();
    constexpr double GetProteinExhaustion_indays();
    constexpr double GetEnergy();
    constexpr double GetDws();
    constexpr double GetMdws();
    constexpr double GetActualFatLevel();
    constexpr double GetActualSugarLevel();
    constexpr double GetActualProteinLevel();
    void SetDws(double to_set);
    void SetMdws(double to_set);
    HumanoidStomach();
    void DailySubstration(double days);
    void HourlySubstration(double hours);
    void TrainingSubstration(double hours, double effort);
};

#endif // HUMANOIDSTOMACH_H
