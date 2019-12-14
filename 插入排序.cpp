#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

void insertSort(vector<int>& a) {
    int len = a.size();
    for(int i=0; i<len; ++i) {
        for(int j = i-1; j >= 0 && a[j] > a[j+1]; j--) {
            swap(a[j],a[j+1]);
        }
    }
}


int main() {
    vector<int> a;
    vectorRandom(a, 10);
    insertSort(a);
    print(a);
}