#ifndef CZQVECTOR_H
#define CZQVECTOR_H

#include <vector>
#include "czqstring.h"
#include "stdlib.h"

std::vector<int> build_int_vector(std::string s, const char delim) {
    using std::vector;
    using std::string;
    vector<string> elems = split(s, delim);
    vector<int> ret;
    for (int i = 0; i < elems.size(); ++i) {
        ret.push_back(atoi(elems[i].c_str()));
    }
    return ret;
}

template<typename T> bool vector_equal(std::vector<T> input1, std::vector<T> input2) {
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


template <typename T> void print_vector(const std::vector<T> data) {
    std::cout<<"[";
    if (data.size() > 0) {
        std::cout<<data[0];
        for (int i = 1; i < data.size(); ++i) {
            std::cout<<","<<data[i];
        }
    }
    std::cout<<"]";
}


template <typename T> void print_2d_vector_line(const std::vector<std::vector<T> > data) {
    std::cout<<"[";
    if (data.size() > 0) {
        print_vector(data[0]);
        for (int i = 1; i < data.size(); ++i) {
            std::cout<<", ";
            print_vector(data[i]);
        }
    }
    std::cout<<"]";
}

template <typename T> void print_2d_vector(const std::vector<std::vector<T> > data) {
    if (data.size() > 0) {
        for (int i = 0; i < data.size(); ++i) {
            print_vector(data[i]);
            std::cout<<std::endl;
        }
    }
}

#endif
