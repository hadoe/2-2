#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>


/**
 * @brief Класс для вывода целых чисел из текстового файла. Использует итераторы istream_iterator, ostream_iterator и алгоритм copy.
 */
class FilePrinter {
private:
    std::string filename;

public:
    /**
     * @brief Конструктор, принимающий имя файла.
     * @param fname Имя файла для чтения.
     */
    FilePrinter(const std::string& fname) : filename(fname) {}

    /**
     * @brief Выводит все целые числа из файла в том же порядке, разделяя пробелами.
     */
    void printNumbers() const {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
            return;
        }

        std::istream_iterator<int> input_it(file);
        std::istream_iterator<int> end_it;
        std::ostream_iterator<int> output_it(std::cout, " ");
        std::copy(input_it, end_it, output_it);
    }
};

#endif // FILEPRINTER_H