#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <any>
#include <algorithm>
#include "curves.h"

void printPointsCoordinates(std::vector<std::any> &vecObj, const double &t)
{
    for (auto itr = vecObj.begin(); itr != vecObj.end(); ++itr)
    {
        if (Circle *a = std::any_cast<Circle>(&*itr))
        {
            std::cout << "Circle:" << std::endl;
            std::cout << "Point: {" << (*a).getPoint(t).x << "; " << (*a).getPoint(t).y << "; " << (*a).getPoint(t).z << "}" << std::endl;
            std::cout << std::endl;
        }
        else if (Ellipse *a = std::any_cast<Ellipse>(&*itr))
        {
            std::cout << "Ellipse:" << std::endl;
            std::cout << "Point: {" << (*a).getPoint(t).x << "; " << (*a).getPoint(t).y << "; " << (*a).getPoint(t).z << "}" << std::endl;
            std::cout << std::endl;
        }
        else if (Helix *a = std::any_cast<Helix>(&*itr))
        {
            std::cout << "Helix:" << std::endl;
            std::cout << "Point: {" << (*a).getPoint(t).x << "; " << (*a).getPoint(t).y << "; " << (*a).getPoint(t).z << "}" << std::endl;
            std::cout << std::endl;
        }
        else
            ;
    }
}

void printPointsDerivatives(std::vector<std::any> &vecObj, const double &t)
{
    for (auto itr = vecObj.begin(); itr != vecObj.end(); ++itr)
    {
        if (Circle *a = std::any_cast<Circle>(&*itr))
        {
            std::cout << "Circle:" << std::endl;
            std::cout << "Vector: (" << (*a).getDerivative(t).i << "; " << (*a).getDerivative(t).j << "; " << (*a).getDerivative(t).k << ")" << std::endl;
            std::cout << std::endl;
        }
        else if (Ellipse *a = std::any_cast<Ellipse>(&*itr))
        {
            std::cout << "Ellipse:" << std::endl;
            std::cout << "Vector: (" << (*a).getDerivative(t).i << "; " << (*a).getDerivative(t).j << "; " << (*a).getDerivative(t).k << ")" << std::endl;
            std::cout << std::endl;
        }
        else if (Helix *a = std::any_cast<Helix>(&*itr))
        {
            std::cout << "Helix:" << std::endl;
            std::cout << "Vector: (" << (*a).getDerivative(t).i << "; " << (*a).getDerivative(t).j << "; " << (*a).getDerivative(t).k << ")" << std::endl;
            std::cout << std::endl;
        }
        else
            ;
    }
}

void printCirclesRadii(std::vector<Circle *> vecCircle)
{
    std::cout << "Radii:" << std::endl;
    for (const auto circlePtr : vecCircle)
        std::cout << circlePtr->getRadius() << std::endl;
    std::cout << std::endl;
}

double calcCirclesRadiiSum(std::vector<Circle *> vecCircle)
{
    double sumRadii = 0.0;
    for (const auto circlePtr : vecCircle)
        sumRadii += circlePtr->getRadius();

    return sumRadii;
}

int main(int argc, char **argv)
{
    try
    {
        std::vector<std::any> vecObj;

        Circle circleA(10.0);
        Circle circleB(5.5);
        Circle circleC(0.7);
        Circle circleD(5.5);

        Ellipse ellipseA(3.0, 2.0);
        Ellipse ellipseB(1.88, 0.5);
        Ellipse ellipseC(3.0, 9.99);

        Helix helixA(10.0, 1.0);
        Helix helixB(5.5, 3.0);
        Helix helixC(0.7, 5.0);

        vecObj.push_back(circleA);
        vecObj.push_back(helixC);
        vecObj.push_back(circleB);
        vecObj.push_back(ellipseA);
        vecObj.push_back(ellipseB);
        vecObj.push_back(circleD);
        vecObj.push_back(helixA);
        vecObj.push_back(ellipseC);
        vecObj.push_back(circleC);
        vecObj.push_back(helixB);

        // Print points coordinates and derivatives
        printPointsCoordinates(vecObj, PI / 4);
        printPointsDerivatives(vecObj, PI / 4);

        // Filling vector of circles pointers
        std::vector<Circle *> vecCircle;
        for (auto itr = vecObj.begin(); itr != vecObj.end(); ++itr)
        {
            if (Circle *a = std::any_cast<Circle>(&*itr))
            {
                vecCircle.push_back(a);
            }
        }

        // Sorting
        std::sort(vecCircle.begin(), vecCircle.end(), [](const auto &ptrA, const auto &ptrB)
                  { return **ptrA < **ptrB; });

        // Print radii
        printCirclesRadii(vecCircle);

        // Print circles radii sum
        std::cout << "Radii sum: ";
        std::cout << calcCirclesRadiiSum(vecCircle) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}