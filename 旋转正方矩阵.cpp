#include <iostream>
#include <vector>
#include "util.h"

using namespace std;
// void rotate(vector<vector<int>>& vec) {
//     int hRow = 0;
//     int hCol = vec[0].size() - 1;
//     int lRow = vec.size() - 1;
//     int lCol = 0;
//     while (hRow < lRow) {
//         rotateEdge(vec, hRow, lCol, lRow, hCol);
//     }
// }

// void rotateEdge(vector<vector<int>>& vec, int hRow, int lCol, int lRow, int hCol) {
//     int times = hCol - lCol;
//     int tmp = 0;
//     for (int i = 0; i != times; i++) {
//         tmp = vec[hRow][lCol + i];
//         m[hRow][lCol+i] = m[lRow - i][]
//     }
// }
void rotateEdge(vector<vector<int>>& vec, int left, int right, int high, int bottom) {
    int times = bottom - high;
    int tmp = 0;
    for (int i = 0; i < times; i++) {
        tmp = vec[high][left+i];
        vec[high][left+i] = vec[bottom-i][left];
        vec[bottom-i][left] = vec[bottom][right-i];
        vec[bottom][right-i] = vec[high+i][right];
        vec[high+i][right] = tmp;
    }
}
void rotate(vector<vector<int>>& vec) {
    int left = 0;
    int right = vec.size() - 1;
    int bottom = vec[0].size() - 1;
    int high = 0;
    while(left < right && high < bottom) {
        rotateEdge(vec,left++, right--, high++, bottom--);
    }
}
int main() {
    vector<vector<int>> a;
    matrixRandom(a,4,4);
    printMatrix(a);
    cout << endl;
    rotate(a);
    printMatrix(a);
    cout << endl;
}