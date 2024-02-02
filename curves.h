#pragma once

#include <cmath>
#include <stdexcept>

#ifndef SIGMA
#define SIGMA 0.01
#endif

#ifndef PI
#define PI 3.141
#endif

struct Point
{
public:
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

struct DerivativeVector
{
public:
    double i = 0.0;
    double j = 0.0;
    double k = 0.0;
};

class Curve
{
public:
    virtual Point &getPoint(double) = 0;
    virtual DerivativeVector &getDerivative(double) = 0;
    virtual ~Curve() {}
};

class Circle : public Curve
{
private:
    Point point;
    DerivativeVector vector;
    double r;
    bool isParamValid(const double &);

public:
    Circle(double);
    Point &getPoint(double) override;
    DerivativeVector &getDerivative(double) override;
    bool operator<(const Circle &);
    Circle operator*();
    double getRadius();
};

class Ellipse : public Curve
{
private:
    Point point;
    DerivativeVector vector;
    double rx;
    double ry;
    bool isParamValid(const double &);

public:
    Ellipse(double, double);
    Point &getPoint(double) override;
    DerivativeVector &getDerivative(double) override;
};

class Helix : public Curve
{
private:
    Point point;
    DerivativeVector vector;
    double r;
    double step;
    bool isParamValid(const double &);

public:
    Helix(double, double);
    Point &getPoint(double) override;
    DerivativeVector &getDerivative(double) override;
};