#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int f(int x) {
    if(x == 0) return 0;
    int res = INT_MAX;
    if(x >= 7) {
        res = min(f(x-7) || f(x-5) || f(x-2),
    }
    return res;
}

int main() {
    cout << "答案: " << f(27) << endl;
}
