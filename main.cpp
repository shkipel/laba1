#include <iostream>
#include "Prog1.h"

using namespace Prog1;

// основная функция
int main() {
    Matrix matrix;
//    Matrix res;
    try{
        matrix = input();
        output("First Matrix:", matrix);
        Matrix res = rewrite_matrix(matrix);
        output("Changed Matrix:", res);
        erase(matrix);
        erase(res);
    }
    catch(const std::bad_alloc &ba){
        std::cerr << "No memory" << std::endl;
        erase(matrix);
        return 1;
    }

    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        erase(matrix);
        return 1;
    }
    return 0;

}