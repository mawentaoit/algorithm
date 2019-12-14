#include <iostream>
#include <vector>
#include "util.h"
using namespace std;
bool findNumForMatrix(vector<vector<int>>& vec, int num){
    if(vec.size() == 0) return false;
    int left = 0;
    int right = vec[0].size() - 1;
    int high = 0;
    int bottom = vec.size() - 1;
    while(right >= left && bottom >= high) {
        if(vec[high][right] == num) return true;
        if(vec[high][right] > num) {
            right--;
        }
        if(vec[high][right] < num) {
            high++;
        }
    }
    return false;
}
int main() {
    vector<vector<int>> a = { { 0, 1, 2, 3, 4, 5, 6 },// 0
				{ 10, 12, 13, 15, 16, 17, 18 },// 1
				{ 23, 24, 25, 26, 27, 28, 29 },// 2
				{ 44, 45, 46, 47, 48, 49, 50 },// 3
				{ 65, 66, 67, 68, 69, 70, 71 },// 4
				{ 96, 97, 98, 99, 100, 111, 122 },// 5
				{ 166, 176, 186, 187, 190, 195, 200 },// 6
				{ 233, 243, 321, 341, 356, 370, 380 } };
    // matrixRandom(a,10,5);
    printMatrix(a);
    cout << endl;
    cout << findNumForMatrix(a, 233);
    cout << endl;   
}