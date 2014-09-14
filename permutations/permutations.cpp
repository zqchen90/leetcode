/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &ret,
			vector<int> &path,
			vector<int> &num) {
	if (path.size() == num.size()) {
		ret.push_back(path);
		return;
	}
	int cur;
	vector<int>::iterator idx;
	for (int i = 0; i < num.size(); ++i) {
		cur = num[i];
		idx = find(path.begin(), path.end(), cur);
		if (idx == path.end()) {
			path.push_back(cur);
			dfs(ret, path, num);
			path.pop_back();
		}
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > ret;        
	vector<int> path;
	dfs(ret, path, num);
	return ret;
}

void print_vector(vector<vector<int> > v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout<<v[i][j]<<" ";	
		}
		cout<<endl;
	}
}

int main() {
	int num_array[] = {1,2,3};
	vector<int> num(num_array, num_array + sizeof(num_array)/sizeof(int));
	vector<vector<int> > ret = permute(num);
	print_vector(ret);
}