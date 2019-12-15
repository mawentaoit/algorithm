#include <iostream>
#include <vector>
#include <stack>

#include "util.h"

//节点定义
struct Node{
public:
int val;
Node* left;
Node* right;
Node* parent;
Node(int data) : val(data) , left(nullptr), right(nullptr), parent(nullptr) {};
};


/**
 * 寻找后继节点
 */
Node* getLeftMost(Node* head) {
    if(head != nullptr) return head;
    while(head->left != nullptr) {
        head = head->left;
    };
    return head;
}
Node* findAfterNode(Node* head) {
    if(head == nullptr) return head;
    //如果有右子树，直接进入右子树，遍历到以右子树为根的最左边节点
    //如果没有右子树，说明这是中间节点，那么向上查找，直到孩子节点为父节点的左子树节点为止
    if(head->right != nullptr) {
       return getLeftMost(head->right);
    }
    Node* parent = head->parent;
    while(parent != nullptr && parent->left != head) {
        head = parent;
        parent = parent->parent;
    }
    return parent;
}

/**
 * 寻找前驱节点
 */
//发现最右节点
Node* getRightMost(Node* head) {
    if(head == nullptr) return head;
    while(head->right != nullptr) {
        head = head->right;
    }
    return head;
}
Node* findPreNode(Node* head) {
    if(head == nullptr) return head;
    if(head->left != nullptr) return getRightMost(head->left); //找到左子树中最右的节点
    Node* parent = head->parent;
    while(parent != nullptr && parent->right != head) {
        head = parent;
        parent = parent->parent;
    }
    return parent;
}


int main() {
    Node* head;
		head = new Node(6);
		head->parent = nullptr;
		head->left = new Node(3);
		head->left->parent = head;
		head->left->left = new Node(1);
		head->left->left->parent = head->left;
		head->left->left->right = new Node(2);
		head->left->left->right->parent = head->left->left;
		head->left->right = new Node(4);
		head->left->right->parent = head->left;
		head->left->right->right = new Node(5);
		head->left->right->right->parent = head->left->right;
		head->right = new Node(9);
		head->right->parent = head;
		head->right->left = new Node(8);
		head->right->left->parent = head->right;
		head->right->left->left = new Node(7);
		head->right->left->left->parent = head->right->left;
		head->right->right = new Node(10);
		head->right->right->parent = head->right;   
    cout << "后继节点" << ": ";
    cout << findAfterNode(head->left->left)->val << endl;
    cout << "前驱节点" << ": ";
    cout << findPreNode(head)->val << endl;
}