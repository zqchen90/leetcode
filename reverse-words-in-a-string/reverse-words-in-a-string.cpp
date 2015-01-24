#include<vector>

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;

	int strsize = s.size();
	if(strsize<1){
	    return;
	}
	
	// input " " should output ""
	if(strsize == 1){
	    if(s == " ")
	        s="";
	   return;
	}
	
	int i;
	for(i=0;i<strsize;i++){
		if(s[i] != ' ')
			break;
	}
	
	// input "     " should output ""
	if(i == strsize){
		s = "";
		return;
	}

	int wordbegin = i;

	for(;i<strsize;){
		if(s[i] == ' '){
			words.push_back(string(s,wordbegin,i-wordbegin));
			while(i<strsize &&s[i] == ' ')
				i++;
			wordbegin = i;
		}
		else
			i++;
	}
	
	
	if(wordbegin != strsize)
		words.push_back(string(s,wordbegin, strsize-wordbegin));

	s.clear();
	for(i=words.size()-1;i>0;i--){
		s.append(words[i]);
		s.append(" ");
	}
	s.append(words[0]);
    }
};