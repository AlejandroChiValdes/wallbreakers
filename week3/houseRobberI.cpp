class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> memo(nums.size(), -1);
        return recursiveRob(nums.size() - 1, nums, memo);
        
    }
    
    int recursiveRob(int index, vector<int>& nums, vector<int>& memo)
    {
        if (index < 0)
            return 0;
        if (memo[index] != -1)
            return memo[index];
        memo[index] = max(nums[index] + recursiveRob(index - 2, nums, memo), recursiveRob(index - 1, nums, memo));
        return memo[index];
    }
};