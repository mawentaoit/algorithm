#include <iostream>
#include <vector>

using namespace std;

class arrayStack {
private:
    int* st;
    int size;
    int len;
public: 
    arrayStack(int size) {
        st = new int[size];
        len = size;
        size = 0;
    }
    void push(int num) {
        if(size >= len) {
            cout << "栈满" << endl;
            return;
        }
        st[size++] = num; 
    }
    int pop() {
        if(size <= 0){
            cout << "栈空" << endl;
            return -1;
        } 
        return st[--size]; 
    }
    int top() {
        if(size <= 0) cout << "栈空" << endl;
        return st[size-1];
    }
    ~arrayStack() {
        delete[] st;
    }
};

int main() {
    arrayStack st(10);
    st.push(1);
    st.push(2);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
}