#include <iostream>
#include "./card/Card.h"
#include "card/Handle.h"
#include "./card/CardList.h"
#include "./calculator/PlayCardCheckUp.h"
#include "./calculator/Calculator.h"

#pragma comment(linker, "/STACK:102400000,102400000")

using CheckUp::defaultPlayCardCheckUp;
using namespace std;

int main() {
//    freopen("log.txt", "w", stdout);
    std::cout << "Hello, World!" << std::endl;
    Property property;
    property.setLastCost(6);
//    property.setCard(0, new SpiritOfTheSharkCard());
//    property.getCard(0)->work();
//    property.addCard(new SpiritOfTheSharkCard());
//    property.addCard(new FoxyFraudCard());


    property.addCard(new ScabbsCutterbutterCard());
    property.addCard(new CoinCard());
    property.addCard(new CoinCard());
    property.addCard(new PotionOfIllusionCard());
    property.addCard(new TenwuOfTheRedSmokeCard());
    property.addCard(new SpectralPillagerCard());
    property.addCard(new ShadowStepCard());
    property.addCard(new ShadowStepCard());
    property.addCard(new FoxyFraudCard());


//    property.addCard(new FoxyFraudCard());
//    property.addCard(new ShadowStepCard());
//    property.addCard(new ShadowStepCard());
//    property.addCard(new ScabbsCutterbutterCard());

//    SpiritOfTheSharkCard* spiritOfTheShark = new SpiritOfTheSharkCard();
//    spiritOfTheShark->getNextLegalTarget(0, &property);
//    cout << defaultPlayCardCheckUp.PreCheckUp(property.getCard(0), &property) << endl;
//    defaultPlayCardCheckUp.CostCount(property.getCard(0), &property);
//    cout << property.getLastCost() << endl;
//    cout << defaultPlayCardCheckUp.PreCheckUp(property.getCard(0), &property) << endl;
//    defaultPlayCardCheckUp.CostCount(property.getCard(0), &property);
//    cout << property.getLastCost() << endl;
//    cout << defaultPlayCardCheckUp.PreCheckUp(property.getCard(0), &property) << endl;
//    defaultPlayCardCheckUp.CostCount(property.getCard(0), &property);
//    cout << property.getLastCost() << endl;
//    cout << property.getCard(0)->getNextHandle(0, PlayCard) << endl;
    Calculator calculator;
    calculator.CalculateLethal(&property);
    return 0;
}
