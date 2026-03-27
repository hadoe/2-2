/**
 * @file ListManager.h
 * @brief Заголовочный файл класса для управления списками.
 */

#ifndef LIST_MANAGER_H
#define LIST_MANAGER_H

#include <list>
#include <stdexcept>
#include <iostream>

/**
 * @class ListManager
 * @brief Класс для работы с двумя списками и перемещения элементов между ними.
 * 
 * Класс инкапсулирует два списка типа T и предоставляет методы
 * для манипуляции их элементами, включая перемещение среднего элемента.
 * 
 * @tparam T Тип элементов, хранящихся в списках.
 */
template <typename T>
class ListManager
{
private:
    std::list<T> m_list1;  ///< Первый список (L1)
    std::list<T> m_list2;  ///< Второй список (L2)

public:
    /**
     * @brief Конструктор по умолчанию.
     * 
     * Создаёт пустые списки L1 и L2.
     */
    ListManager() = default;

    /**
     * @brief Конструктор с инициализацией списков.
     * 
     * @param list1 Начальное значение для списка L1.
     * @param list2 Начальное значение для списка L2.
     */
    ListManager(const std::list<T>& list1, const std::list<T>& list2);

    /**
     * @brief Установить список L1.
     * 
     * @param list Новый список для L1.
     */
    void setList1(const std::list<T>& list);

    /**
     * @brief Установить список L2.
     * 
     * @param list Новый список для L2.
     */
    void setList2(const std::list<T>& list);

    /**
     * @brief Получить список L1.
     * 
     * @return Константная ссылка на список L1.
     */
    const std::list<T>& getList1() const;

    /**
     * @brief Получить список L2.
     * 
     * @return Константная ссылка на список L2.
     */
    const std::list<T>& getList2() const;

    /**
     * @brief Проверить, имеет ли список L1 нечётное количество элементов.
     * 
     * @return true, если количество элементов нечётное, иначе false.
     */
    bool isList1OddSize() const;

    /**
     * @brief Переместить средний элемент списка L1 в конец списка L2.
     * 
     * Использует один вызов функции-члена splice для перемещения
     * среднего элемента из L1 в конец L2.
     * 
     * @throw std::invalid_argument Если размер L1 чётный.
     * 
     * @note Средний элемент определяется как элемент с индексом size/2
     *       (целочисленное деление).
     */
    void moveMiddleElementToList2End();

    /**
     * @brief Вывести содержимое списков в поток вывода.
     * 
     * @tparam U Тип элементов (должен поддерживать оператор вывода).
     */
    void printLists() const;
};

/**
 * @brief Конструктор с инициализацией списков.
 * 
 * @tparam T Тип элементов в списках.
 * @param list1 Начальное значение для списка L1.
 * @param list2 Начальное значение для списка L2.
 */
template <typename T>
ListManager<T>::ListManager(const std::list<T>& list1, const std::list<T>& list2)
    : m_list1(list1), m_list2(list2)
{
}

/**
 * @brief Установить список L1.
 * 
 * @tparam T Тип элементов в списках.
 * @param list Новый список для L1.
 */
template <typename T>
void ListManager<T>::setList1(const std::list<T>& list)
{
    m_list1 = list;
}

/**
 * @brief Установить список L2.
 * 
 * @tparam T Тип элементов в списках.
 * @param list Новый список для L2.
 */
template <typename T>
void ListManager<T>::setList2(const std::list<T>& list)
{
    m_list2 = list;
}

/**
 * @brief Получить список L1.
 * 
 * @tparam T Тип элементов в списках.
 * @return Константная ссылка на список L1.
 */
template <typename T>
const std::list<T>& ListManager<T>::getList1() const
{
    return m_list1;
}

/**
 * @brief Получить список L2.
 * 
 * @tparam T Тип элементов в списках.
 * @return Константная ссылка на список L2.
 */
template <typename T>
const std::list<T>& ListManager<T>::getList2() const
{
    return m_list2;
}

/**
 * @brief Проверить, имеет ли список L1 нечётное количество элементов.
 * 
 * @tparam T Тип элементов в списках.
 * @return true, если количество элементов нечётное, иначе false.
 */
template <typename T>
bool ListManager<T>::isList1OddSize() const
{
    return m_list1.size() % 2 != 0;
}

/**
 * @brief Реализация метода перемещения среднего элемента.
 * 
 * Использует один вызов splice для перемещения среднего элемента
 * из L1 в конец L2.
 * 
 * @tparam T Тип элементов в списках.
 * @throw std::invalid_argument Если размер L1 чётный.
 */
template <typename T>
void ListManager<T>::moveMiddleElementToList2End()
{
    if (!isList1OddSize())
    {
        throw std::invalid_argument("Список L1 должен иметь нечётное количество элементов.");
    }

    // Находим итератор на средний элемент
    auto middleIt = m_list1.begin();
    std::advance(middleIt, m_list1.size() / 2);

    // Перемещаем средний элемент в конец L2 с помощью одного вызова splice
    // splice перемещает элемент, а не копирует его
    m_list2.splice(m_list2.end(), m_list1, middleIt);
}

/**
 * @brief Вывод содержимого обоих списков.
 * 
 * @tparam T Тип элементов (должен поддерживать оператор вывода).
 */
template <typename T>
void ListManager<T>::printLists() const
{
    std::cout << "L1: ";
    for (const auto& elem : m_list1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "L2: ";
    for (const auto& elem : m_list2)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif // LIST_MANAGER_H
