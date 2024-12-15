#pragma once

#ifndef RIVER_H
#define RIVER_H

#include "WaterBody.h"

class River : public WaterBody {
public:
    River(double a, double p, double d)
        : WaterBody(a, p, d, false) {}

    double calculateArea() override {
        return area; // ��� ���� ����� �������� �� ������ �� �������
    }

    double calculatePerimeter() override {
        return perimeter; // ��� ���� ������ ��������
    }
};

#endif // RIVER_H
