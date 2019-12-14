#include <vector>
#include <iostream>
#include <cstdlib>
#include "util.h"
#include <algorithm>

using namespace std;

int bucket(long num, long len, long min, long max) {
    return (int)((num-min)*len/(max-min));
}
int maxGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int len = nums.size();
    int m_min = nums[0];
    int m_max = nums[0];
    for (int i = 0; i < len; i++) {
        m_min = min(m_min, nums[i]);
        m_max = max(m_max, nums[i]);
    }
    //如果最小值和最大值相等，那么最大差值为0
    if (m_min == m_max)  return 0;
    //安装len+1个桶bool变量，如果为true说明桶中有数字，为false说明桶中没数字
    bool hasNum[len+1] = {false};
    int maxs[len+1] = {0};
    int mins[len+1] = {0};
    int bid = 0; 
    for (int i = 0; i < len; i++) {
        //确定一个桶的边界
        bid = bucket(nums[i], len, m_min, m_max);
        mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]) : nums[i];
        maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]) : nums[i];
        hasNum[bid] = true;
    }
    int res = 0;
    int lastMax = maxs[0];
    for(int i = 1; i <= len; i++) {
        if(hasNum[i]) {
            res = max(res, mins[i] - lastMax);
            lastMax = maxs[i];
        }
    }
    return res;
}


int main() {
    vector<int> a;
    vectorRandom(a, 10);
    cout << maxGap(a) << endl;
}