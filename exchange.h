#ifndef EXCHANGE_H
#define EXCHANGE_H
constexpr double CaloriesToWeight(double calories) {return calories / 32.02049312;}
constexpr double WeighttoCalories(double weight) {return weight * 32.02049312;}
constexpr double SugarToCalories(double sugar) {return sugar * 4.20;}
constexpr double CaloriesToSugar(double calories) {return calories / 4.20;}
constexpr double FatToCalories(double fat) {return fat * 9.50;}
constexpr double CaloriesToFat(double calories) {return calories / 9.50;}
constexpr double ProteinToCalories(double protein) {return protein * 4.10;}
constexpr double CaloriesToProtein(double calories) {return calories / 4.10;}
constexpr double AlcoholToCalories(double alcohol) {return alcohol * 7.00;}
constexpr double CaloriesToAlcohol(double calories) {return calories / 7.00;}
constexpr double LethalAlcoholAmountGram(double weight) {return (weight / 64.00) * 204.6050847;}
constexpr double LethalAlcoholAmountCalories(double weight) {return AlcoholToCalories(LethalAlcoholAmountGram(weight));}
constexpr double AlcoholBloodcontent(double weight, double alcohol, double resistance)
{return ((alcohol / 0.789) * (1.00 / (508.4745763 / 62.00 * weight))) / ((resistance + 100.00) / 100.00);}
constexpr unsigned char AlcoholState(double alcohol_blood_content) {
    if (alcohol_blood_content < 0.029)
        return 0; // Normal
    else if (alcohol_blood_content < 0.059)
        return 1; // Tipsy
    else if (alcohol_blood_content < 0.090)
        return 2; // Drunk
    else if (alcohol_blood_content < 0.190)
        return 3; // Very Drunk
    else if (alcohol_blood_content < 0.290)
        return 4; // Wasted
    else if (alcohol_blood_content < 0.390)
        return 5; // Non-lethal alcohol poisoning
    else if (alcohol_blood_content < 0.500)
        return 6; // Lethal alcohol poisoning
    else
        return 7; // Instant Death
}
constexpr double AlcoholToSugar(double alcohol) {return CaloriesToSugar(AlcoholToCalories(alcohol));}
#endif // EXCHANGE_H
