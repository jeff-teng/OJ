import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // 初始化 hash 表
        HashMap<Integer, Integer> hashableNums = new HashMap<>();

        // 存储数据
        for (int i = 0; i < nums.length; i++) {
            // 查找是否已加入 hash 表
            if (hashableNums.containsKey(target - nums[i])) {
                // 如果找到结果，直接返回
                return new int[]{hashableNums.get(target - nums[i]), i};
            }
            // 没有找到结果，加入 hash 表
            hashableNums.put(nums[i], i);
        }
        return new int[]{};
    }
}