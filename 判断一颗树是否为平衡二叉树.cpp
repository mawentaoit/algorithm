#include <iostream>
#include <vector>
#include "util.h"

int getHeight(TreeNode* head, int level, bool* res) {
    if(head == nullptr) return level;
    int lH = getHeight(head->left, level + 1, res);
    if(!*res) {
        return level;
    }
    int rH = getHeight(head->right, level + 1, res);
    if(!*res) {
        return level;
    }
    if(abs(lH - rH) > 1) {
        *res = false;
    }
    return max(lH, rH);
}
bool isBalancedTree(TreeNode* head) {
    bool *res;
    *res = true;
    getHeight(head, 1, res);
    return *res;
}
int main() {
		TreeNode* head = new TreeNode(1);
		// head->left = new TreeNode(2);
		// head->right = new TreeNode(3);
		// head->left->left = new TreeNode(4);
		// head->left->right = new TreeNode(5);
		// head->right->left = new TreeNode(6);
		// head->right->right = new TreeNode(7);
        head->left = new TreeNode(2);
        head->left->left = new TreeNode(3);
    cout <<  isBalancedTree(head) << endl;
}