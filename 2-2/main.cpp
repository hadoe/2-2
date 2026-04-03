#include "FilePrint.h"
#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::string filename;
    std::cout << "Введите имя файла: ";
    std::getline(std::cin, filename);

    FilePrinter printer(filename);
    printer.printNumbers();

    return 0;
}