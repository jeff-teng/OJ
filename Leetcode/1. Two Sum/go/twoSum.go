package main

func twoSum(nums []int, target int) []int {
	// 初始化 hash 表
	hashableNums := map[int]int{}

	// 存储数据
	for i, x := range nums {
		// 查找是否已加入 hash 表
		if search, ok := hashableNums[target-x]; ok {
			// 如果找到结果，直接返回
			return []int{search, i}
		}

		// 没有找到结果，加入 hash 表
		hashableNums[x] = i
	}

	return []int{}
}
