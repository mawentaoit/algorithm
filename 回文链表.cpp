#include <iostream>
#include <vector>
#include <stack>
#include "util.h"

using namespace std;
//n额外空间
bool isPalindrome1(linkList* head) {
    stack<int> st;
    linkList* cur = head;
    while (cur) {
        st.push(cur->val);
        cur = cur->next;
    }
    while(head) {
        if(head->val != st.top()) {
            return false;
        }
        st.pop();
        head = head->next;
        return true;
    }
}
//n/2n辅助空间
bool isPalindrome2(linkList* head) {
    if(head == nullptr || head->next == nullptr) return true;
    linkList* tmp = head;
    
}
int main() {
    linkList* head;
    head = listRandom(1, 10, 50);
    bool i = isPalindrome1(head);
    if(i) cout << "是回文链表" << endl;
    else cout << "不是回文链表" << endl;
    printLinkList(head);
}