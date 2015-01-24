# [Next Permutation ](https://oj.leetcode.com/problems/next-permutation/)
## Question
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

## Solution

 - From right to left, find the first digit (partition_number) which voilate the increase trend (increase from right to left)
 - From right to left, find the first digit which is larger than partition_number, called change_number
 - Swap partition_number and change_number
 - Reverse all the digits on the right side of partition_number

 Take 2,1,5 for example:

 - parition_number is the second digit, 1, because 1 < 5
 - change_number is 5
 - swap: 2,5,1
 - reverse: 2,5,1

Note:

 - change_number is the minimal number from right to left that can be swapped with the partition number
 - the fouth step is necessary because all the digits on the right side of partition_number is in descent order (from left to right), next permutation should make these digits in ascent order.

 The question is just the same as the following qusetion:

 Given a binary number, find the next number that has the same number of "1"s and "0"s as the input.

 - From right to left, find the first "1"
 - From right to left, find the "0"
 - Turn the first "1" to "0" and turn the first "0" to "1"
 - Push all the "1"s on the right side of the first "0" (where we turn "0" to "1") to the right side.