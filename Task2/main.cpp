
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include "ListManager.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try
    {
        std::list<int> list1, list2;
        std::string line;
        int value;

        // Читаем первый список (до нажатия Enter)
        std::getline(std::cin, line);
        std::istringstream iss1(line);
        while (iss1 >> value)
        {
            list1.push_back(value);
        }

        // Читаем второй список (до нажатия Enter)
        std::getline(std::cin, line);
        std::istringstream iss2(line);
        while (iss2 >> value)
        {
            list2.push_back(value);
        }

        ListManager<int> manager(list1, list2);

        std::cout << "До перемещения:" << std::endl;
        manager.printLists();
        std::cout << std::endl;

        manager.moveMiddleElementToList2End();

        std::cout << "После перемещения среднего элемента из L1 в конец L2:" << std::endl;
        manager.printLists();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
