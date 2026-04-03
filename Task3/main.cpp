#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "GroupingManager.h"


int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try
    {
        std::vector<int> vec;
        std::string line;
        int value;

        std::cout << "Введите элементы вектора через пробел:" << std::endl;
        std::cout << "> ";

        /**
         * Читаем вектор (до нажатия Enter).
         * Элементы вводятся через пробел.
         */
        std::getline(std::cin, line);
        std::istringstream iss(line);
        while (iss >> value)
        {
            vec.push_back(value);
        }

        if (vec.empty())
        {
            std::cout << "Вектор пуст. Завершение работы." << std::endl;
            return 0;
        }

        GroupingManager manager(vec);

        // Группировка по последней цифре (задача 21)
        manager.groupByLastDigit();

        std::cout << std::endl;
        std::cout << "Мультиотображение (последняя цифра -> элемент):" << std::endl;
        manager.printGroupedMap();
        std::cout << std::endl;

        // Вычисление сумм групп без первого элемента (задача 23 через задачу 21)
        manager.computeGroupSumsExcludingFirst();

        std::cout << "Суммы групп (без первого элемента), упорядоченные по цифрам:" << std::endl;
        manager.printGroupSums();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
