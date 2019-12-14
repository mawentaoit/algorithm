#include <iostream>
#include <vector>
#include <stack>
#include "util.h"


linkList* reverseLinkList(linkList* head) {
    if(head == nullptr || head->next == nullptr) return head;
    linkList* pre = nullptr;
    linkList* next = nullptr;
    while(head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}


int main() {
    linkList* head;
    head = listRandom(10, 10, 50);
    printLinkList(head);
    linkList* tmp;
    tmp = reverseLinkList(head);
    printLinkList(tmp);
}