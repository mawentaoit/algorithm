#include <vector>
#include <iostream>
#include <cstdlib>
#include "util.h"

using namespace std;

//建成大顶堆
void heapInsert(vector<int>& vec, int index) {
    while(vec[index] > vec[(index-1) / 2]) {
        swap(vec[index], vec[(index-1)/2]);
        index = (index - 1) / 2;
    }
}

//调整堆顶
void heapify(vector<int>& vec, int index, int size) {
    int left = index * 2 + 1;
    while (left < size) {
        int largest = left + 1 < size && vec[left+1] > vec[left] ? left + 1 : left;
        largest = vec[largest] > vec[index] ? largest : index;
        if(largest == index) {
            break;
        }
        swap(vec[largest], vec[index]);
        index = largest;
        left = index * 2 + 1;
    }
}

void heapSort(vector<int>& vec) {
    if(vec.size() < 2) return ;
    for (int i = 0; i < vec.size(); i++) {
        heapInsert(vec, i);
    }
    int size = vec.size();
    swap(vec[0], vec[--size]);
    while(size > 0) {
        heapify(vec, 0, size);
        swap(vec[0], vec[--size]);
    }
}

int main() {
    vector<int> a;
    vectorRandom(a, 10);
    heapSort(a);
    print(a);
}