#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <windows.h> //добавил данную библиотеку для взаимодействия с ОС

using namespace std;

/**
* \brief Математическая функция, рассчитывающая объём шара
* \radius - радиус шара
**/
enum class Sphere
{
	/**
	 * \brief Объём шара.
	 */
	Volume,

	/**
	 * \brief Площадь поверхности шара.
	 */
	 SurfaceArea
};
double getVolume(const double radius);

/**
* \brief Математическая функция, рассчитывающая площадь поверхности шара
* \radius - радиус шара
**/
double getSurfaceArea(const double radius);

/**
 * \brief Точка входа в программу.
 */
int main()
{
	SetConsoleCP(1251); //использую данную команду для отображения кириллицы в консоли
	SetConsoleOutputCP(1251); //использую данную команду для отображения кириллицы в консоли
	{
		cout << "Выберите то, что вы бы хотели узнать"
			<< "\n Объём - " << static_cast<int>(Sphere::Volume)
			<< "\n Площадь поверхности - " << static_cast<int>(Sphere::SurfaceArea);
		cout << endl;
		int sphere;
		cin >> sphere;
		double radius = 0.0;
		cout << "Введите radius ";
		cin >> radius;

		const auto Figure = static_cast<Sphere>(sphere);
		switch (Figure)
		{
		case Sphere::Volume:
			cout << "V = " << getVolume(radius);
			break;
		case Sphere::SurfaceArea:
			cout << "S = " << getSurfaceArea(radius);
			break;
			return 0;
		}
	}

}

double getVolume(const double radius)
{
	return pow(radius, 3) * ((4 * M_PI) / 3);
}
double getSurfaceArea(const double radius)
{
	return pow(radius, 2) * M_PI * 4;
}