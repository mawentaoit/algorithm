#include <iostream>
#include<vector>


using namespace std;

void func(int n, int* res) {
    if(n <= 0){
        res = 0;
        return;
    }
    if(n == 1) {
        *res += 1;
        return;
    }
    func(n-1, res);
    int temp = 1;
    while(n > 1) {
        temp *= n--;
    }
    *res += temp;
}

void fun2(int n, int* res) {
    if(n <= 0){
        res = 0;
        return;
    }
    if(n == 1) {
        *res += 1;
        return;
    }
    while(n >= 1) {
        int temp = n;
        int tmp = 1;
        while(temp > 1) {
            tmp *= temp--;
        }
        *res += tmp;
        n--;
    }   
}

int main() {
    int n = 4;
    int res = 0;
    fun2(n, &res);
    cout << res << endl;
}