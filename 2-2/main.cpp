#include "FilePrint.h"

int main() {

    char* locale = setlocale(LC_ALL, "");
    FilePrinter printer("name.txt");
    printer.printNumbers();

    return 0;
}