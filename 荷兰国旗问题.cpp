#include <vector>
#include <iostream>
#include "util.h"

using namespace std;
void helan(vector<int>& vec, int i) {
    int len = vec.size();
    int less = -1;
    int more = len;
    int index = 0;
    while(index < more) {
        if(vec[index] < i) {
            swap(vec[++less], vec[index++]);
        } else if(vec[index] > i) {
            swap(vec[--more], vec[index]);
        } else {
            index++;
        }
    }
}

int main() {
    vector<int> a;
    vectorRandom(a, 10);
    helan(a,30);
    print(a);
}