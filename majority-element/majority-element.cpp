#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int majorityElement(vector<int> &num) {
    sort(num.begin(), num.end());
    int mid = num.size() / 2;
    return num[mid];
}

int main() {
    

    return 0;
}

