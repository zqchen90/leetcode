/*  
  https://oj.leetcode.com/problems/divide-two-integers/
  Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
           int result = 0;
    int neg_flag = 1;
    unsigned int undividend = abs(dividend);
    unsigned int undivisor = abs(divisor);
    
    if (0 == dividend)
        return 0;
    
    if (0 > dividend) {
        neg_flag = 0 - neg_flag;
    }
    if (0 > divisor) {
        neg_flag = 0 - neg_flag;
    }
    
    if (1 == divisor)
        return dividend;
    
    if (2 == divisor) {
        undividend = undividend>>1;
        return undividend * neg_flag;
    }
        
    if (undivisor == undividend)
        return neg_flag;

    while (undividend >= undivisor) {
        int shift = 1;
        unsigned int newdivisor = undivisor;
        while (undividend >= newdivisor) {
            undividend -= newdivisor;
            newdivisor = newdivisor << 1;
            result += shift;
            shift = shift<<1;
        }
    }
    return result * neg_flag;
}


int main() {
	cout<<divide(-2147483648, 2);
}