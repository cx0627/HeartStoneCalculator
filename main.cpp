#include <iostream>
#include "./card/Card.h"
#include "card/Handle.h"
#include "./card/CardList.h"
#include "./calculator/PlayCardCheckUp.h"

using CheckUp::defaultPlayCardCheckUp;
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Property property;
    property.setLastCost(10);
//    property.setCard(0, new SpiritOfTheShark());
//    property.getCard(0)->work();
    property.addCard(new SpiritOfTheShark());
    cout << defaultPlayCardCheckUp.PreCheckUp(property.getCard(0), &property) << endl;
    defaultPlayCardCheckUp.CostCount(property.getCard(0), &property);
    cout << property.getLastCost() << endl;
    cout << defaultPlayCardCheckUp.PreCheckUp(property.getCard(0), &property) << endl;
    defaultPlayCardCheckUp.CostCount(property.getCard(0), &property);
    cout << property.getLastCost() << endl;
    cout << defaultPlayCardCheckUp.PreCheckUp(property.getCard(0), &property) << endl;
    defaultPlayCardCheckUp.CostCount(property.getCard(0), &property);
    cout << property.getLastCost() << endl;
    return 0;
}
