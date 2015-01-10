#ifndef CHECK_VECTOR_H
#define CHECK_VECTOR_H

#include <vector>

template<typename T> bool check_vector(std::vector<T> input1, std::vector<T> input2) {
    if (input1.size() != input2.size()) {
        return false;
    }
    for (int i = 0; i < input1.size(); ++i) {
        if (input1[i] != input2[i]) {
            return false;
        }
    }
    return true;
}

#endif
