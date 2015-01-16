#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

class SegmentTree {
public:
    SegmentTree(int array_size) {
        height = (int)(ceil(log2(array_size)));
        size = 2 * (int)pow(2, height) - 1;
        st = new int[size];
    }

    ~SegmentTree() {
        delete[] st;
        st = NULL;
    }

    void build_tree(std::vector<int> &array) {
        build_tree_til(array, 0, array.size() - 1, 0);
        // cout<<"segment tree, size: "<<size<<" height: "<<height<<endl;
    }

    int get(int index) {
        return st[index];
    }
                                  
private:
    int build_tree_til(std::vector<int> &array, int start, int end, int index) {
        if (start == end) {
            st[index] = start;
            return start;
        }
        int middle = (start + end) / 2;
        int left_index = build_tree_til(array, start, middle, 2 * index + 1);
        int right_index = build_tree_til(array, middle + 1, end, 2 * index + 2);
        if (array[left_index] < array[right_index]) {
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
