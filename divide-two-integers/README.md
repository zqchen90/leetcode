# [Divide Two Integers ](https://oj.leetcode.com/problems/divide-two-integers/)

## Question
Divide two integers without using multiplication, division and mod operator.

return dividend / divisor

If it is overflow, return MAX_INT.

## AC
2014-9-20

## Solution

### Subtract divisor from dividend

Very direct solution, but will TLE.

### A faster solution

If dividend - divisor > 0, we will always try to double divisor next time.

```cpp
newdivisor = divisor;
newdivisor = newdivisor << 1;
```

if dividend - newdivisor < 0, we will try again from divisor.

In both solutions above, we should deal with the sign (positive or negative) first, and use unsigned int in the calculate to avoid overflow.

If the result is larger than INT_MAX (2147483647), we should return INT_MAX directly.

