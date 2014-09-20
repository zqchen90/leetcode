class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int K) {
        // always m <= n
        if (m > n) return findKth(B, n, A, m, K);
        // if A is empty, B[K - 1] is the Kth number
        if (m == 0) return B[K - 1]; 
        if (K == 1) {
            return min(A[0], B[0]);
        }
        int ia = min(K/2, m);
        int ib = K - ia;
        if (A[ia - 1] < B[ib - 1])
            return findKth(A + ia, m - ia, B, n, K- ia);
        else if (A[ia - 1] > B[ib - 1])
            return findKth(A, m , B + ib, n - ib, K- ib);
        else
            return A[ia - 1];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 == 1) {
            return findKth(A, m, B, n, total / 2 + 1);
        } else {
            return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2.0;
        }
    }
};