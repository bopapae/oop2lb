#pragma once

#ifndef POOL_H
#define POOL_H

#include "WaterBody.h"

class Pool : public WaterBody {
public:
    Pool(double a, double p, double d)
        : WaterBody(a, p, d, false) {}

    double calculateArea() override {
        return area; // Для басейну просто площа
    }

    double calculatePerimeter() override {
        return perimeter; // Для басейну просто периметр
    }
};

#endif // POOL_H
