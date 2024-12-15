#pragma once

#ifndef RIVER_H
#define RIVER_H

#include "WaterBody.h"

class River : public WaterBody {
public:
    River(double a, double p, double d)
        : WaterBody(a, p, d, false) {}

    double calculateArea() override {
        return area; // Для річки площа залежить від ширини та довжини
    }

    double calculatePerimeter() override {
        return perimeter; // Для річки просто периметр
    }
};

#endif // RIVER_H
