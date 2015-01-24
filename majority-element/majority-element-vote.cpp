// https://oj.leetcode.com/discuss/22620/an-easy-way-to-solve-the-problem-24ms

// Every number in the vector votes for itself, 
// the majority number gets the most votes. 
// Different number offsets the votes.

int majorityElement(vector<int> &num) {
    int vote = num[0];
    int count = 1;
    int size = num.size();
    //vote from the second number
    for( int i = 1; i < size; i++ )
    {
        if( count == 0 ) { vote = num[i]; count++; }
        else if( vote == num[i] )   count++;
        else count--;
    }
    return vote;
}