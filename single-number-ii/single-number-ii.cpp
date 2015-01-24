class Solution {
public:
    int singleNumber(int A[], int n) {
        int M = sizeof(int) * 8;  // the number of bits of an integer
        vector<int> bitsCount (M, 0);
        for (int i = 0; i < n; ++i) {
            for (int bit = 0; bit < M; ++bit) {
                bitsCount[bit] += (A[i] >> bit) & 1;
                bitsCount[bit] %= 3;
            }
        }
        int ret = 0;
        // bitsCount[i] % 3 != 0, single number has 1 at i.
        for (int bit = 0; bit < M; ++bit) {
            if (bitsCount[bit] > 0) {
                ret += 1 << bit;
            }
        }
        return ret;
    }
};