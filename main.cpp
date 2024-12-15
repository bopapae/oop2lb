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

    // ��������� ��'����
    Lake lake(150.0, 50.0, 20.0);
    River river(200.0, 100.0, 5.0);
    Pool pool(25.0, 30.0, 2.0);
    Sea sea(10000.0, 400.0, 200.0);
    Ocean ocean(1000000.0, 10000.0, 11000.0);

    // ��������� ��������� � ������ �������
    WaterBodyContainer container;
    container.addWaterBody(&lake);
    container.addWaterBody(&river);
    container.addWaterBody(&pool);
    container.addWaterBody(&sea);
    container.addWaterBody(&ocean);

    // ����� ������� � ��������� ��������
    WaterBody* deepest = container.findDeepest();
    std::cout << "������� � ����i����� ��������:" << std::endl;
    deepest->print();

    // ��������� ������ � ������� ��������� �����
    std::cout << "\n������� � ������� ��������� ����i:" << std::endl;
    container.printOrderedByArea();

    // ��������� ������� ������
    std::cout << "\n�����i �������:" << std::endl;
    container.printByWaterType(true);

    // ��������� ������ ������
    std::cout << "\n��i��i �������:" << std::endl;
    container.printByWaterType(false);

    return 0;
}
