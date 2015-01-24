class Solution {
public:
int trap(int A[], int n) {
    int sum = 0;
    int max = 0;
    int max_index = 0;

    // find max index
    for (int i = 0; i < n; ++i) {
        if (A[i] > max) {
            max = A[i];
            max_index = i;
        }
    }

    // from 0 to max_index
    int prev = 0;
    for (int i = 0; i < max_index; ++i) {
        if (A[i] > prev) {
            sum += (A[i] - prev) * (max_index - i);
            prev = A[i];
        }
        sum -= A[i];
    }

    // from end to max_index
    prev = 0;
    for (int i = n - 1; i > max_index; --i) {
        if (A[i] > prev) {
            sum += (A[i] - prev) * (i - max_index);
            prev = A[i];
        }
        sum -= A[i];
    }

    return sum;
}
};