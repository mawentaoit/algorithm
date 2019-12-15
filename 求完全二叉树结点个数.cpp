#include <iostream>
#include <vector>
#include <stack>
#include "util.h"

int getHeighLeft(TreeNode* head, int level) {
    if(head == nullptr) return 0;
    while(head != nullptr) {
        head = head->left;
        level++;
    }
    return level - 1;
}
int bs(TreeNode* head, int l, int h) {
    if(l == h) return 1;
    if(getHeighLeft(head->right, l+1) == h) {
        return (1 << (h-l)) + bs(head->right, l+1, h); 
    } else {
        return (1 << (h-l-1)) + bs(head->left, l + 1, h);
    }
}
int TreeNodeNumbers(TreeNode* head) {
    if(head == nullptr) return 0;
    return bs(head, 1, getHeighLeft(head, 1));
}
int main() {
        TreeNode* head = new TreeNode(4);
		head->left = new TreeNode(2);
		head->right = new TreeNode(6);
		head->left->left = new TreeNode(1);
		head->left->right = new TreeNode(3);
		head->right->left = new TreeNode(5);
        printTree(head);
        cout << "该完全二叉树结点个数为: " << TreeNodeNumbers(head) << endl;

        head = createBinaryTree(4, 1, 10);
        printTree(head);
        cout << "该完全二叉树结点个数为: " << TreeNodeNumbers(head) << endl;       
}