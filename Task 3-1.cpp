#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение функции y
**/

double gety(const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double x = 2;
    const auto y = gety(x);
}

double gety(const double x)
{
    for (double x = 2; x <= 3; x = x + 0.1)
    {
        cout << "y = " << sin(3) * sqrt(x) + 0.39 * x - 3.8 << endl;
    }
    return 1;
}