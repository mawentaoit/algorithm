#include <iostream>
#include <vector>
#include <stack>
#include "util.h"


//是否为平衡二叉树
/**
 * 进行中序遍历，只要有一个比遍历前面的小，那么就不是平衡二叉树
 */
bool isBST(TreeNode* head) {
    if(head == nullptr) return true;
    stack<TreeNode*> st;
    int min = -999;
    while(!st.empty() || head != nullptr) {
        while(head != nullptr) {
            st.push(head);
            head = head->left;
        }
        if(!st.empty()) {
            head = st.top(); 
            st.pop();
            //现在到了最左边
            if(min == -999) {
                min = head->val;
            } else {
                if(head->val <= min) return false;
            }
            min = head->val;
            head = head->right;
        }        
    }
    return true;
}


//是否为完全二叉树
/**
 * 首先进程层次遍历
 * 分四种情况，如果左右子树都有，那么继续遍历，如果左子树有，右子树没有，那么剩下一定都为叶子节点
 * 如果右子树有，左子树没有，那么一定不是完全二叉树，如果左右子树都没有，那么剩下的一定都为叶子节点
 */
bool isCBT(TreeNode* head) {
    if(head == nullptr) return true;
    queue<TreeNode*> qe;
    bool leaf = false; //一个状态为，如果为真，那么后面都为叶子节点
    TreeNode* l = nullptr;
    TreeNode* r = nullptr;
    qe.push(head);
    while(!qe.empty()) {
        head = qe.front(); qe.pop();
        l = head->left;
        r = head->right;
        //如果右子树不空，左子树为空那么一定非完全二叉树，如果开启了叶子状态，那么只要左右子树不为空，就为假
        if((leaf&&(l != nullptr || r != nullptr) || (l == nullptr && r != nullptr)) {
            return false;
        }
        if(l != nullptr) {
            qe.push(l);
        }
        if(r != nullptr) {
            qe.push(r);
        } else {
            leaf = true;
        }
    }
}
int main() {
        TreeNode* head = new TreeNode(4);
		head->left = new TreeNode(2);
		head->right = new TreeNode(6);
		head->left->left = new TreeNode(1);
		head->left->right = new TreeNode(3);
		head->right->left = new TreeNode(5);
        // TreeNode* head = createBinaryTree(3, 10, 20);
        printTree(head);
        cout << isBST(head);
}