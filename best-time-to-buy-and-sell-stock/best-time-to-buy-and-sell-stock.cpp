#include <iostream>
#include <vector>

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one 
share of the stock), design an algorithm to find the maximum profit.

https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

using namespace std;

void print_vector(vector<int> &v) {
	vector<int>::iterator iter;  
    for (iter=v.begin();iter!=v.end();iter++)  
    {  
        cout<<*iter<<", ";  
    }
    cout<<endl;
}

void copy_array_to_vector(int array[], int n, vector<int> &vec) {
	vec.clear();
	for (int i = 0; i < n; ++i) {
		vec.push_back(array[i]);
	}
}

int maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;

    int profit = 0;
    int min = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        min = min > prices[i] ? prices[i] : min;
        profit = profit < prices[i] - min ? prices[i] - min : profit;
    }
    return profit;
}

void test() {
	vector<int> prices;

	int array1[] = {2,2,3,4,7,0,2,6};
	copy_array_to_vector(array1, sizeof(array1) / sizeof(int), prices);
	if (6 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<endl;

	int array2[] = {2,1,2,0,1};
	copy_array_to_vector(array2, sizeof(array2) / sizeof(int), prices);
	if (1 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<endl;

	int array3[] = {6,1,3,2,4,7};
	copy_array_to_vector(array3, sizeof(array3) / sizeof(int), prices);
	if (6 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<endl;
}

int main() {
	test();
}
 