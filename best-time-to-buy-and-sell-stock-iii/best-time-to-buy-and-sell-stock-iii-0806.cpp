#include <iostream>
#include <vector>
#include <algorithm>

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock 
before you buy again).

https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

using namespace std;

int maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	
	int *left = new int[prices.size()];
	int *right = new int[prices.size()];  
	for (int i = 0; i < prices.size(); ++i) {
		left[i] = 0;
		right[i] = 0;
	}

	// left[i] is the max profit when buy and sell once in [0, i]
	// left[i] = max(left[i - 1], price[i] - min)
	int min = prices[0];
	for (int i = 1; i < prices.size(); ++i) {
		min = prices[i] < min ? prices[i] : min;
		left[i] = left[i - 1] > prices[i] - min ? left[i - 1] : prices[i] - min;
	}

	
	// right[i] is the max profit when buy and sell once in [i, end]
	// right[i] = max(right[i + 1], max - price[i])
	int max = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; --i) {
		max = prices[i] > max ? prices[i] : max;
		right[i] = right[i + 1] > max - prices[i] ? right[i + 1] : max - prices[i];
	}

	// max profit = max{left[i] + right[i]} foreach i
	int profit = 0;
	for (int i = 0; i < prices.size(); ++i) {
		profit = left[i] + right[i] > profit ? left[i] + right[i] : profit;
	}
	return profit;
}

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

void test() {
	vector<int> prices;

	int array1[] = {2,2,3,4,7,0,2,6};
	copy_array_to_vector(array1, sizeof(array1) / sizeof(int), prices);
	if (11 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;

	int array2[] = {2,1,2,0,1};
	copy_array_to_vector(array2, sizeof(array2) / sizeof(int), prices);
	if (2 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;

	int array3[] = {6,1,3,2,4,7};
	copy_array_to_vector(array3, sizeof(array3) / sizeof(int), prices);
	if (7 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;

	int array4[] = {2,1};
	copy_array_to_vector(array4, sizeof(array4) / sizeof(int), prices);
	if (0 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;
	
	int array5[] = {1,2,4,2,5,7,2,4,9,0};
	copy_array_to_vector(array5, sizeof(array5) / sizeof(int), prices);
	if (13 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;
	
	int array6[] = {2,6,8,7,8,7,9,4,1,2,4,5,8};
	copy_array_to_vector(array6, sizeof(array6) / sizeof(int), prices);
	if (14 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;
	 
	int array7[] = {8,6,4,3,3,2,3,5,8,3,8,2,6};
	copy_array_to_vector(array7, sizeof(array7) / sizeof(int), prices);
	if (11 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;

	int array8[] = {6,5,4,8,6,8,7,8,9,4,5};
	copy_array_to_vector(array8, sizeof(array8) / sizeof(int), prices);
	if (7 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;

	int array9[] = {1,3,5,4,3,7,6,9,2,4};
	copy_array_to_vector(array9, sizeof(array9) / sizeof(int), prices);
	if (10 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;

	int array10[] = {3,4,6,0,3,7,5,8,2,9,1,6,6,2};
	copy_array_to_vector(array10, sizeof(array10) / sizeof(int), prices);
	if (15 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<" "<<maxProfit(prices)<<endl;
}

int main() {
	test();
}
 