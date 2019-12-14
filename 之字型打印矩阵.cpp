#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void printLevel(vector<vector<int>>& vec , int tR, int tC, int dR, int dC, bool f) {
    if(f) {
        //高行只要不等于低行，那么说明还没有走到尽头
        while(tR != dR + 1) {

            cout << vec[tR++][tC--]  << " ";
        }
        //如果从上往下打，那么tR++, tC--
    } else {
        while(dR != tR - 1) {
            cout << vec[dR--][dC++] << " ";
        }
    }
}
void printMatrixZigZag(vector<vector<int>>& vec) {
    if(vec.size() == 0) return;
    int tR = 0;
    int tC = 0;
    int dR = 0;
    int dC = 0;
    int endR = vec.size() - 1;
    int endC = vec[0].size() - 1;
    bool fromUp = false;
    while(tR != endR+1) {
        printLevel(vec, tR, tC, dR, dC, fromUp);
        tR = tC == endC ? tR + 1 : tR; //如果高列走到列最后面，就应该朝下走，所以如果高列等于最后的列，那么就高行就开始往低行走
        tC = tC == endC ? tC : tC + 1; //如果高列没有走到高列最后，那么继续往后走
        dC = dR == endR ? dC + 1 : dC; //如果低行没有到最后一行，那么就不懂低列
        dR = dR == endR ? dR : dR + 1; //如果低行没有走到最后，那么移动低行
        fromUp = !fromUp; //交替打印
    }
}


int main() {
    vector<vector<int>> a;
    matrixRandom(a,4,4);
    printMatrix(a);
    cout << endl;
    printMatrixZigZag(a);
    cout << endl;   
}