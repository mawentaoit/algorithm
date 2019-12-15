#include <iostream>
#include <vector>
#include <stack>
#include "util.h"

void serialize(TreeNode* head, string& res) {
    if(head == nullptr) {
        res += "#!";
        return;
    }
    res += to_string(head->val) + "!";
    serialize(head->left, res);
    serialize(head->right, res);
}

/**
 * 中序反序列化
 */
TreeNode* dePreOrder(queue<string>& qe) {
    string value = qe.front();
    qe.pop();
    if(value == "#") return nullptr;
    TreeNode* head = new TreeNode(stoi(value));
    head->left = dePreOrder(qe);
    head->right = dePreOrder(qe);
    return head;
}
TreeNode* deSerialize(string& str) {
    if(str == "!#"){
        return nullptr;
    }
    queue<string>  strVec = split(str, "!");
    // while(!strVec.empty()) {
    //     cout << strVec.front() << " ";
    //     strVec.pop();
    // }
    return dePreOrder(strVec);
}
int main() {
    TreeNode* head = createBinaryTree(3, 10 ,20);
    printTree(head);
    string res = "";
    serialize(head, res);
    cout << "序列化" << endl;
    cout << res << endl;
    cout << "反序列化" << endl;
    TreeNode* p = deSerialize(res);
    printTree(p);
}