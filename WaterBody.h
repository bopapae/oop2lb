#pragma once

#ifndef WATERBODY_H
#define WATERBODY_H

#include <iostream>
#include <vector>
#include <algorithm>

class WaterBody {
protected:
    double area;        // Площа
    double perimeter;   // Периметр
    double depth;       // Глибина
    bool isSaltWater;   // Чи є солона вода?

public:
    WaterBody(double a, double p, double d, bool salt)
        : area(a), perimeter(p), depth(d), isSaltWater(salt) {}

    virtual double calculateArea() = 0;      // Віртуальна функція для обчислення площі
    virtual double calculatePerimeter() = 0; // Віртуальна функція для обчислення периметра

    double getDepth() const { return depth; }  // Отримати глибину
    bool getIsSaltWater() const { return isSaltWater; } // Отримати тип води

    virtual void print() const {
        std::cout << "Площа: " << area << ", Периметр: " << perimeter
            << ", Глибина: " << depth << ", Солона вода: "
            << (isSaltWater ? "Так" : "Нi") << std::endl;
    }
};

#endif // WATERBODY_H
