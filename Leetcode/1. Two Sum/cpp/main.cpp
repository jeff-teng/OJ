#include <iostream>
#include <vector>

#include "twoSum.hpp"

using namespace std;


int main() {
    // 初始化数组
    vector<int> nums = {2, 7, 11, 15};

    // 求解
    vector<int> result = Solution().twoSum(nums, 9);

    // 打印
    for (int x: result) {
        cout << x << " ";
    }

    return 0;
}