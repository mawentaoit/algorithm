#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "util.h"
using namespace std;
int func(vector<vector<int>> matrix, int i, int j) {
    if(i == matrix.size()-1 && j == matrix[0].size()-1) return matrix[i][j];
    if(i == matrix.size()-1) {
        return matrix[i][j] + func(matrix, i, j+1);
    }
    if(j == matrix[0].size()-1) {
        return matrix[i][j] + func(matrix, i+1, j);
    }
    return matrix[i][j] + min(func(matrix, i, j+1),func(matrix, i+1, j));
}
map<string, int> cache;
/*记忆化搜索方法，做一个傻缓存*/
int func1(vector<vector<int>> matrix, int i, int j) {
    int result = 0;
    if(i == matrix.size()-1 && j == matrix[0].size()-1) return matrix[i][j];
    if(i == matrix.size()-1) {
        return matrix[i][j] + func(matrix, i, j+1);
    }
    if(j == matrix[0].size()-1) {
        return matrix[i][j] + func(matrix, i+1, j);
    }
    return matrix[i][j] + min(func(matrix, i, j+1),func(matrix, i+1, j));
}
int minPath(vector<vector<int>> matrix) {
    return func(matrix, 0, 0);
}

int main() {
    vector<vector<int>> a;
    matrixRandom(a,15,15);
    printMatrix(a);
    std::cout << minPath(a) << std::endl;
}