#include <iostream>
#include <vector>
#include "util.h"
using namespace std;
int main() {
    TreeNode* head = nullptr;
    // head = createBinaryTree(3);
    head = new TreeNode(1);
    head->right = new TreeNode(3);
    head->left = new TreeNode(4);
    head->right->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    printTree(head);
}