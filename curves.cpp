#include "curves.h"

bool Circle::isParamValid(const double &t)
{
    if (t < 0.0 || t > 2.0 * PI || std::fabs(2.0 * PI - t) < SIGMA)
        throw std::runtime_error("Invalid parameter \"t\" for circle.");
    else
        return true;
}

Circle::Circle(double _r)
{
    if (_r < 0)
        throw std::runtime_error("Invalid radius for circle.");
    r = _r;
}

Point &Circle::getPoint(double t)
{
    if (isParamValid(t))
    {
        double x = r * cos(t);
        double y = r * sin(t);

        std::fabs(x) < SIGMA ? point.x = 0.0 : point.x = x;
        std::fabs(y) < SIGMA ? point.y = 0.0 : point.y = y;

        point.z = 0.0;

        return point;
    }
}

DerivativeVector &Circle::getDerivative(double t)
{
    if (isParamValid(t))
    {
        double i = -r * sin(t);
        double j = r * cos(t);

        std::fabs(i) < SIGMA ? vector.i = 0.0 : vector.i = i;
        std::fabs(j) < SIGMA ? vector.j = 0.0 : vector.j = j;

        vector.k = 0.0;

        return vector;
    }
}

bool Circle::operator<(const Circle &circle)
{
    return r < circle.r;
}

Circle Circle::operator*()
{
    return *this;
}

double Circle::getRadius()
{
    return r;
}

bool Ellipse::isParamValid(const double &t)
{
    if (t < 0 || t > 2 * PI || std::fabs(2 * PI - t) < SIGMA)
        throw std::runtime_error("Invalid parameter \"t\" for Ellipse.");
    else
        return true;
}

Ellipse::Ellipse(double _rx, double _ry)
{
    if (_rx < 0 || _ry < 0)
        throw std::runtime_error("Invalid radius for ellipse.");
    rx = _rx;
    ry = _ry;
}

Point &Ellipse::getPoint(double t)
{
    if (isParamValid(t))
    {
        double x = rx * cos(t);
        double y = ry * sin(t);

        std::fabs(x) < SIGMA ? point.x = 0.0 : point.x = x;
        std::fabs(y) < SIGMA ? point.y = 0.0 : point.y = y;

        point.z = 0.0;

        return point;
    }
}

DerivativeVector &Ellipse::getDerivative(double t)
{
    if (isParamValid(t))
    {
        double i = -rx * sin(t);
        double j = ry * cos(t);

        std::fabs(i) < SIGMA ? vector.i = 0.0 : vector.i = i;
        std::fabs(j) < SIGMA ? vector.j = 0.0 : vector.j = j;

        vector.k = 0.0;

        return vector;
    }
}

bool Helix::isParamValid(const double &t)
{
    if (t < 0.0)
        throw std::runtime_error("Invalid parameter \"t\" for helix.");
    else
        return true;
}

Helix::Helix(double _r, double _step)
{
    if (_r < 0)
        throw std::runtime_error("Invalid radius for helix.");
    r = _r;
    step = _step;
}

Point &Helix::getPoint(double t)
{
    if (isParamValid(t))
    {
        double x = r * cos(t);
        double y = r * sin(t);
        double z = step * t / (2 * PI);

        std::fabs(x) < SIGMA ? point.x = 0.0 : point.x = x;
        std::fabs(y) < SIGMA ? point.y = 0.0 : point.y = y;
        std::fabs(z) < SIGMA ? point.y = 0.0 : point.z = z;

        return point;
    }
}

DerivativeVector &Helix::getDerivative(double t)
{
    if (isParamValid(t))
    {
        double i = -r * sin(t);
        double j = r * cos(t);

        std::fabs(i) < SIGMA ? vector.i = 0.0 : vector.i = i;
        std::fabs(j) < SIGMA ? vector.j = 0.0 : vector.j = j;

        vector.k = step / (2 * PI);

        return vector;
    }
}