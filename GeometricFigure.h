#pragma once
#include <iostream>
class GeometricFigure
{
protected:
    double centerX;
    double centerY;
    double rotationAngle; // у градусах
    double scaleFactor;

public:
    GeometricFigure(double x, double y, double angle, double scale)
        : centerX(x), centerY(y), rotationAngle(angle), scaleFactor(scale) {}

    virtual void show() const = 0; // чисто віртуальна функція
    virtual void hide() const = 0;
    virtual void rotate(double angle) = 0;
    virtual void move(double deltaX, double deltaY) = 0;

    virtual ~GeometricFigure() = default;
};

class Circle : public GeometricFigure {
private:
    double radius;

public:
    Circle(double x, double y, double angle, double scale, double r)
        : GeometricFigure(x, y, angle, scale), radius(r) {}

    void show() const override {
        std::cout << "Показано коло на (" << centerX << ", " << centerY << ") з радіусом " << radius << std::endl;
    }

    void hide() const override {
        std::cout << "Приховування Коло на (" << centerX << ", " << centerY << ")" << std::endl;
    }

    void rotate(double angle) override {
        rotationAngle += angle;
        std::cout << "Обертове коло по " << angle << " ступенів" << std::endl;
    }

    void move(double deltaX, double deltaY) override {
        centerX += deltaX;
        centerY += deltaY;
        std::cout << "Переміщення кола до (" << centerX << ", " << centerY << ")" << std::endl;
    }
};

