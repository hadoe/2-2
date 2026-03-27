#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <string>

class FilePrinter {
private:
    std::string filename;

public:
    /**
     * @brief конструктор класса.
     * @param fname имя файла.
     */
    FilePrinter(const std::string& fname);

    /**
     * @brief выводит числа в соответствии с заданием.
     */
    void printNumbers() const;
};

#endif // FILEPRINTER_H