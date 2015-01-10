#include <iostream>
#include "czqvector.h"

using namespace std;

int main() {
    vector<int> v1 = build_int_vector("1,2,3,4,5", ',');
    print_vector(v1);

    vector<int> v2 = build_int_vector("1 2 3 4 5", ' ');
    print_vector(v2);

    cout<<vector_equal(v1, v2)<<endl;
    return 0;
}

