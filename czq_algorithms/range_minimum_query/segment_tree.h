#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

template <class T> class SegmentTree {
public:
    template <class T> SegmentTree(int data_size) {
        height = (int)(ceil(log2(data_size)));
        size = 2 * (int)pow(2, height) - 1;
        st = new int[size];
    }

    template <class T> ~SegmentTree() {
        delete[] st;
        st = NULL;
    }

    template <class T> void build_tree(std::vector<T> &data) {
        build_tree_til(data, 0, data.size() - 1, 0);
    }

    template <class T> 
    void build_tree(T* data, int data_size) {
        std::vector<T> data_vector (data, data + data_size);
        build_tree_til(data_vector, 0, data_size - 1, 0);
    }

    template <class T> 
    T get_index(int index) {
        return st[index];
    }
                                  
private:
    template <class T> 
    int build_tree_til(std::vector<T> &data, int start, int end, int index) {
        if (start == end) {
            st[index] = start;
            return start;
        }
        int middle = (start + end) / 2;
        int left_index = build_tree_til(data, start, middle, 2 * index + 1);
        int right_index = build_tree_til(data, middle + 1, end, 2 * index + 2);
        if (data[left_index] < data[right_index]) {
            st[index] = left_index;
        } else {
            st[index] = right_index;
        }
        return st[index];
    }

    int *st;
    int height;
    int size;
};

#endif
