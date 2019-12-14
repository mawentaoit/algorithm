#ifndef _UTIL_H
#define _UTIL_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

/**
 * 随机整数容器
 */
void vectorRandom(vector<int>& a, int length) {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,100);
    for(int i = 0; i<length; ++i) {
        a.push_back(u(e));
    }
}
/**
 * 打印容器
 */
template<typename T>
void print(const vector<T>& b) {
    for(auto iter : b) cout << iter << " ";
    cout << endl;
}


/**
 * 随机数发生器
 */
int random(int min, int max) {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(min, max);      
    return u(e);
}



/**
 * 打印矩阵
 */
void printMatrix(const vector<vector<int>>& b) {
    int row = b.size();
    int col = b[0].size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << b[i][j] << " " ;
        }
        cout << endl;
    }
}
/**
 * 随机整数矩阵产生器
 */
void matrixRandom(vector<vector<int>>& a, int row, int col) {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(3,10);   
    for(int i = 0; i<row; i++) {
        a.push_back(vector<int>());
        for(int j = 0; j<col; j++) {
            a[i].push_back(u(e));
        }
    } 
}




/**
 * 随机整型链表产生器
 */
struct linkList{
    int val;
    linkList* next;
    linkList(int _val = 0) : val(_val) , next(nullptr) {};
};
linkList* listRandom(int nums, int random_min, int random_max) {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(random_min,random_max);  
    linkList* tmp = nullptr;
    linkList* head = nullptr;
    linkList* p = new linkList();
    head = tmp = p;
    p->val = u(e);
    p->next = nullptr;
    while(--nums) {
        p = new linkList();
        p->val = u(e);
        tmp->next = p;
        tmp = p;
    }
    return head;
}
/**
 * 打印链表
 */
void printLinkList(linkList* head) {
    if(head == nullptr){
        cout << "链表为空" << endl;
    }
    linkList* tmp = head;
    while(tmp) {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}



/**
 * 二叉树产生器
 */
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val = 0) : val(_val) , left(nullptr), right(nullptr){};
};
/**
 * @param tall : 最大树高
 * @param isComplete: bool 是否为完全二叉树
 */
TreeNode* createBinaryTree(int tall, int min = 1, int max = 100) {
        if(tall <= 0) return nullptr;
        TreeNode* p = new TreeNode();
        p->val = random(min, max);
        p->left = createBinaryTree(tall-1, min, max);
        p->right = createBinaryTree(tall-1, min, max);
        return p;
}

string getSpace(int num) {
    string space = " ";
    string buf = "";
    for (int i = 0; i < num; i++) {
        buf.append(space);
    }
    return buf;
}
void printInOrder(TreeNode* head, int height, string to, int len) {
    if(head == nullptr) return;
    printInOrder(head->right, height + 1, "v", len);
    string val = to + to_string(head->val) + to;
    int lenM = val.size();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) << val << endl;
    printInOrder(head->right, height+1, "^", len);
}
/**
 * 中序打印二叉树
 */
void printTree(TreeNode* head) {
    cout << "Binary Tree: " << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}



#endif