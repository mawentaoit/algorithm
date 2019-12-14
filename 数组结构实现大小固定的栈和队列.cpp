#include <iostream>
#include <vector>
using namespace std;
class ArrayStack {
private:
    int* arr;
    int size;
    int length;
public:
    ArrayStack(int initSize) {
        if(initSize < 0) {
            cout << "大小不能为负" << endl;
        }
        arr = new int[initSize];
        length = initSize;
        size = 0;
    }
    int top() {
        if(size == 0) {
            return NULL;
        }
        return arr[size-1];
    }
    int pop() {
        if(size == 0) {
            cout << "这个队列为空" << endl;
            return arr[--size];
        }
    }
    int push(int num) {
        if(size == length) {
            cout << "这个队列已经满了" << endl;
        }
        arr[size++] = num;
    }
    ~ArrayStack() {
        delete[] arr;
    }
};

int main() {
    ArrayStack a(2);
    a.push(10);
    cout << a.top() << endl;
    a.push(20);
    cout << a.top() << endl;
    a.push(30);

}