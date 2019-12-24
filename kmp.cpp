#include <iostream>
#include <string>
#include <vector>
//kmp 
//int getIndexOf(str1, str2) 
//kmp,让前面配过的信息保留下来

//next数组求法
using namespace std;
vector<int>  getNext(string str) {
    vector<int> res;
    if(str.size() == 1) {
        res.push_back(-1);
        return res;
    }
    res.push_back(-1);
    res.push_back(0);
    int i = 2;
    int cn = 0;
    while(i < res.size()) {
        if(str[i-1] == str[cn]) {
            res.push_back(++cn);
        } else if (cn > 0) {
            cn = res[cn];
        } else {
            res[i++] = 0;
        }
    }
    return res;
}
int getIndexof(string s1, string s2) {
    if(s1.size() < 1 || s2.size() < 1 || s1.size() < s2.size()) {
        return -1;
    }
    vector<int> next = getNext(s2);
    int i1 = 0;
    int i2 = 0;
    while(i1 < s1.size() && i2 < s2.size()) {
        if(s1[i1] == s2[i2]) {
            i1++;
            i2++;
        } else {
            if(next[i2] == -1) {
                i1++;
            } else {
                i2 = next[i2];
            }
        }
    }
    if(i2 == s2.size()) {
        return i1-i2; //如果找到了字符串，那么就直接返回位置
    } else {
        return -1;
    }
}


int main( ) {
    string s1 = "bcabcabcd";
    string s2 = "abca";
    cout <<  getIndexof(s1,s2) << endl;
}
 
//竞赛的大佬他们都是不会的
//T1 某一颗子树是否是
//怎么判断不是由子串重复得到的
//