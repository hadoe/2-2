#include "FilePrint.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

FilePrinter::FilePrinter(const std::string& fname) : filename(fname) {}

void FilePrinter::printNumbers() const {
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
