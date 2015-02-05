#include <iostream>
#include <algorithm>
#include "czqvector.h"
#include "czqtester.h"

using namespace std;

struct Bucket {
    int min;
    int max;
    Bucket() : min(-1), max(-1) {}
    Bucket(int minimum, int maximum) : min(minimum), max(maximum) {}
};

void print_buckets(vector<Bucket> &buckets) {
    for (int i = 0; i < buckets.size(); ++i) {
        cout<<"["<<buckets[i].min<<", "<<buckets[i].max<<"]  ";
    }
    cout<<endl;
}

int maximumGap(vector<int> &num) {
    // Find max and min
    int max_num = num[0];
    int min_num = num[0];
    for (int i = 1; i < num.size(); ++i) {
        max_num = max(max_num, num[i]);
        min_num = min(min_num, num[i]);
    }
    int range = max_num - min_num;
    int gap_number = num.size() - 1;
    int bucket_size = (range ) / gap_number + 1;
    vector<Bucket> buckets (num.size(), Bucket());
    // Fill number into buckets
    for (int i = 0; i < num.size(); ++i) {
        int bucket_index = (num[i] - min_num) / bucket_size;
        if (buckets[bucket_index].min == -1) {
            buckets[bucket_index].min = num[i];
        } else {
            buckets[bucket_index].min = min(buckets[bucket_index].min, num[i]);
        }
        buckets[bucket_index].max = max(buckets[bucket_index].max, num[i]);
    }
    print_buckets(buckets);
    // Find max gap
    int max_gap = bucket_size;
    int prev_bucket_max = buckets[0].max;
    for (int i = 1; i < buckets.size(); ++i) {
        if (buckets[i].min == -1 || buckets[i].max == -1) {
            continue;
        }
        max_gap = max(max_gap, buckets[i].min - prev_bucket_max);
        prev_bucket_max = buckets[i].max;
    }
    return max_gap;
}

void test(string input, int result) {
    vector<int> inputv = build_int_vector(input, ',');
    int output = maximumGap(inputv);
    czqassert(output, result);
}

int main() {
    test("3,2,1,7,6", 3);    

    return 0;
}

