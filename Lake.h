#pragma once

#ifndef LAKE_H
#define LAKE_H

#include "WaterBody.h"

class Lake : public WaterBody {
public:
    Lake(double a, double p, double d)
        : WaterBody(a, p, d, false) {}

    double calculateArea() override {
        return area; // Для озера просто площа
    }

    double calculatePerimeter() override {
        return perimeter; // Для озера просто периметр
    }
};

#endif // LAKE_H
