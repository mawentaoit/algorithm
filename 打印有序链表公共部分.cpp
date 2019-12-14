#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

void printCommonPart(linkList* head1, linkList* head2) {
    if(head1 == nullptr || head2 == nullptr) return;
    while(head1 != nullptr && head2 != nullptr) {
        if(head1->val == head2->val) {
            cout << head1->val << " ";
            head1 = head1->next;
            head2 = head2->next;
        } else {
            if(head1->val > head2->val) {
                head2 = head2->next;
            } else {
                head1 = head1->next;
            }
        }
    }
    cout << endl;
}


int main() {
    linkList* head1 = new linkList(2);
    head1->next = new linkList(3);
    head1->next->next = new linkList(5);

    linkList* head2 = new linkList(1);
    head2->next = new linkList(2);
    head2->next->next = new linkList(5);
    head2->next->next->next = new linkList(7);
    printLinkList(head1);
    printLinkList(head2);
    printCommonPart(head1, head2);
}