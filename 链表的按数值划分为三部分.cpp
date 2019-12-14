/**
 * 将单向链表按某值划分成左边小，中间相等，右边大的形式
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "util.h"
using namespace std;
linkList* DivideByNum(linkList* head, int num) {
    if(head == nullptr) return head;
    linkList* minList = nullptr;
    linkList* maxList = nullptr;
    linkList* midList = nullptr;
    linkList* i = nullptr, *j = nullptr, *k = nullptr;
    linkList* next;
    while(head != nullptr) {
        next = head->next;
        head->next = nullptr;
        if(head->val == num) {
            if(midList == nullptr) {
                midList = head;
                midList->next = nullptr;
                i = midList;
            } else {
                i->next = head;
                i = head;
                i->next = nullptr;
            }
        }else {
            if(head->val > num) {
                if(maxList == nullptr) {
                    maxList = head;
                    maxList->next = nullptr;
                    j = maxList;
                } else {
                    j->next = head;
                    j = head;
                    j->next = nullptr;
                }
            } else {
                 if(minList == nullptr) {
                    minList = head;
                    minList->next = nullptr;
                    k = minList;
                } else {
                    k->next = head;
                    k = head;
                    k->next = nullptr;
                }               
            }
        }
        head = next; 
    }
    //测试
    // printLinkList(minList);
    // printLinkList(maxList);
    // printLinkList(midList);
    if(midList != nullptr) {
        k->next = midList;
        if(maxList!= nullptr) {
            i->next  = maxList;
        }
    } else {
        if(maxList != nullptr) {
            k->next = maxList;
        }
    }
    return minList;
}

int main() {
linkList *head = listRandom(10, 10, 20);
printLinkList(head);
printLinkList(DivideByNum(head, 15));
}