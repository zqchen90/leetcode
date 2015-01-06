#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int> &num) {
    unordered_map<int, int> num_count;
    vector<int>::iterator it;
    // Add {num:0} to the map
    for (it = num.begin(); it != num.end(); ++it) {
        num_count[*it] = 0;
    }
    int threshold = num.size() / 2;
    int max_count = 0;
    int max_count_num = 0;
    for (it = num.begin(); it != num.end(); ++it) {
        num_count[*it] += 1;
        int count = num_count[*it];
        if (count > max_count) {
            max_count = count;
            max_count_num = *it;
        }
        if (count > threshold) {
            return *it;
        }
    }
    return max_count_num;
}

int main() {
    

    return 0;
}

