#pragma once

#ifndef WATERBODY_H
#define WATERBODY_H

#include <iostream>
#include <vector>
#include <algorithm>

class WaterBody {
protected:
    double area;        // �����
    double perimeter;   // ��������
    double depth;       // �������
    bool isSaltWater;   // �� � ������ ����?

public:
    WaterBody(double a, double p, double d, bool salt)
        : area(a), perimeter(p), depth(d), isSaltWater(salt) {}

    virtual double calculateArea() = 0;      // ³�������� ������� ��� ���������� �����
    virtual double calculatePerimeter() = 0; // ³�������� ������� ��� ���������� ���������

    double getDepth() const { return depth; }  // �������� �������
    bool getIsSaltWater() const { return isSaltWater; } // �������� ��� ����

    virtual void print() const {
        std::cout << "�����: " << area << ", ��������: " << perimeter
            << ", �������: " << depth << ", ������ ����: "
            << (isSaltWater ? "���" : "�i") << std::endl;
    }
};

#endif // WATERBODY_H
