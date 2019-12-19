#include <iostream>
#include <map>
#include <vector>
#include <string>

/**
 * map以模板(泛型)方式实现
 * map内部的实现自建一颗红黑树，这棵树具有对数据自动排序的功能
 */
using namespace std;
int main() {
    map<int, string> person;
    //插入元素
    person.insert(pair<int,string>(1,"mawentao")); //通过pair方式创建
    person.insert(map<int,string>::value_type(2,"mwt")); //通过value_type
    //前两种方式相同key值不能插入成功
    person[3] = "mawentao2";
    //这种方式相同key值进行value值覆盖
    //查找元素,find返回迭代器指向当前查找元素的位置否则返回map::end()位置
    auto iter = person.find(1);
    if(iter != person.end()) {
    cout << iter->second << endl;
    }else {
        cout << "Do not Find" << endl;
    }

    for(map<int,string>::value_type iter : person) {
        cout << iter.second << endl;
    }
    //map大小
    cout << "map size: " << person.size() << endl;
    //删除元素
    iter = person.find(1);
    person.erase(1);
    cout << "delete 1 : " << endl;
        for(map<int,string>::value_type iter : person) {
        cout << iter.second << endl;
    }
/**
 * hash_map 其中map底层为红黑树，并且保证排序，
 * hash_map底层为hash表，
 * 首先分配一大片内存，形成许多桶。利用hash函数，对key进行映射到不同的区域(桶)进行保存
 */
    // cout << "创建hash表" << endl;
    // hash_map<int,string> m_map;
    // m_map.insert(pair<int,string>(1,"mawentaot"));
    // m_map.insert(pair<int,string>(2,"mwt"));
    // for(auto iter : m_map) {
    //     cout << iter.second << endl;
    // }

}
