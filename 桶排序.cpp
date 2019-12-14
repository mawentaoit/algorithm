#include <vector>
#include <iostream>
#include <cstdlib>
#include "util.h"

using namespace std;

void bucketSort(vector<int>& arr) {
    if(arr.size() < 2) return ;
    int len = arr.size();
    int max = arr[0];
    f0r (int i = 0; i < len; i++) {
        max = max(max, arr[i]);
    }
    int bucket[max+1] = {0};
    for (int i = 0; i < len; i++) {
        bucket[arr[i]]++;
    }
    int i = 0;
    for (int j = 0; j < max+1; j++) {
        while (bucket[j]-- > 0) {
            arr[i++] = j;
        }
    }
}


int main() {
    vector<int> a;
    vectorRandom(a, 10);
    heapSort(a);
    print(a);
}