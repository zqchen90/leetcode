#include <iostream>
#include <vector>
#include <math.h>
/* 
	00 01 11 10
	000 001 011 010 110 111 101 100
	0000 0001 0011 0010 0110 0111 0101 0100
	1100 1101 1111 1110 1010 1011 1001 1000 
	*/
using namespace std;

int my_exp(int base, int n) {
	int ret = base;
	for (int i = 1; i < n; ++i) {
		ret *= base;
	}
	return ret;
}
vector<int> grayCode(int n) {
	vector<int> ret;
	int base = 1<<n;
	for (int i = 0; i < base; ++i) {
		ret.push_back(i ^ (i>>1));
	}
	return ret;
}

void print_vector(vector<int> invec) {
	vector<int>::iterator iter;
	for (iter = invec.begin(); iter != invec.end(); ++iter) {
		cout<<*iter<<"\t";
	}
	cout<<endl;
}

int main() {
	vector<int> ret = grayCode(2);
	print_vector(ret);	
	return 0;
}