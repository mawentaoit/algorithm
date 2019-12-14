#include <iostream>
#include <vector>
#include "util.h"

using namespace std;
void bubbleSort(vector<int>& a, int len) {
    if (a.size() < 2) return ;
    for(int i=0; i<len; ++i) {
        for(int j=0; j<len-i-1; ++j) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}


int main() {
    vector<int> a;
    vectorRandom(a,12);
    // for(auto iter : a) cout << iter << endl;
    bubbleSort(a,12);
    print(a);
}