#include <iostream>
#include <vector>
#include "util.h"

using namespace std;
/**
 * 方法1
 */
// void printEdge(vector<<vector<int>>& vec, int tR, int tC, int dR, int dC) {
//     if (tR = dR) {
//         for (int i = lL, i <= lR; i++) {
//             cout << vec[tR][i]  << " " ;
//         } 
//     } else if(tC == dC) {
//         cout << vec[i][tC] << " ";
//     } else {
//         int curC = tc;
//         int curR = tR;
//         while (curC != dc) {
//             cout << vec[tR][curC] + " ";
//             curC++;
//         }
//         while (curR != dR) {
//             cout << vec[curR][dC] + " ";
//         }
//         while (curC != tC) {
//             cout << vec[dR][curC] + " ";
//         }
//         while (curR != tR) {
//             cout << vec[]
//         }
//     }
// }

//方法二
void print(vector<vector<int>>& vec) {
    if(vec.size() == 0) return;
    int left = 0;
    int right = vec[0].size() - 1;
    int high = 0;
    int bottom = vec.size() - 1;
    while(left <= right && high <= bottom) {
        for (int i = left; i <= right; i++) cout<< vec[high][i] << " " ;
        for (int i = high + 1; i <= bottom; i++) cout << vec[i][right];
        if(left < right) {
            for (int i = right-1; i >= left; i--) cout << vec[bottom][i] << " ";
        }
        if(high < bottom) {
            for (int i = bottom - 1; i > high; i--) cout << vec[i][left] << " ";
        }
        left++, high++, bottom--, right--;
    }

}
int main() {
    vector<vector<int>> a;
    matrixRandom(a);
    printMatrix(a);
    print(a);
}
