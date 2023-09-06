#ifndef OOPPROG1_PROG1_H
#define OOPPROG1_PROG1_H

#include <iostream>
#include <string>
#include <limits>
#include <cstring>

namespace Prog1 {
    // структура для задания строки матрицы
    struct Line {
        int n = 0; // количество элементов в строке матрицы
        double *a = nullptr; // массив элементов
    };

    // структура для задания матрицы
    struct Matrix {
        int n = 0;
        int m = 0; // количество строк
        Line *lines = nullptr; // массив строк
    };

    template<class T>
    T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()){
        T a;
        while(true){
            std::cin >> a;
            if(std::cin.eof()){ throw std::runtime_error("EOF"); }
            else if(std::cin.bad()) { throw std::runtime_error(strerror(errno)); }
            else if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Wrong input" << std::endl;
            }
            else if(a >= min && a <= max){
                return a;
            }
        }
    }

    //prototypes
    Matrix input();
    void output(const char* msg, const Matrix &matrix);
    void erase(Matrix &matrix);
    Matrix rewrite_matrix(const Matrix &matrix);
}

#endif //OOPPROG1_PROG1_H
