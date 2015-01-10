class Solution {
public:
    void sortColors(int A[], int n) {
		int red_cnt = 0;
		int blue_cnt = n - 1;
        for (int i = 0; i <= blue_cnt;) {
            if (A[i] == 0) {
				swap(A[red_cnt], A[i]);
				red_cnt++;
				i++; // i must larger than red_cnt
			} else if (A[i] == 2) {
				swap(A[blue_cnt], A[i]);
				blue_cnt--;
			} else {
				i++;
			}
        }
    }
};