#include <iostream>
#include <string>
#include <random>

using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 * \brief Вывод элементов массива, значения которых больше заданного числа А.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrintIndex(const int* myArray, const size_t size);

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minimum минимальное значение элементов массива.
 * \param maximum максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int  minimum, int maximum);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* myArray, const size_t size);

/**
 * \brief Функция для нахождения суммы элементов, имеющих нечетное значение.
 * \param myArray массив.
 * \param size размер массива.
 * \return Сумма элементов, имеющих нечетное значение.
 */
int Sum(const int* myArray, const size_t size);

/**
 * \brief Замена второго элемента массива на максимальный среди отрицательных.
 * \param myArray массив.
 * \param size размер массива.
 * \return maximum максимальное значение, которое может принимать элемент массива.
 */
int* Replace(int* myArray, const size_t size, const int  minimum);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param  minimum минимальное значение элементов массива.
 * \param maximum максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size);

/**
 * \brief Варианы ввода массива.
 */
enum class ArrayInputWay
{
    random,
    keyboard
};

/**
 * \brief Точка входа в программу.
 * \return 0, в случае успеха.
 */
int main()
{
    size_t size = GetSize();

    if (size == 0)
        return 1;

    cout << "Как вы хотите заполнить массив?\n";
    cout << static_cast<int>(ArrayInputWay::random) << " - random,\n";
    cout << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;

    const auto chosen = static_cast<ArrayInputWay>(choice);
    int* myArray = nullptr;

    auto  minimum = 0;
    auto maximum = 0;
    cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl;
    cin >> minimum >> maximum;

    if (maximum <= minimum)
    {
        cout << "Введен неправильный диапазон!" << endl;
    }

    switch (chosen)
    {
    case ArrayInputWay::random:
    {
        myArray = FillRandomArray(size, minimum, maximum);
        break;
    }
    case ArrayInputWay::keyboard:
    {
        myArray = FillUserArray(size);
        break;
    }
    }

    ArrayPrint(myArray, size);

    cout << "Сумма нечетных элементов массива: " << Sum(myArray, size) << endl;

    Sum(myArray, size);

    cout << "Индексы элементов больших а" << endl;
    ArrayPrintIndex(myArray, size);
    cout << endl;

    Replace(myArray, size, minimum);
    ArrayPrint(myArray, size);

    myArray = Replace(myArray, size, maximum);
    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}

size_t GetSize() {
    int size = 0;
    cout << "Введите размер массива" << endl;
    cin >> size;
    if (size <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size;
};

int Sum(const int* myArray, const size_t size) {
    int sum = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 2 == 1)
            sum += myArray[index]; {
        }
    }
    return sum;
}

void ArrayPrintIndex(const int* myArray, const size_t size) {
    int a;
    cout << "Введите a" << endl;
    cin >> a;
    for (size_t index = 0; index < size; index++) {
        if ((myArray[index]) > a) {
            cout << index << " ";
        }
    }
}

int* Replace(int* myArray, const size_t size, const int  minimum)
{
    int temprary = 0;
    if (myArray == nullptr)
        cout << "Массив пуст";

    auto maxNegativeArrayValue = minimum;
    size_t maxNegativeElementIndex = 0;

    for (size_t index = 0; index < size; index++) {
        if (myArray[index] <0 && myArray[index] > maxNegativeArrayValue) {
            maxNegativeArrayValue = myArray[index];
            maxNegativeElementIndex = index;
        }
    }

    if (maxNegativeArrayValue > 0) {
        cout << "Ошибка";
    }
    else {
        temprary = myArray[maxNegativeElementIndex];
        myArray[maxNegativeElementIndex] = myArray[(size - 1) / 2];
        myArray[(size - 1) / 2] = temprary;
    }

    return myArray;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "\nМассив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int  minimum, const int maximum)
{
    random_device rd;

    mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minimum, maximum);

    auto* myArray = new int[size];

    for (size_t index = 0; index < size; index++)
    {
        myArray[index] = uniformIntDistribution(gen);
    }
    return myArray;
}

int* FillUserArray(const size_t size)
{
    auto* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}
