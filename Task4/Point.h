#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

/**
 * @brief Структура, представляющая точку с координатами x, y и строкой s.
 */
struct point
{
    int x;          ///< Координата x
    int y;          ///< Координата y
    std::string s;  ///< Строковое представление

    /**
     * @brief Конструктор по умолчанию.
     */
    point() : x(0), y(0), s("") {}

    /**
     * @brief Конструктор с параметрами.
     *
     * @param x Координата x.
     * @param y Координата y.
     * @param s Строковое представление.
     */
    point(const int x, const int y, const std::string& s);

    /**
     * @brief Оператор сравнения: A < B.
     *
     * A < B, если A.x < B.x или (A.x == B.x и A.y < B.y).
     *
     * @param other Точка для сравнения.
     * @return true, если текущая точка меньше other.
     */
    bool operator<(const point& other) const;

    /**
     * @brief Оператор сравнения: A > B.
     *
     * @param other Точка для сравнения.
     * @return true, если текущая точка больше other.
     */
    bool operator>(const point& other) const;

    /**
     * @brief Оператор ввода из потока.
     *
     * Последовательно считывает x, y и s из входного потока is.
     *
     * @param is Входной поток.
     * @param p Точка для заполнения.
     * @return Ссылка на входной поток.
     */
    friend std::istream& operator>>(std::istream& is, point& p);

    /**
     * @brief Оператор вывода в поток.
     *
     * Записывает все члены структуры p в выходной поток os.
     * Между членами вставляется пробел.
     *
     * @param os Выходной поток.
     * @param p Точка для вывода.
     * @return Ссылка на выходной поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const point& p);

    /**
     * @brief Оператор преобразования в строку.
     *
     * Возвращает строку с текстовыми представлениями членов x, y, s,
     * разделёнными пробелами.
     *
     * @return Строковое представление точки.
     */
    operator std::string() const;

    /**
     * @brief Проверка, являются ли x и y положительными.
     *
     * @return true, если x > 0 и y > 0.
     */
    bool is_positive() const;
};

#endif // POINT_H
