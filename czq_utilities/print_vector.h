#ifndef PRINT_VECTOR_H
#define PRINT_VECTOR_H

#include <vector>

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
