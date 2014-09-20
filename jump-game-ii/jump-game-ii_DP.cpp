/*
A O(n) answer
will get AC
*/

class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1) {
            return 0;
        }
        int *D = new int[n];
        int i = 0, j = 0;
        for (i = 0; i < n; ++i){
            D[i] = 0;
        }
        queue<int> waiting;
        for (i = 0; i < n; ++i){
            if (A[i] > 0) {
                waiting.push(i);
                break;
            }
        }
        int cur;
        while (waiting.size() > 0) {
            cur = waiting.front();
            waiting.pop();
            if (A[cur] + cur >= n - 1) {
                return D[cur] + 1;
            }
            for (j = A[cur]; j > 0; --j) {
                if (0 == D[cur + j] || D[cur + j] > D[cur] + 1) {
                    D[cur + j] = D[cur] + 1;
                    waiting.push(j + cur);
                }
            }
        }
        return D[n - 1];
    }
};