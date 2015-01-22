class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int count = 0;
        bool zeroFlag = false;  // if there is any element reducing to zero in this round, if false, find the missing one
        while (true) {
            zeroFlag = false;
            for (int i = 0; i < n; ++i) {
                if (A[i] > 0) {
                    if (A[i] == 1) {
                        zeroFlag = true;
                    }
                    A[i] -= 1;
                } 
            }
            count += 1;
            if (!zeroFlag) {  // find the missing positive
                break;
            }
        }
        return count;
    }
};