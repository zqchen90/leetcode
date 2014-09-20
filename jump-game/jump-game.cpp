class Solution {
public:
    bool canJump(int A[], int n) {
        int reach = 0;
        for (int i = 0; i <= reach && reach < n; ++i)
            reach = max(reach, i + A[i]);
        return reach >= n - 1;
    }
};