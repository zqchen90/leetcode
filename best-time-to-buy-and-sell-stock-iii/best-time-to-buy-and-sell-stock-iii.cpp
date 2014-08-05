#include <iostream>
#include <vector>
#include <algorithm>

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock 
before you buy again).

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

int maxProfit2(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<int> profit_list;
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
		profit = sell_price - buy_price;
		index = next_index;
		profit_list.push_back(profit);
	}

	if (0 == profit_list.size()) {
		return 0;
	}
    sort(profit_list.begin(), profit_list.end());
    reverse(profit_list.begin(), profit_list.end());
	if (profit_list.size() <= 1)
	    return profit_list[0];
	else
        return profit_list[0] + profit_list[1];
}

void print_transaction_list(vector<vector<int> > &transaction_list) {
	cout<<"----"<<endl;
	for (int i = 0; i < transaction_list.size(); ++i) {
		cout<<transaction_list[i][0]<<", "<<transaction_list[i][1]<<", "<<transaction_list[i][2]<<endl;
	}
	cout<<"----"<<endl;
}

int merge_transactions(vector<vector<int> > &transaction_list) {
	// buy_price, sell_price, profit
	int i = 0;
	bool merge_flag = false;
	while (transaction_list.size() > 2) {
		// merge i and i + 1
		//cout<<transaction_list[i][0]<<", "<<transaction_list[i][1]<<"\t";
		//cout<<transaction_list[i + 1][0]<<", "<<transaction_list[i + 1][1]<<endl;

		//print_transaction_list(transaction_list);

		int merge_profit = transaction_list[i + 1][1] - transaction_list[i][0];
		if (merge_profit > transaction_list[i][2] && merge_profit >= transaction_list[i + 1][2]) {
			transaction_list[i][1] = transaction_list[i + 1][1];
			transaction_list[i][2] = merge_profit;
			transaction_list.erase(transaction_list.begin() + i + 1);
			merge_flag = true;
		}
		else {
			++i;
			//transaction_list.erase(transaction_list.begin() + i);
		}
		//print_transaction_list(transaction_list);
		if (3 == transaction_list.size() &&
			transaction_list[2][2] < transaction_list[0][2] &&
			transaction_list[2][2] < transaction_list[1][2] &&
			(transaction_list[1][1] - transaction_list[0][0] + transaction_list[2][2])
			< (transaction_list[1][2] + transaction_list[0][2])) {

			cout<<transaction_list[0][0]<<", "<<transaction_list[0][1]<<"\t";
			cout<<transaction_list[1][0]<<", "<<transaction_list[1][1]<<"\t";
			cout<<transaction_list[2][0]<<", "<<transaction_list[2][1]<<endl;

			break;
		}
		if (i == transaction_list.size() - 1) {
			if (!merge_flag) {
				break;
			} else {
				i = 0;
				merge_flag = false;
			}
		}
	}
	//cout<<"final"<<endl;
	//print_transaction_list(transaction_list);
	vector<int> profit_list;
	for (int i = 0; i < transaction_list.size(); ++i) {
		profit_list.push_back(transaction_list[i][2]);
	}
	sort(profit_list.begin(), profit_list.end());
    reverse(profit_list.begin(), profit_list.end());
	
    if (profit_list.size() <= 1)
	    return profit_list[0];
	else
        return profit_list[0] + profit_list[1];
}

int maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<vector<int> > transaction_list;
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
		profit = sell_price - buy_price;
		index = next_index;
		vector<int> transaction;
		transaction.push_back(buy_price);
		transaction.push_back(sell_price);
		transaction.push_back(profit);
		transaction_list.push_back(transaction);
	}

	if (0 == transaction_list.size()) {
		return 0;
	}
    return merge_transactions(transaction_list);
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
 