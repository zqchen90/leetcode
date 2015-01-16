# [Anagrams](https://oj.leetcode.com/problems/anagrams/)
## Question
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

## "Anagrams"
Rearrange the letters of a word or phrase to produce a new word or phrase.

## AC
2015-1-7

## Solution

Anagrams have the same histogram of letters. Anagrams become same strings after sort. How to check "sorted anagrams" are same? 
  - We can organize "sorted anagrams" with same length into groups and only compare those in the same group.
  - More efficient way: use hashmap to check whether the same "sorted anagram" already exists.

### Compare the same length

anagrams.cpp

### Hashmap

anagrams_hash.cpp

Use an unordered_map[string, int] to save the [sorted_string, index]:

  1. For each string, sort it
  1. Check whether the sorted string is in the hashmap, if YES: add the string (before sorting) to result; if NO: add the sorted string to the hashmap

Note: Mark the value (index) to -1 if the string in the hashmap has already be added to the result.

Time:

  1. Sort string: O(Ndlogd), where d is the average length of the strings
  2. Hash check: O(N)
  3. Total: O(N + Ndlogd), is O(N) when N is very large

Space: O(N)