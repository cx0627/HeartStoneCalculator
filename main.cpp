#include <iostream>
#include "./card/Card.h"
#include "card/Handle.h"
#include "./card/CardList.h"
#include "./calculator/PlayCardCheckUp.h"
#include "./calculator/Calculator.h"

using CheckUp::defaultPlayCardCheckUp;
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Property property;
    property.setLastCost(4);
//    property.setCard(0, new SpiritOfTheSharkCard());
//    property.getCard(0)->work();
    property.addCard(new SpiritOfTheSharkCard());
    property.addCard(new FoxyFraudCard());
    property.addCard(new ScabbsCutterbutterCard());
    property.addCard(new ShadowStepCard());
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
