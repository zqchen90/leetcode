#include <iostream>
#include <assert.h>

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/


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

	if (A[middle] == A[start]) {
		int index_front = rotated_bisearch(A, start, middle - 1, target);
		if (index_front >= 0)
			return index_front;
		int index_end = rotated_bisearch(A, middle + 1, end, target);
		if (index_end >= 0)
			return index_end;
		return -1;
	}


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

bool search(int A[], int n, int target) {
    return rotated_bisearch(A, 0, n - 1, target) >= 0 ? true : false;
}

bool simple_search(int A[], int n, int target) {
	for (int i = 0; i < n; ++i)
		if (A[i] == target)
			return true;
	return false;
}

int main() {
	int A[] = {4,5,6,7,0,1,2};
	int target = 0;
	int n = sizeof(A) / sizeof(A[0]);
	cout<<simple_search(A, n, target)<<"\t"<<search(A, n, target)<<endl;

	int B[] = {1,1,3,1};
	target = 3;
	n = 4;
	cout<<simple_search(B, n, target)<<"\t"<<search(B, n, target)<<endl;
	
	return 0;
}