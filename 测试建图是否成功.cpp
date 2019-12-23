#include <iostream>
#include <map>
#include "util.h"

int main() {
    Graph g;
    vector<int> v1= {1,1,2};
    vector<int> v2= {2,2,3};
    vector<int> v3= {3,3,1};
    vector<vector<int>> vec = {v1,v2,v3};
    // for(auto iter : vec) {
    //     for(auto iter2 : iter) {
    //         cout << iter2 << endl;
    //     }
    // }
    g.createGraph(vec);
    for(auto iter : *g.nodes) {
        cout << "编号: " << iter.first << "值: " << iter.second->value << "入度: " << iter.second->in << "出度" << iter.second->out << endl;
        //  "from: " << iter.second->next[0].value <<  "to: " << iter.second->next->value << endl;
    } 
}