#include <iostream>
#include <vector>
#include <stack>
#include "util.h"

//递归前序遍历
void preOrderPrint(TreeNode* head) {
    if(head == nullptr) return ;
    cout << head->val << " " ;
    preOrderPrint(head->left);
    preOrderPrint(head->right);
}
//非递归前序遍历
void preOrderPrint1(TreeNode* head) {
    if(head == nullptr) return;
    stack<TreeNode*> st;
    st.push(head);
    TreeNode* temp = head;
    while(!st.empty()) {
        TreeNode* a = st.top();
        st.pop();
        cout << a->val << " " ;
        if(a->right != nullptr) {
            st.push(a->right);
        }
        if(a->left != nullptr) {
            st.push(a->left);
        }
    }
}
//递归中序遍历
void InOrderPrint(TreeNode* head) {
    if(head == nullptr) return ;
    InOrderPrint(head->left);
    cout << head->val << " " ;
    InOrderPrint(head->right);   
}

//中序非递归遍历
void InOrderPrint1(TreeNode* head) {
    if(head == nullptr) return;
    stack<TreeNode*> st;
    while(!st.empty() || head != nullptr) {
        //首先找到最左边的地方
        while(head != nullptr) {
            st.push(head);
            head = head->left;
        }
        if(!st.empty()) {
            head = st.top(); 
            st.pop();
            //现在到了最左边
            cout << head->val << " " ;
            head = head->right;
        }
    }
}
//递归后续遍历
void afterOrderPrint(TreeNode* head) {
    if(head == nullptr) return ;
    afterOrderPrint(head->left);
    afterOrderPrint(head->right);   
    cout << head->val << " " ;
}
//非递归后续遍历
void afterOrderPrint1(TreeNode* head) {
    stack<TreeNode*> st;
    TreeNode* r = nullptr; //使用辅助指针,指向最近访问过的节点
    while(!st.empty() || head != nullptr) {
        if(head != nullptr) {
            st.push(head);
            head = head->left; //一直遍历到左子树最低端，存入栈中
        } else {
            head = st.top(); //取出一个节点
            if(head->right != nullptr && head->right != r) {
                //如果这个节点有右子树，且上次没有遍历右子树，那么就访问右子树
                head = head->right;
            } else {
                st.pop();
                cout << head->val << " ";
                r = head; //记录这一次遍历的节点
                head = nullptr;
            }
        }
    }
}
int main() {
    TreeNode* head;
    head = createBinaryTree(4,20, 40);
    printTree(head);
    cout << endl;
    cout << "递归先序" << endl;
    preOrderPrint(head);
    cout << endl;
    cout << "非递归先序" << endl;    
    preOrderPrint1(head);
    cout << endl;
    cout << "递归中序" << endl;
    InOrderPrint(head);
    cout << endl;
    cout << "非递归中序" << endl;
    InOrderPrint1(head);
    cout << endl;
    cout << "递归后序" << endl;
    afterOrderPrint(head);
    cout << endl;
    cout << "非递归后续遍历" << endl;
    afterOrderPrint1(head);
    cout << endl;
}