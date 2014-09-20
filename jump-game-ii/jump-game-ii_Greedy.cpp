/*
A O(n^2) answer
will get TLE
*/

class Solution {
public:
    int jump(int A[], int n) {
        int *D = new int[n];
        int i = 0, j = 0;
        for (i = 0; i < n; ++i){
            D[i] = 0;
        }
        stack<int> waiting;
        for (i = 0; i < n; ++i){
            if (A[i] > 0) {
                waiting.push(i);
                break;
            }
        }
        int cur;
        while (waiting.size() > 0) {
            cur = waiting.top();
            waiting.pop();
            if (A[cur] + cur >= n - 1) {
                return A[cur] + 1;
            }
            for (j = A[cur]; j > 0; --j) {
                if (0 == D[cur + j] || D[cur + j] > A[cur] + 1) {
                    D[cur + j] = A[cur] + 1;
                    waiting.push(j + cur);
                }
            }
        }
        return D[n - 1];
    }
};

