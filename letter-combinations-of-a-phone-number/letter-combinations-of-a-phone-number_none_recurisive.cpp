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


vector<string> letterCombinations(string digits) {
	string keyboard_array[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
								"tuv", "wxyz"};
	vector<string> keyboard(keyboard_array, keyboard_array + sizeof(keyboard_array) / sizeof(string));
	vector<string> ret;
	
	// TODO

	return ret;
}

int main() {
	string digits = "23";
	vector<string> ret = letterCombinations(digits);
	for (int i = 0; i < ret.size(); ++i) {
		cout<<ret[i]<<endl;
	}
}