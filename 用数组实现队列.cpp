#include <iostream>
#include <vector>

using namespace std;
class ArrayQueue{
private:
    int size;
    int length;
    int* arr;
    int start;
    int end;
public:
    ArrayQueue(int initSize) {
        if(initSize < 0) cout << "初始值不能为空" << endl;
        size = 0;
        length = initSize;
        arr = new int[initSize];
        start = 0;
        end = 0;
    }
    void push(int nums) {
        if(size >= length){
            cout << "队列已满" << endl;
            return;
        }
        arr[end] = nums;
        size++;
        end = end == length -1 ? 0 : start + 1;
    }
    int top() {
        return arr[start];
    }
    int pop() {
        if(size <= 0) {
            cout << "队列为空" << endl;
            return NULL;
        }
        int temp = arr[start];
        size--;
        start = start == length - 1 ? 0 : start + 1;
        return temp;
    }
    int Size() {
        return size;
    }
    ~ArrayQueue() {
        delete[] arr;
    }
};

int main() {
    ArrayQueue a(3);
    a.push(2);
    cout << "top: " << a.top() << endl;
    a.push(3);
    a.push(4);
    cout << "pop: " << a.pop() << endl;
    a.push(5);
    for(int i = 0; i<a.Size(); i++) {
     cout << "pop: " << a.pop() << endl;       
    }
    cout << "top: " << a.top() << endl;   
}
//听懂啥意思
//你如果不知道这个问题，你思维就被限制住了，你就废了，你看我用了
//队列怎么实现栈结构
