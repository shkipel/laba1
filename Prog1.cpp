#include <iostream>
#include "Prog1.h"

namespace Prog1 {
    Matrix input(){
        Matrix matrix;
        double* arr;
        try{

            std::cout << "Enter number of lines: ";
            matrix.m = getNum<int>(0);

            std::cout << "Enter number of colums: ";
            int n;
            n = getNum<int>(0);
            matrix.n = n;
            matrix.lines = new Line[matrix.m];
            for(int i = 0; i < matrix.m; i++){
                Line &line = matrix.lines[i];

                std::cout << "Enter elements" << std::endl;
                arr = new double[matrix.n];
                int count{0};
                for(int j = 0; j < n; j++){
                    double r = getNum<double>();
                    std::cout << "fdfd" << std::endl;
                    if(r != 0.0){
                        arr[count] = r;
                        count++;
                    }
                }
                line.a = new double[count];
                line.n = count;
                for(int j = 0; j < count; j++){
                    line.a[j] = arr[j];
                }
                delete[] arr;
            }
        }
        catch(...){
            delete[] arr;
            erase(matrix);
            throw;
        }
        return matrix;
    }

    void output(const char* msg, const Matrix &matrix){
        std::cout << msg << ":\n";
        for(int i = 0; i < matrix.m; i++){
            Line &line = matrix.lines[i];
            for(int j = 0; j < line.n; ++j){
                std::cout << line.a[j] << " ";
            }
//            std::cout << line.n;
            std::cout << std::endl;
        }
    }

    void erase(Matrix &matrix){
        if(matrix.lines != nullptr) {
            for(int i = 0; i < matrix.m; i++){
                delete[] matrix.lines[i].a;
            }
        }
        delete[] matrix.lines;
        matrix.lines = nullptr;
        matrix.m = 0;
    }

    Matrix copy_matrix(const Matrix &matrix){
        Matrix res;
        res.n = matrix.n;
        res.m = matrix.m;
        res.lines = new Line[res.m];
        for(int i = 0; i < res.m; i++){
            Line &line = res.lines[i];
            line.n = matrix.lines[i].n;
            line.a = new double[line.n];
            for(int j = 0; j < line.n; j++){
                line.a[j] = matrix.lines[i].a[j];
            }
        }
        return res;
    }

    int find_i(Line &line){
        if(line.n < 2){ return -1; }
        else{
            for(int i = 1; i < line.n; i++){
                if(line.a[i] > line.a[i-1]) return i;
            }
        }
        return 0;
    }

    int find_j(Line &line){
        if(line.n < 2){ return -1; }
        else{
            for(int i = line.n - 1; i > 0; i--){
                if(line.a[i] < line.a[i - 1]) return i;
            }
        }
        return 0;
    }

    void swap(int i, int j, Line &line){
        if(i == -1) {
            std::cout << "Not enough elements in line" << std::endl;
            return;
        }
        else if(i == 0 || j == line.n - 1  || i == j){
            return;
        }
        else{
            double tmp = line.a[i];
            line.a[i] = line.a[j];
            line.a[j] = tmp;
        }
    }

    Matrix rewrite_matrix(const Matrix &matrix){
        Matrix res = copy_matrix(matrix);
//        output("gg", res);
        for(int k = 0; k < matrix.m; k++){
            int i = find_i(res.lines[k]);
            int j = find_j(res.lines[k]);
            swap(i, j, res.lines[k]);
        }
        return res;
    }
}