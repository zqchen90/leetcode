#include <iostream>

template<typename T> void czqassert(T output, T result) {
    if (output == result) {
        std::cout<<"Success"<<endl;
    } else {
        std::cout<<"Fail  output["<<output<<"] expect["<<result<<"]"<<endl;
    }
}
