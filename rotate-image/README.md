# [Rotate Image](https://oj.leetcode.com/problems/rotate-image/)
##Question

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

##Solution

### Level

Do the rotation layer by layer from outside to inside.

### Two mirrors

1. Mirror the image along the diagonal (from left bottom to right top)
2. Mirror the image vertically