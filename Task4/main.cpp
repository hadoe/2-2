#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
#include "Point.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try
    {
        std::string name;

        std::cout << "Введите имя файла: " << std::flush;
        std::cin >> name;

        std::ifstream fin(name);
        if (!fin.is_open())
        {
            std::cerr << "Ошибка: не удалось открыть файл " << name << " для чтения." << std::endl;
            return 1;
        }

        // Считываем всё содержимое файла в строковый буфер
        std::ostringstream buffer;
        buffer << fin.rdbuf();
        fin.close();

        // Создаём поток для чтения из буфера
        std::istringstream fin_buf(buffer.str());

        std::ofstream fout(name, std::ios::trunc);
        if (!fout.is_open())
        {
            std::cerr << "Ошибка: не удалось открыть файл " << name << " для записи." << std::endl;
            return 1;
        }

        std::istream_iterator<point> it_in(fin_buf);
        std::istream_iterator<point> it_in_end;
        std::ostream_iterator<point> ptout_iterator(fout, "\n");

        std::replace_copy_if(
            it_in,
            it_in_end,
            ptout_iterator,
            std::mem_fn(&point::is_positive),
            point(0, 0, "A")
        );

        fout.close();

        std::cout << std::endl;

        std::ifstream fout_read(name);
        if (fout_read.is_open())
        {
            std::copy(std::istreambuf_iterator<char>(fout_read),
                      std::istreambuf_iterator<char>(),
                      std::ostream_iterator<char>(std::cout));
            fout_read.close();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "Нажмите Enter для выхода...";
    std::cin.ignore(32767, '\n');
    std::cin.get();

    return 0;
}
