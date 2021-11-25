#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая объём шара
* \radius - радиус шара
**/
double getVolume(const double r);

/**
* \brief Математическая функция, рассчитывающая площадь поверхности шара
* \radius - радиус шара
**/
double getSurfaceArea(const double r);

/**
 * \brief Точка входа в программу.
 */
int main() 
{
    double radius;

    cout << "Введите радиус и нажмите Enter: \n";
    cin >> radius;

    const auto Volume = getVolume(radius);
    const auto SurfaceArea = getSurfaceArea(radius);

    cout << "Радиус radius = " << radius << "\n Объём шара = " << Volume << "\n Площадь поверхности шара = " << SurfaceArea;
    return 0;
}

double getVolume(const double radius) 
{
    return pow(radius, 3) * ((4 * M_PI) / 3);
}
double getSurfaceArea(const double radius)
{
    return pow(radius, 2) * M_PI * 4;
}