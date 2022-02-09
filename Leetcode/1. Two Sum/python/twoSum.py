from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 初始化 hash 表
        hashableNums = {}

        # 存储数据
        for i in range(len(nums)):
            # 查找是否已加入 hash 表
            if target - nums[i] in hashableNums:
                # 如果找到结果，直接返回
                return [hashableNums[target - nums[i]], i]

            # 没有找到结果，加入 hash 表
            hashableNums[nums[i]] = i

        return []
