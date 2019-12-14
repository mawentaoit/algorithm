
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "util.h"


linkList* getLoopNode(linkList* head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return nullptr;
    linkList* n1 = head->next;
    linkList* n2 = head->next->next;
    while(n1 != n2) {
        if (n2->next == nullptr || n2->next->next == nullptr) {
            return nullptr; //如果能跑到链表末尾说明这个链表无环
        }
        n2 = n2->next->next;
        n1 = n1->next;
    }
    n2 = head; //让快指针从头开始走，知道快慢指针相遇，便是环入口节点
    while(n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}

/**
 * 两个链表没有环，求相交节点的情况
 */
linkList* noLoop(linkList* head1, linkList* head2) {
    if(head1 == nullptr || head2 == nullptr) return nullptr; //只要有一个为空，那么必定不存在环
    linkList* cur1 = head1;
    linkList* cur2 = head2;
    int n = 0;
    //首先遍历出两条链表的长度之差
    while(cur1 != nullptr) {
        n++;
        cur1 = cur1->next;
    }
    while(cur2 != nullptr) {
        n--;
        cur2 = cur2->next;
    }
    /**
     * 首先把cur1赋值为链表长度比较长的那条链表
     * 然后求出两条链表长度之差，先让长的链表进行移动那些差值，然后共同移动，必当会经过相交的第一个节点
     */
    if(n >0) {
        cur1 = head1;
        cur2 = head2;
    } else {
        cur2 = head1;
        cur1 = head2;
    }
    n = abs(n);
    while(n != 0) {
        n--;
        cur1 = cur1->next;
    }
    while(cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

/**
 * 两个有环链表相交节点的情况
 */
linkList* bothLoop(linkList* head1, linkList* loop1, linkList* head2, linkList* loop2) {
    linkList* cur1 = nullptr;
    linkList* cur2 = nullptr;
    if (loop1 == loop2) {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while(cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while(cur2 != loop2) {
            n--;
            cur2 = cur2->next;
        }
        if(n >0) {
            cur1 = head1;
            cur2 = head2;
        } else {
            cur2 = head1;
            cur1 = head2;
        }
        n = abs(n);
        while(n != 0) {
            n--;
            cur1 = cur1->next;
        } 
        while(cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }       
        return cur1;
    } else {
        //这里有两种情况，如果在一个换上相交，那么一定可以循环找到两个入环点
        //如果不相交，那么直接返回nullptr
        cur1 = loop1->next;
        while(cur1 != loop1) {
            if (cur1 == loop2) return loop1;
            cur1 = cur1->next;
        }
        return nullptr;
    }
}
/**
 * 得到相交链表的相交节点（其中每条链表都有可能有环）
 */
linkList* getIntersectNode(linkList* head1, linkList* head2) {
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    linkList* loop1 = getLoopNode(head1);
    linkList* loop2 = getLoopNode(head2);
    //上诉代码测试链表是否有环，
    if(loop1 == nullptr && loop2 == nullptr) {//如果无环，进入
        return noLoop(head1, head2);
    }
    if (loop1 != nullptr && loop2 != nullptr) {
        return bothLoop(head1, loop1, head2, loop2);
    }
    //为什么没有一个链表有环，一个链表无环，并且相交的情况呢？因为，一旦有一个链表有环，如果
    //另一个链表与之相交，那么必定也有环，所以只有两种情况，同时有环，和同时无环的情况
    return nullptr;
}

/**
 * 由于测试原因，没有释放内存，有内存泄漏
 */
int main() {
    // 1->2->3->4->5->6->7->nullptr
    linkList* head1 = new linkList(1);
    head1->next = new linkList(2);
    head1->next->next = new linkList(3);
    head1->next->next->next = new linkList(4);
    head1->next->next->next->next = new linkList(5);
    head1->next->next->next->next->next = new linkList(6);
    head1->next->next->next->next->next->next = new linkList(7);

    // 0->9->8->6->7->nullptr
    linkList* head2 = new linkList(0);
    head2->next = new linkList(9);
    head2->next->next = new linkList(8);
    head2->next->next->next = head1->next->next->next->next->next; //8->6
    cout << getIntersectNode(head1, head2)->val;


    //1->2->3->4->5->6->7->4
    head1 = new linkList(1);
    head1->next = new linkList(2);
    head1->next->next = new linkList(3);
    head1->next->next->next = new linkList(4);
    head1->next->next->next->next = new linkList(5);
    head1->next->next->next->next->next = new linkList(6);
    head1->next->next->next->next->next->next = new linkList(7);   
    head1->next->next->next->next->next->next  = head1->next->next->next;  //7->4

    head2 = new linkList(0);
    head2->next = new linkList(9);
    head2->next->next = new linkList(8);
    head2->next->next->next = head1->next;
    cout << getIntersectNode(head1, head2)->val << endl;


    		// 0->9->8->6->4->5->6..
}