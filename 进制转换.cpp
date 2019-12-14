#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s="", table ="0123456789ABCDE";
    int m, n;
    cin >> m >> n;
    while(m) {
        if(m < 0) {
            m= -m;
            cout << "-";
        }
        s=table[m%n]+s;
        m/=n;
    }
    cout << s << endl;
    return 0;
}