#include <iostream>

using namespace std;

int rotated_bisearch(int A[], int start, int end, int target) {
	if (start > end)
		return -1;
	if (start == end) {
		return A[start] == target ? start : -1;
	}
	if (A[start] == target)
		return start;
	if (A[end] == target)
		return end;

	int middle = (start + end) / 2;
	if (A[middle] == target)
		return middle;

	if (A[middle] > A[start]) {
		if (A[middle] > target) {
			if (A[start] < target) {
				return rotated_bisearch(A, start, middle - 1, target);
			} else {
				return rotated_bisearch(A, middle + 1, end, target);
			}
		}
		else {  // A[middle] < target
			return rotated_bisearch(A, middle + 1, end, target);
		}
	} else {
		if (A[middle] > target) {
			return rotated_bisearch(A, start, middle - 1, target);
		}
		else {  // A[middle] < target
			if (A[end] < target) {
				return rotated_bisearch(A, start, middle - 1, target);
			} else {
				return rotated_bisearch(A, middle + 1, end, target);
			}
		}
	}

}

int search(int A[], int n, int target) {
    return rotated_bisearch(A, 0, n - 1, target);
}

int main() {
	int A[] = {4,5,6,7,0,1,2};
	int target = 0;
	int index = search(A, sizeof(A) / sizeof(A[0]), target);

	if (index >= 0) {
		cout<<target<<"\t"<<A[index]<<endl;
	}
	else {
		cout<<"-1"<<endl;
	}
	return 0;
}