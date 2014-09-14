/*
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


void dfs(vector<string> &keyboard,
			vector<string> &ret,
			string &path,
			int cnt,
			string digits) {
	if (cnt == digits.size()) { 
		ret.push_back(path);
		return;
	}
	//for (int i = cnt; i < digits.size(); ++i) {
		int num = digits[cnt] - '0';
		for (int j = 0; j < keyboard[num].size(); ++j) {
			path += keyboard[num][j];
			dfs(keyboard, ret, path, cnt + 1, digits);
			path.erase(path.end() - 1);
		}
	//}
}

vector<string> letterCombinations(string digits) {
	string keyboard_array[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
								"tuv", "wxyz"};
	vector<string> keyboard(keyboard_array, keyboard_array + sizeof(keyboard_array) / sizeof(string));
	vector<string> ret;
	int cnt = 0;
	string path = "";
	dfs(keyboard, ret, path, cnt, digits);
	return ret;
}

int main() {
	string digits = "23";
	vector<string> ret = letterCombinations(digits);
	for (int i = 0; i < ret.size(); ++i) {
		cout<<ret[i]<<endl;
	}
}