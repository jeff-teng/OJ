#ifndef TWO_SUM_HPP
#define TWO_SUM_HPP

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 初始化 hash 表
        unordered_map<int, int> hashableNums;

        // 存储数据
        for (int i = 0; i < nums.size(); i++) {
            // 查找是否已加入 hash 表
           auto search = hashableNums.find(target - nums[i]);

            // 如果找到结果，直接返回
            if (search != hashableNums.end()) {
                return {search->second, i};
            }

            // 没有找到结果，加入 hash 表
            hashableNums[nums[i]] = i;
        }

        return {0, 0};
    }
};

#endif