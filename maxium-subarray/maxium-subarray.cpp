#include <iostream>

using namespace std;

int maxSubArray(int A[], int n) {
    if (0 == n)
        return 0;
    if (1 == n)
        return A[0];

    int *sum = new int[n];
    sum[0] = A[0];
    int max_sum = sum[0];
    for (int i = 1; i < n; ++i) {
        if (sum[i - 1] > 0) {
            sum[i] = sum[i - 1] + A[i];
        } else {
            sum[i] = A[i];
        }
        max_sum = sum[i] > max_sum ? sum[i] : max_sum;
    }
    return max_sum;
}

int main() {
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(A) / sizeof(int);
    cout<<maxSubArray(A, n)<<endl;

    return 0;
}

