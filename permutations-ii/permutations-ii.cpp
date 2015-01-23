/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void dfs(vector<vector<int> > &ret,
			vector<int> &path,
			vector<int> &num,
			unordered_map<int, int> &num_cnt,
			int n) {
	if (path.size() == n) {
		ret.push_back(path);
		return;
	}
	int cur;
	vector<int>::iterator idx;
	for (int i = 0; i < num.size(); ++i) {
		cur = num[i];
		if (num_cnt[cur] >= 1) {
			path.push_back(cur);
			num_cnt[cur]--;
			dfs(ret, path, num, num_cnt, n);
			path.pop_back();
			num_cnt[cur]++;
		}
	}
}

vector<vector<int> > permuteUnique(vector<int> &num) {
	vector<vector<int> > ret;        
	vector<int> path;
	unordered_map<int, int> num_cnt;
	unordered_map<int, int>::iterator it;
	vector<int> num_uniq;
	for (int i = 0; i < num.size(); ++i) {
		it = num_cnt.find(num[i]);
		if (it == num_cnt.end()) {
			num_cnt.insert(pair<int, int> (num[i], 1));
			num_uniq.push_back(num[i]);
		} else {
			num_cnt[num[i]] += 1;
		}
	}
	// Becareful, should use num_uniq, NOT num
	// because we don't distinct two identical number
	dfs(ret, path, num_uniq, num_cnt, num.size());
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
	int num_array[] = {1,1,2};
	vector<int> num(num_array, num_array + sizeof(num_array)/sizeof(int));
	vector<vector<int> > ret = permuteUnique(num);
	print_vector(ret);
}