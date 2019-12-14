#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bucket(long num, long len, long min, long max) {
    return (int)((num-min) * len / (max - min));
}

int maxGap(vector<int>& nums) {
    if(nums.size() < 2) {
        return 0;
    }
    int len = nums.size();
    int m_min = nums[0];
    int m_max = nums[0];
    for (int i = 0; i < len; ++i) {
        m_min = min(m_min, nums[i]);
        m_max = max(m_max, nums[i]); 
    }
    if(m_min == m_max) {
        return 0;
    }
    bool hasNum[len+1] = {0};
    int maxs[len+1] = {0};
    int mins[len+1] = {0};
    int bid = 0;
    for(int i = 0; i < len; ++i) {
        bid = bucket(nums[i], len, m_min, m_max);
        mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]) : nums[i];
        maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]) : nums[i];
        hasNum[bid] = true;
    }
    int res = 0;
    int lastMax = maxs[0];
    for(int i = 1; i <= len; ++i) {
        if(hasNum[i]) {
            res = max(res, mins[i] - lastMax);
            lastMax = maxs[i];
        }
    }
    return res;
}


int main() {
    vector<int> a = {1,2,5,7,4,3,6,8,9,4,75,53,75,54};
    cout << maxGap(a) << endl;
}