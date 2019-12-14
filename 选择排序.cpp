#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void choiceSort(vector<int>& a) {
    int len = a.size();
    int minindex = 0;
    for(int i = 0; i<len-1; i++){
        minindex = i;
        for(int j = i; j < len; j++) {
            minindex = a[j] < a[minindex] ? j : minindex;
        }
        swap(a[i],a[minindex]);
    }
}

int main() {
    vector<int> a;
    vectorRandom(a, 10);
    choiceSort(a);
    print(a);
}