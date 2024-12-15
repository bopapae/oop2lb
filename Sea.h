#pragma once

#ifndef SEA_H
#define SEA_H

#include "WaterBody.h"

class Sea : public WaterBody {
public:
    Sea(double a, double p, double d)
        : WaterBody(a, p, d, true) {}

    double calculateArea() override {
        return area; // Для моря площа
    }

    double calculatePerimeter() override {
        return perimeter; // Для моря периметр
    }
};

#endif // SEA_H
