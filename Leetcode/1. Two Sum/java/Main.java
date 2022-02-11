public class Main {
    public static void main(String[] args) {
        // 初始化数组
        int[] nums = {2, 7, 11, 15};

        // 求解
        Solution solution = new Solution();
        int[] result = solution.twoSum(nums, 9);

        // 打印
        for (int x: result) {
            System.out.printf("%d ", x);
        }
    }
}
