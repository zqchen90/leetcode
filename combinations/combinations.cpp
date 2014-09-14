/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &ret,
			vector<int> &path,
			int start,
			int cnt,
			int n,
			int k) {
	if (cnt == k) {
		ret.push_back(path);
		return;
	}
	for (int i = start; i <= n; ++i) {
		path.push_back(i);
		dfs(ret, path, i + 1, cnt + 1, n, k);
		path.pop_back();
	}
	return; 
}
	
vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ret;
	vector<int> path;
	int start = 1;
	int cnt = 0;
	dfs(ret, path, start, cnt, n, k);
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
	print_vector(combine(4, 2));
}