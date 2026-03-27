
#include <iostream>
#include <list>
#include "ListManager.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try
    {
        // Создаём списки L1 и L2
        // L1 имеет нечётное количество элементов (5 элементов)
        std::list<int> list1 = { 1, 2, 3, 4, 5 };
        std::list<int> list2 = { 10, 20, 30 };

        // Создаём объект ListManager
        ListManager<int> manager(list1, list2);

        std::cout << "=== Задание 24: Перемещение среднего элемента ===" << std::endl;
        std::cout << std::endl;

        std::cout << "До перемещения:" << std::endl;
        manager.printLists();
        std::cout << std::endl;

        // Перемещаем средний элемент из L1 в конец L2
        // Средний элемент списка {1, 2, 3, 4, 5} - это 3 (индекс 2)
        manager.moveMiddleElementToList2End();

        std::cout << "После перемещения среднего элемента из L1 в конец L2:" << std::endl;
        manager.printLists();
        std::cout << std::endl;

        // Дополнительный тест с другим списком
        std::cout << "=== Дополнительный тест ===" << std::endl;
        std::list<int> list3 = { 100, 200, 300, 400, 500, 600, 700 };
        std::list<int> list4 = { -1, -2 };

        ListManager<int> manager2(list3, list4);

        std::cout << "До перемещения:" << std::endl;
        manager2.printLists();
        std::cout << std::endl;

        manager2.moveMiddleElementToList2End();

        std::cout << "После перемещения среднего элемента из L1 в конец L2:" << std::endl;
        manager2.printLists();
        std::cout << std::endl;

        // Тест с исключением (чётное количество элементов)
        std::cout << "=== Тест обработки исключения ===" << std::endl;
        std::list<int> evenList = { 1, 2, 3, 4 };
        std::list<int> anotherList = { 5, 6 };

        ListManager<int> manager3(evenList, anotherList);

        try
        {
            manager3.moveMiddleElementToList2End();
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Исключение: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "Программа завершена успешно." << std::endl;

    return 0;
}
