#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <string>


class FilePrinter {
private:
    std::string filename;

public:
    /**
     * @brief конструктор.
     * @param fname имя читаемого файла.
     */
    FilePrinter(const std::string& fname);

    /**
     * @brief Выводит числа в соответствии с заданием.
     */
    void printNumbers() const;
};

#endif // FILEPRINTER_H