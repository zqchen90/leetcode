class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // move A[0 - m-1] to A[n - n+m-1]
        int i;
        for (i = m-1; i >= 0; --i) {
            A[i + n] = A[i];
        }
        // merge
        i = n;
        int j = 0;
        int cur = 0;
        while (i < n + m && j < n) {
            if (A[i] < B[j]) {
                A[cur++] = A[i++];
            } else {
                A[cur++] = B[j++];
            }
        }
        // merge what left
        while (i < n+m) {
            A[cur++] = A[i++];
        }
        while (j < n) {
            A[cur++] = B[j++];
        }
    }
};