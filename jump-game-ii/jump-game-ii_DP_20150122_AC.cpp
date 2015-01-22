#include <iostream>
#include "czqvector.h"

using namespace std;

int jump(vector<int> A, int n) {
   if (1 >= n) {
        return 0;
    }
    vector<int> D (n, 0);
    int i = 0, j = 0;
    for (i = 0; i < n - 1; ++i){
        if (0 == A[i]) {
            D[i] = -1;
        }
    }
    
    for (i = n - 2; i >= 0; --i){
        if (0 > D[i]) {
            continue;
        }
        if (i + A[i] >= n - 1) {
            D[i] = 1;
            continue;
        }
        j = i + A[i];
        int min = D[j];
        for (; j > i; --j){
            if (0 > D[j]) {
                continue;
            }
            if (1 == D[j]) {
                min = 1;
                break;
            }
            if (min < 0) {
                min = D[j];
            } else {
                if (min > D[j]) {
                    min = D[j];
                }
            }
        }
        if (min < 0) {
            D[i] = -1;
        } else {
            D[i] = 1 + min;
        }
        cout<<"i = "<<i<<" A[i] = "<<A[i]<<endl;
        print_vector(D);
        cout<<endl;
    }
    return D[0];
}

void test(string inputstr, int result) {
	vector<int> input = build_int_vector(inputstr, ',');
    cout<<"Input: "<<endl;
    print_vector(input);
    cout<<endl;
    int output =  jump(input, input.size());
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<result<<endl;
    }
}

int main() {
    test("5,9,3,2,1,0,2,3,3,1,0,0", 3);

    return 0;
}

