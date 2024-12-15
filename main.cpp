#include <iostream>
#include "WaterBody.h"
#include "Lake.h"
#include "River.h"
#include "Pool.h"
#include "Sea.h"
#include "Ocean.h"


class WaterBodyContainer {
private:
    std::vector<WaterBody*> waterBodies;

public:
    void addWaterBody(WaterBody* wb) {
        waterBodies.push_back(wb);
    }

    WaterBody* findDeepest() {
        return *std::max_element(waterBodies.begin(), waterBodies.end(),
            [](WaterBody* a, WaterBody* b) {
                return a->getDepth() < b->getDepth();
            });
    }

    void printOrderedByArea() {
        std::sort(waterBodies.begin(), waterBodies.end(),
            [](WaterBody* a, WaterBody* b) {
                return a->calculateArea() > b->calculateArea();
            });
        for (auto wb : waterBodies) {
            wb->print();
        }
    }

    void printByWaterType(bool saltWater) {
        for (auto wb : waterBodies) {
            if (wb->getIsSaltWater() == saltWater) {
                wb->print();
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");

    // Створюємо об'єкти
    Lake lake(150.0, 50.0, 20.0);
    River river(200.0, 100.0, 5.0);
    Pool pool(25.0, 30.0, 2.0);
    Sea sea(10000.0, 400.0, 200.0);
    Ocean ocean(1000000.0, 10000.0, 11000.0);

    // Створюємо контейнер і додаємо водойми
    WaterBodyContainer container;
    container.addWaterBody(&lake);
    container.addWaterBody(&river);
    container.addWaterBody(&pool);
    container.addWaterBody(&sea);
    container.addWaterBody(&ocean);

    // Пошук водойми з найбільшою глибиною
    WaterBody* deepest = container.findDeepest();
    std::cout << "Водойма з найбiльшою глибиною:" << std::endl;
    deepest->print();

    // Виведення водойм у порядку зменшення площі
    std::cout << "\nВодойми у порядку зменшення площi:" << std::endl;
    container.printOrderedByArea();

    // Виведення солоних водойм
    std::cout << "\nСолонi водойми:" << std::endl;
    container.printByWaterType(true);

    // Виведення прісних водойм
    std::cout << "\nПрiснi водойми:" << std::endl;
    container.printByWaterType(false);

    return 0;
}
