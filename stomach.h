#ifndef STOMACH_H
#define STOMACH_H

class stomach
{
private:
    double FatContent;
    double ProteinContent;
    double SugarContent;
    double alcohol_blood_content;
    double fat_multiplier;
    double sugar_multiplier;
    double protein_multiplier;
    double nominal_weight;
    double alcohol_resistance;
public:
    constexpr double GetAlcoholResistance();
    void SetAlcoholResistance(double setto);
    void FeedFat(double fat);
    void FeedProtein(double protein);
    void FeedSugar(double sugar);
    void FeedAlcohol(double alcohol);
    void FeedAlcoholDirect(double alcohol);
    void SubstractFat(double fat);
    void SubstractProtein(double protein);
    void SubstractSugar(double sugar);
    void SubstractAlcohol(double alcohol);
    constexpr double GetFatContent();
    constexpr double GetProteinContent();
    constexpr double GetSugarContent();
    constexpr double GetAlcoholContent();
    constexpr double GetFatMultiplier();
    constexpr double GetSugarMultiplier();
    constexpr double GetProteinMultiplier();
    constexpr double GetNominalWeight();
    void SetFatContent(double setto);
    void SetProteinContent(double setto);
    void SetSugarContent(double setto);
    void SetAlcoholContent(double setto);
    void SetFatMultiplier(double setto);
    void SetSugarMultiplier(double setto);
    void SetProteinMultiplier(double setto);
    void SetNominalWeight(double setto);
    stomach();
    constexpr double TotalContent();
    constexpr double FatNeed();
    constexpr double ProteinNeed();
    constexpr double SugarNeed();
    constexpr double TotalNeed();
    constexpr double RealWeight();
    constexpr double FatLevel();
    constexpr double ProteinLevel();
    constexpr double SugarLevel();
    constexpr unsigned char AlcoholLevel();
    constexpr double FatRatio();
    constexpr double ProteinRatio();
    constexpr double SugarRatio();
    void SubstractCalories(double calories);
};

#endif // STOMACH_H
