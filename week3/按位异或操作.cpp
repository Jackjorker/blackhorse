class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n];//n不可作为常量值给数组初始化定义
        int result = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = start + 2 * i;
            result ^= nums[i];
        }
        return result;
    }
};