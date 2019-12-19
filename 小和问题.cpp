#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

// void merge(vector<int>& vec, int* sum, int begin, int end){
//     if(begin >= end) return;
//     int a[end-begin+1] = {0};
//     int mid = begin + ((end - begin) >> 1);
//     int Lbegin = begin;
//     int Lend = mid;
//     int Rbegin = mid+1;
//     int Rend = end;
//     merge(vec, sum,Lbegin, Lend);
//     merge(vec, sum, Rbegin, Rend);
//     int i = 0;
//     while(Lbegin <= Lend && Rbegin <= Rend) {
//         if(vec[Lbegin] < vec[Rbegin]) {
//             *sum += (Rend-Rbegin+1)*vec[Lbegin];
//             a[i++] = vec[Lbegin++];
//         } else {
//             a[i++] = vec[Rbegin++];
//             *sum += 0;
//         }
//     }
//     while(Lbegin <= Lend) {
//         a[i++] = vec[Lbegin++];
//     }
//     while(Rbegin <= Rend) {
//         a[i++] = vec[Rbegin++];
//     }
//     for(int i=0; i<end-begin+1; i++){
//         vec[begin+i] = a[i];
//     }
// } 
// int mergeSrot(vector<int>& vec) {
//     int sum = 0;
//     if(vec.size() < 2) return 0;
//     int len = vec.size();
//     merge(vec, &sum, 0, len-1);
//     return sum;
// }



    void merge(vector<int>& data, int begin, int end, int* res) {
        if(begin >= end) return ;
        int mid = begin + ((end-begin) >> 1) ;
        int beginL = begin; int beginR = mid+1;
        int endL = mid; int endR = end;
        merge(data, beginL, endL, res);
        merge(data, beginR, endR, res);
        vector<int> helper(end-begin+1);
        int i  = 0;
        while(beginL <= endL && beginR <= endR) {
            if(data[beginL] <= data[beginR]) {
                helper[i++] = data[beginL++];
            } else {
                *res += (mid - beginL + 1);
                
                if(*res > 1000000007) {
                    *res %= 1000000007;
                }
                helper[i++] = data[beginR++];
            }
        }
        while(beginL <= endL) {
            helper[i++] = data[beginL++];
        }
        while(beginR <= endR) {
            helper[i++] = data[beginR++];
        }
        for(int i = 0; i < end-begin+1; i++) {
            data[begin+i] = helper[i++];
        }
    }
    int InversePairs(vector<int> data) {
        if(data.size() <= 1) return 0;
        int dataLen = data.size();
        int res = 0;
        merge(data, 0, dataLen-1, &res);
        return res;
    }

int main() {
    // vector<int> a;
    // vectorRandom(a, 10);
    vector<int> a = {1,2,3,4,5,6,0};    
    int sum = InversePairs(a);
    print(a);
    cout << sum << endl;
}