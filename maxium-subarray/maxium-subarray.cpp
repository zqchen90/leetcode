#include <iostream>

using namespace std;

int maxSubArray(int A[], int n) {
    if (0 == n)
        return 0;
    if (1 == n)
        return A[0];

    int sum = A[0];
    int max_sum = sum;
    for (int i = 1; i < n; ++i) {
        if (sum > 0) {
            sum += A[i];
        } else {
            sum = A[i];
        }
        max_sum = sum > max_sum ? sum : max_sum;
    }
    return max_sum;
}

int main() {
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(A) / sizeof(int);
    cout<<maxSubArray(A, n)<<endl;

    return 0;
}

