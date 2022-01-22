#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


/**
 * \brief Возможность расчета функции в точке.
 * \param точка x - Входной параметр .
 * \return true, если функция определена в заданной точке x.
 */
bool IsCalculated(const double x);

/**
 * \brief Расчет функции в точке x.
 * \param точка x - Входной параметр.
 * \return Значение функции в точке x
 */
double Calculation(const double x);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto leftBound = 2.0;
    const auto rightBound = 3.0;
    const auto step = 0.1;

    auto x = leftBound;
    cout << "  x" << setw(15) << "y\n";
    while ((x < rightBound) || (abs(x - rightBound) < step))
    {
        if (IsCalculated(x))
        {
            const auto y = Calculation(x);
            cout << setw(10) << setprecision(2) << x << setw(15)
                << setprecision(5) << y << '\n';
        }
        else
        {
            cout << setw(10) << setprecision(2) << x << setw(15)
                << "not defined \n";
        }
        x += step;
    }
    return 0;
}

double Calculation(const double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

bool IsCalculated(const double x)
{
    return x > 0;
}