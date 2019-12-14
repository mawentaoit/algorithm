#include <vector>
#include <iostream>
#include <cstdlib>
#include "util.h"

using namespace std;

vector<int> partition(vector<int>& vec, int l, int r) {
    int less = l -1;
    int more = r;
    while (l < more) {
        if(vec[l] < vec[r]) {
            swap(vec[++less], vec[l++]);
        } else if (vec[l] > vec[r]) {
            swap(vec[--more], vec[l]);
        } else {
            l++;
        }
    }
    swap(vec[more], vec[r]);
    return {less+1, more};
}

void quickSort(vector<int>& vec, int l, int r) {
    if (l < r) {
        swap(vec[l + rand()%(r-l+1)], vec[r]);
        vector<int> p = partition(vec, l, r);
        quickSort(vec, l, p[0] - 1);
        quickSort(vec, p[1] + 1, r);
    }
}
void quickSort(vector<int>& vec) {
    if (vec.size() < 2) return;
    quickSort(vec, 0, vec.size() - 1);
}

int main() {
    vector<int> a;
    vectorRandom(a, 10);
    quickSort(a);
    print(a);
}