#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void merge(vector<int>& vec, int* sum, int begin, int end){
    if(begin >= end) return;
    int a[end-begin+1] = {0};
    int mid = begin + ((end - begin) >> 1);
    int Lbegin = begin;
    int Lend = mid;
    int Rbegin = mid+1;
    int Rend = end;
    merge(vec, sum,Lbegin, Lend);
    merge(vec, sum, Rbegin, Rend);
    int i = 0;
    while(Lbegin <= Lend && Rbegin <= Rend) {
        if(vec[Lbegin] < vec[Rbegin]) {
            *sum += (Rend-Rbegin+1)*vec[Lbegin];
            a[i++] = vec[Lbegin++];
        } else {
            a[i++] = vec[Rbegin++];
            *sum += 0;
        }
    }
    while(Lbegin <= Lend) {
        a[i++] = vec[Lbegin++];
    }
    while(Rbegin <= Rend) {
        a[i++] = vec[Rbegin++];
    }
    for(int i=0; i<end-begin+1; i++){
        vec[begin+i] = a[i];
    }
} 
int mergeSrot(vector<int>& vec) {
    int sum = 0;
    if(vec.size() < 2) return 0;
    int len = vec.size();
    merge(vec, &sum, 0, len-1);
    return sum;
}

int main() {
    vector<int> a;
    vectorRandom(a, 10);
    vector<int> a = {4,2,5,1,7,3,6};    
    int sum = mergeSrot(a);
    print(a);
    cout << sum << endl;
}