#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
//n/2辅助空间 快慢指针实现
bool isPalindrome2(linkList* head) {
    if(head == nullptr || head->next == nullptr) return true;
    linkList* quick = head;
    linkList* slow = head->next;
    while(quick->next!= nullptr && quick->next->next != nullptr) {
        slow = slow->next;
        quick = quick->next->next;
    }
    stack<int> st;
    while(slow != nullptr) {
        st.push(slow->val);
        slow = slow->next;
    }
    while(!st.empty()) {
        if(head->val != st.top()) {
            return  false;
        }
        st.pop();
    }
    return true; 
}

// O(1) 辅助空间
//反转链表
linkList*  swapLink(linkList* head) {
    linkList * pre = nullptr;
    linkList * after = nullptr;
    while(head != nullptr) {
        after = head->next;
        head->next = pre;
        pre = head;
        head = after;
    }
    return pre;
}
bool isPalindrome3(linkList* head) {
    if(head == nullptr || head->next == nullptr) return true;
    linkList* quick = head;
    linkList* slow = head;
    //首先让slow走到中点位置(此位置为中间的前或中位置)
    /**
     * eg 1->3->1
     * 此时slow 会在1位置
     */
    while(quick->next != nullptr && quick->next->next != nullptr) {
        quick = quick->next->next;
        slow = slow->next;
    }
    //让中间包括后面链表反转(此时)
    linkList* tail =   swapLink(slow->next);
    // printLinkList(tail);
    linkList * temp = tail;
    while(temp != nullptr) {
        if(temp->val != head->val) {
            slow->next = swapLink(tail);
            return  false;
        }
        temp = temp->next;
        head = head->next;
    }
    slow->next = swapLink(tail);
    return true;
}
int main() {
    linkList* head = new linkList(2);
    head->next = new linkList(3);
    head->next->next = new linkList(3);
    head->next->next->next = new linkList(2);
    // head = listRandom(3, 10, 50);

    bool i = isPalindrome3(head);
    if(i) cout << "是回文链表" << endl;
    else cout << "不是回文链表" << endl;
    printLinkList(head);
}