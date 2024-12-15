#pragma once

#ifndef OCEAN_H
#define OCEAN_H

#include "WaterBody.h"

class Ocean : public WaterBody {
public:
    Ocean(double a, double p, double d)
        : WaterBody(a, p, d, true) {}

    double calculateArea() override {
        return area; // ��� ������ �����
    }

    double calculatePerimeter() override {
        return perimeter; // ��� ������ ��������
    }
};

#endif // OCEAN_H
