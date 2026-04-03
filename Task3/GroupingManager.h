#ifndef GROUPING_MANAGER_H
#define GROUPING_MANAGER_H

#include <vector>
#include <map>

/**
 * @brief Класс для группировки элементов вектора по последней цифре и вычисления сумм групп.
 */
class GroupingManager
{
private:
    std::vector<int> m_vector;                          
    std::multimap<int, int> m_groupedMap;               
    std::map<int, int> m_groupSums;                     

    /**
     * @brief Получить последнюю цифру числа.
     *
     * @param value Число.
     * @return Последняя цифра (0-9).
     */
    int getLastDigit(int value) const;

public:
    /**
     * @brief Конструктор по умолчанию.
     *
     * Создаёт пустой менеджер.
     */
    GroupingManager() = default;

    /**
     * @brief Конструктор с инициализацией вектора.
     *
     * @param vec Вектор элементов.
     */
    explicit GroupingManager(const std::vector<int>& vec);

    /**
     * @brief Установить вектор.
     *
     * @param vec Новый вектор элементов.
     */
    void setVector(const std::vector<int>& vec);

    /**
     * @brief Получить исходный вектор.
     *
     * @return Константная ссылка на вектор.
     */
    const std::vector<int>& getVector() const;

    /**
     * @brief Получить мультиотображение группировки.
     *
     * @return Константная ссылка на multimap.
     */
    const std::multimap<int, int>& getGroupedMap() const;

    /**
     * @brief Получить отображение сумм групп.
     *
     * @return Константная ссылка на map (цифра -> сумма без первого элемента).
     */
    const std::map<int, int>& getGroupSums() const;

    /**
     * @brief Выполнить группировку элементов вектора по последней цифре.
     *
     * Элементы перебираются итераторами (цикл с параметром-итератором).
     * В multimap элементы добавляются в порядке обхода, сохраняя
     * исходный порядок внутри каждой группы (как в задаче 21).
     */
    void groupByLastDigit();

    /**
     * @brief Вычислить суммы элементов в каждой группе, исключая первый элемент.
     *
     * Если группа состоит из одного элемента, сумма равна 0.
     * Использует алгоритм std::accumulate (как в задаче 23).
     */
    void computeGroupSumsExcludingFirst();

    /**
     * @brief Вывести мультиотображение группировки в поток вывода.
     *
     * Для каждого элемента отображения выводится ключ и связанное значение.
     */
    void printGroupedMap() const;

    /**
     * @brief Вывести суммы групп, упорядоченные по возрастанию цифр.
     */
    void printGroupSums() const;
};

#endif // GROUPING_MANAGER_H
