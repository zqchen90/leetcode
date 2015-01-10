class Solution {
public:
    void sortColors(int A[], int n) {
        int color_cnt[] = {0,0,0};
        for (int i = 0; i < n; ++i) {
            color_cnt[A[i]]++;
        }
        int i = 0;
        for (int color = 0; color <=2; ++color) {
            for (int j = 0; j < color_cnt[color]; ++j) {
                A[i + j] = color;
            }
            i += color_cnt[color];
        }
    }
};