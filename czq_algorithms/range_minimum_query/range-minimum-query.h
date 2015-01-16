#ifndef RANGE_MINIMUM_QUERY_H
#define RANGE_MINIMUM_QUERY_H

#include "segment_tree.h"

template <class T>
class RangeMinimumQuery {
public:
    RangeMinimumQuery(std::vector<T> &Data);
    void initialize();
    int get_range_minimum_index(int left, int right);
                                  
private:
    int minValIndex(int i, int j);
    int find_range_minimum_index(int start, int end, int qstart, int qend, int index);

    SegmentTree<T> st;
    std::vector<T> data;
};

template <class T> RangeMinimumQuery<T>::RangeMinimumQuery(
    std::vector<T> &Data) : st(SegmentTree<T>(Data.size())), data(std::vector<T>(Data.begin(), Data.end())) {
    // using std::cout;
    // using std::endl;
    // cout<<"Query construct, data: "<<data.size()<<endl;
}

template <class T> void RangeMinimumQuery<T>::initialize() {
    st.build_tree(data);
}

template <class T> int RangeMinimumQuery<T>::get_range_minimum_index(int left, int right) {
    if (left < 0 || right > data.size() || left > right) {
        return -1;
    }
    if (left == right) {
        return left;
    }
    return find_range_minimum_index(0, data.size() - 1, left, right, 0);
}

template <class T> int RangeMinimumQuery<T>::minValIndex(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    return (data[i] < data[j]) ? i : j;
}

template <class T> int RangeMinimumQuery<T>::find_range_minimum_index(
                                                int start,
                                                int end, 
                                                int qstart, 
                                                int qend, 
                                                int index) {
    // Now the segment node is a part of the query range
    if (start >= qstart && end <= qend) {
        return st.get_index(index);
    }
    // segment node is out of range
    if (end < qstart || start > qend) {
        return -1;
    }
    // search left child tree and right child tree
    int middle = (start + end) / 2;
    int left_index = find_range_minimum_index(start, middle, 
                                                qstart, qend,
                                                2 * index + 1);
    int right_index = find_range_minimum_index(middle + 1, end,
                                                qstart, qend,
                                                2 * index + 2);
    return minValIndex(left_index, right_index);
}

#endif

