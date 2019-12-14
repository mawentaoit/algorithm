#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class StackByQueue{
private:
queue<int> data;
queue<int> helper;
public:
    void push(int num) {
        data.push(num);
    }
    int pop(){
        // if(helper.empty()) {
        //     if(!data.empty()){
        //         while(!data.empty()) {
        //             helper.push(data.front());
        //             data.pop();
        //         }
        //     } else {
        //         cout << "栈为空" << endl;
        //     }

        // }
        // int temp = helper.front();
        // helper.pop();
        // return temp;
        if (data.empty()) {
            cout << "栈为空" << endl;
        }
        while(data.size() > 1) {
            int temp = data.front();
            data.pop();
            helper.push(temp);
        }
        int res = data.front();
        data.pop();
        helper.swap(data);
        return res;
    }
    int top() {
        // if(helper.empty()) {
        //     if(!data.empty()){
        //         while(!data.empty()) {
        //             helper.push(data.front());
        //             data.pop();
        //         }
        //     }
        //     cout << "栈为空" << endl;
        // }
        // return helper.front();       
        if (data.empty()) {
            cout << "栈为空" << endl;
        }
        while(data.size() != 1) {
            int temp = data.front();
            data.pop();
            helper.push(temp);
        }

        int res = data.front();
        data.pop();
        helper.push(res);
        helper.swap(data);
        return res;
    }
};

int main() {
    StackByQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "pop: " << s.pop() << endl;
    cout << "pop: " << s.pop() << endl;   
    cout << "pop: " << s.pop() << endl;   
}