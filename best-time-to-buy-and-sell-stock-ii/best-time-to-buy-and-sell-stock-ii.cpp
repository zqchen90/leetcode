#include <iostream>
#include <vector>

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
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

int find_next_min(vector<int> &prices, int start) {
	for (int i = start; i < prices.size() - 1; i++) {
		if (prices[i] < prices[i + 1]) {
			return i;
		}
	}
	return -1;
}

int find_next_max(vector<int> &prices, int start) {
	for (int i = start; i < prices.size() - 1; i++) {
		if (prices[i] > prices[i + 1]) {
			return i;
		}
	}
	return prices.size() - 1;
}

int maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	int profit = 0;
	int buy_price = -1;
	int sell_price = -1;
	int index = 0;
	int next_index = 0;
	while (index < prices.size()) {
		next_index = find_next_min(prices, index);
		if (next_index < 0) {
			break;
		}
		buy_price = prices[next_index];
		index = next_index;
		next_index = find_next_max(prices, index);
		sell_price = prices[next_index];
		profit += sell_price - buy_price;
		index = next_index;
	}
    return profit;
}

void test() {
	vector<int> prices;

	int array1[] = {2,2,3,4,7,0,2,6};
	copy_array_to_vector(array1, sizeof(array1) / sizeof(int), prices);
	if (11 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<endl;

	int array2[] = {2,1,2,0,1};
	copy_array_to_vector(array2, sizeof(array2) / sizeof(int), prices);
	if (2 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<endl;

	int array3[] = {6,1,3,2,4,7};
	copy_array_to_vector(array3, sizeof(array3) / sizeof(int), prices);
	if (7 == maxProfit(prices))
		cout<<"success"<<endl;
	else
		cout<<"fail"<<endl;
}

int main() {
	test();
}
 