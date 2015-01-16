#include <iostream>
#include <vector>
#include "czqvector.h"
#include "math.h"
#include "segment_tree.h"

using namespace std;


int minValIndex(vector<int> &height, int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    return (height[i] < height[j]) ? i : j;
}

int findRangeMinIndex(vector<int> &array, SegmentTree &st, int start, int end, int qstart, int qend, int index) {
    // Now the segment node is a part of the query range
    if (start >= qstart && end <= qend) {
        return st.get(index);
    }
    // segment node is out of range
    if (end < qstart || start > qend) {
        return -1;
    }
    // search left child tree and right child tree
    int middle = (start + end) / 2;
    int left_index = findRangeMinIndex(array, st, start, middle, qstart, qend, 2 * index + 1);
    int right_index = findRangeMinIndex(array, st, middle + 1, end, qstart, qend, 2 * index + 2);
    return minValIndex(array, left_index, right_index);
}

int findRangeMinIndex(vector<int> &array, SegmentTree &st, int size, int qstart, int qend) {
   return findRangeMinIndex(array, st, 0, size - 1, qstart, qend, 0); 
}

int getLargestArea(vector<int> &height, int start, int end, SegmentTree &st) {
    // cout<<"getLargestArea "<<start<<" "<<end<<endl;
    if (start > end) {
        return -1;
    }
    if (start == end) {
        return height[start];
    }
    int min_index = findRangeMinIndex(height, st, height.size(), start, end);
    // cout<<"the min index ["<<start<<","<<end<<"] is "<<min_index<<endl;

    // Return the max of three following cases:
    //  a) The max area of left side of min_index
    //  b) The max area of right side of min_index
    //  c) The max area with height = heigth[min_index]
    
    int max_left = getLargestArea(height, start, min_index - 1, st); 
    int max_right = getLargestArea(height, min_index + 1, end, st);
    int area = (end - start + 1) * height[min_index];
    return max(max(max_left, max_right), area);
}

int largestRectangleArea(vector<int> &height) {
    if (0 == height.size()) {
        return 0;
    }
    // Segment tree save the index of the minimum val in range
    SegmentTree st (height.size());
    st.build_tree(height);
    // cout<<"build segment tree"<<endl;

    return getLargestArea(height, 0, height.size() - 1, st);
}

void test(string inputstr, int result) {
    vector<int> input = build_int_vector(inputstr, ',');
    int output = largestRectangleArea(input);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<output<<" "<<result<<endl;
    }
}

int main() {
    test("2,1,5,6,2,3", 10);
    test("2", 2);
    test("", 0);
    test("1,2,1,2,1,2,1", 7);
    return 0;
}

