//并查集
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "util.h"
using namespace std;
class Node {
    int val;
public:
    Node(int val = 0) : val(val) {};
};
class UnionFindSet{
public:
        map<Node*, Node*> fatherMap;
        map<Node*, int>* sizeMap;
        UnionFindSet(){
            fatherMap = new map<Node*, Node*>;
            sizeMap = new map<Node*, int>;
        }
        void makeSet(list<Node*> nodes) {
            fatherMap->clear();
            sizeMap->clear();
            for(auto node : nodes) {
                fatherMap->insert(make_pair(node, node));
                sizeMap->insert(make_pair(node, 1));
            }
        }
        //是否为相同的并查集
        bool isSameSet(Node* a, Node* b) {
            return findHead(a) == findHead(b);
        }
        //合并两个集合
        void unionTwo(Node* a, Node* b) {
            if(a == nullptr || b == nullptr) {
                return;
            }
            Node* aHead = findHead(a);
            Node* bHead = findHead(b);
            if(aHead != bHead) {
                int aSetSize = 0, bSetSize = 0;
                auto sizeIter = sizeMap->find(aHead);
                if(sizeIter != sizeMap->end()) {
                    aSetSize = sizeIter->second;
                }
                sizeIter = sizeMap->find(bHead);
                if(sizeIter != sizeMap->end()) {
                    bSetSize = sizeIter->second;
                }
                if(aSetSize <= bSetSize) {
                    (*fatherMap)[aHead] = bHead;
                    (*sizeMap)[aHead] = aSetSize + bSetSize;
                }
            }
        }
private:
        Node* findHead(Node* node) {
            //找到node节点的头结点，并把所有子结点都指向头节点
            auto findIter   = fatherMap->find(node);
            if(findIter != fatherMap->end()) {
                Node* father = findIter->second;
                if(father != node){
                //如果父节点不是本节点,那么就一直找到父节点
                    father = findHead(father); 
                } 
                fatherMap->insert(make_pair(node, father));
                return father;
            }
            return nullptr;
        }
};

int main() {
    list<Node*> lst;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    lst.push_back(node1);
    lst.push_back(node2);
    lst.push_back(node3);
    lst.push_back(node4);
    UnionFindSet u;
    u.makeSet(lst);
    cout << u.isSameSet(node1, node2) << endl;
    u.unionTwo(node1, node2);
    cout << u.isSameSet(node1, node2) << endl;   
    cout << u.isSameSet(node1, node3) << endl;
    u.unionTwo(node2,node3);  
    cout << u.isSameSet(node1, node3) << endl;  
}