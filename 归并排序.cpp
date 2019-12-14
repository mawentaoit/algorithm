#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void merge(vector<int>& vec, int begin, int end){
    if(begin >= end) return;
    int a[end-begin+1] = {0};
    int mid = begin + ((end - begin) >> 1);
    // int mid = (begin + end)/2;
    int Lbegin = begin;
    int Lend = mid;
    int Rbegin = mid+1;
    int Rend = end;
    merge(vec,  Lbegin, Lend);
    merge(vec,  Rbegin, Rend);
    int i = 0;
    while(Lbegin <= Lend && Rbegin <= Rend) {
        if(vec[Lbegin] < vec[Rbegin]) {
            a[i++] = vec[Lbegin++];
        } else {
            a[i++] = vec[Rbegin++];
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
void mergeSrot(vector<int>& vec) {
    if(vec.size() < 2) return;
    int len = vec.size();
    merge(vec, 0, len-1);
}

int main() {
    vector<int> a;
    vectorRandom(a, 10);
    mergeSrot(a);
    print(a);
}