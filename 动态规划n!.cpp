#include <iostream>
#include <vector>

long getNI(int n) {
    if(n == 1) {
        return 1L;
    }
    return (long)n * getNI(n-1);
}

int main() {
    long res = getNI(3);
    std::cout << res << std::endl;
}

//打印一个字符串的全排列
//打印一个字符串的子序列