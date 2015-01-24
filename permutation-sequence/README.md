# [Permutation Sequence ](https://oj.leetcode.com/problems/permutation-sequence/)

## Question

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

## Solution

The first digit of the kth permutation sequence is '1' + floor((k-1) / (n-1)!);

k = k - floor((k-1) / (n-1)!) * (n-1)!
n = n - 1

The second digit is the floor(1 + (k-1) / (n-1)!)-th un-used number from 0 to 9;

And so on.

Take n = 3, k = 5 for example:

1. floor((k-1)/(n-1)!) = 2, so the first digit should be '3'
2. Update n = 2, k = 1
3. floor((k-1) / (n-1)!) = 0, so digit should be '1'
4. Update n = 1, k = 1
5. floor((k-1) / (n-1)!) = 0, because '1' is already used, the "1"st un-used digit is '2'
6. Update n = 0, we find the sequence.