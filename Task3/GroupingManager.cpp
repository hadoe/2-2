#include "GroupingManager.h"

#include <numeric>
#include <iostream>
#include <algorithm>

/**
 * @brief Получить последнюю цифру числа.
 *
 * @param value Число.
 * @return Последняя цифра (0-9).
 */
int GroupingManager::getLastDigit(int value) const
{
    return std::abs(value) % 10;
}

/**
 * @brief Конструктор с инициализацией вектора.
 *
 * @param vec Вектор элементов.
 */
GroupingManager::GroupingManager(const std::vector<int>& vec)
    : m_vector(vec)
{
}

/**
 * @brief Установить вектор.
 *
 * @param vec Новый вектор элементов.
 */
void GroupingManager::setVector(const std::vector<int>& vec)
{
    m_vector = vec;
}

/**
 * @brief Получить исходный вектор.
 *
 * @return Константная ссылка на вектор.
 */
const std::vector<int>& GroupingManager::getVector() const
{
    return m_vector;
}

/**
 * @brief Получить мультиотображение группировки.
 *
 * @return Константная ссылка на multimap.
 */
const std::multimap<int, int>& GroupingManager::getGroupedMap() const
{
    return m_groupedMap;
}

/**
 * @brief Получить отображение сумм групп.
 *
 * @return Константная ссылка на map (цифра -> сумма без первого элемента).
 */
const std::map<int, int>& GroupingManager::getGroupSums() const
{
    return m_groupSums;
}

/**
 * @brief Выполнить группировку элементов вектора по последней цифре.
 *
 * Перебирает элементы вектора с использованием итераторов и добавляет
 * их в multimap, где ключом является последняя цифра элемента.
 * Порядок элементов внутри каждой группы сохраняется исходным.
 */
void GroupingManager::groupByLastDigit()
{
    m_groupedMap.clear();

    // Перебор элементов с использованием итераторов (цикл с параметром-итератором)
    for (auto it = m_vector.begin(); it != m_vector.end(); ++it)
    {
        int digit = getLastDigit(*it);
        m_groupedMap.insert(std::make_pair(digit, *it));
    }
}

/**
 * @brief Вычислить суммы элементов в каждой группе, исключая первый элемент.
 *
 * Для каждой группы (элементы с одинаковой последней цифрой) вычисляется
 * сумма всех элементов, кроме первого. Если группа состоит из одного
 * элемента, сумма равна 0. Использует std::accumulate.
 */
void GroupingManager::computeGroupSumsExcludingFirst()
{
    m_groupSums.clear();

    // Перебираем уникальные ключи (цифры) в порядке возрастания
    for (auto it = m_groupedMap.begin(); it != m_groupedMap.end(); )
    {
        int digit = it->first;

        // Получаем диапазон элементов для данной цифры
        auto range = m_groupedMap.equal_range(digit);
        auto rangeBegin = range.first;
        auto rangeEnd = range.second;

        // Считаем количество элементов в группе
        int count = 0;
        for (auto elemIt = rangeBegin; elemIt != rangeEnd; ++elemIt)
        {
            ++count;
        }

        if (count <= 1)
        {
            // Группа из одного элемента — сумма равна 0
            m_groupSums[digit] = 0;
        }
        else
        {
            // Суммируем все элементы кроме первого, используя std::accumulate.
            // Элементы multimap — это pair<const int, int>, поэтому используем
            // лямбду для извлечения значения (second) из пары.
            auto sumStart = std::next(rangeBegin);
            int sum = std::accumulate(sumStart, rangeEnd, 0,
                [](int acc, const std::pair<const int, int>& p)
                {
                    return acc + p.second;
                });
            m_groupSums[digit] = sum;
        }

        // Переходим к следующей группе
        it = rangeEnd;
    }
}

/**
 * @brief Вывести мультиотображение группировки в поток вывода.
 *
 * Для каждого элемента отображения выводится ключ и связанное значение.
 */
void GroupingManager::printGroupedMap() const
{
    // Перебор элементов с использованием итераторов
    for (auto it = m_groupedMap.begin(); it != m_groupedMap.end(); ++it)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

/**
 * @brief Вывести суммы групп, упорядоченные по возрастанию цифр.
 */
void GroupingManager::printGroupSums() const
{
    // std::map уже отсортирован по ключам (цифрам)
    for (auto it = m_groupSums.begin(); it != m_groupSums.end(); ++it)
    {
        std::cout << "Цифра: " << it->first << ", Сумма (без первого): " << it->second << std::endl;
    }
}
