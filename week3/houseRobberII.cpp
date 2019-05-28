class Solution {
public:
    int dpRob(vector<int>& nums) {
        // handle base cases
        if (!nums.size()) return 0;
        else if (nums.size() <= 3)
        {
            int max(-1);
            for (int num : nums)
            {
                max = num > max ? num : max;
            }
            return max;
        }
        vector<int> memo(nums.size() + 2, -1);
        vector<int> memo2(memo);
        memo[nums.size() - 1] = 0;
        memo[nums.size()] = 0;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            memo[i] = max(nums[i] + memo[i + 2], memo[i + 1]);
        }
        memo2[nums.size()] = 0;
        memo2[nums.size() + 1] = 0;
        for (int i = nums.size() - 1; i >= 1; --i)
        {
            memo2[i] = max(nums[i] + memo2[i + 2], memo2[i + 1]);
        }
        return max(memo[0], memo2[1]);
    }
    
	int rRob(vector<int>& nums) {
        // handle base cases
        if (!nums.size()) return 0;
        else if (nums.size() <= 3)
        {
            int max(-1);
            for (int num : nums)
            {
                max = num > max ? num : max;
            }
            return max;
        }
        vector<int> memo(nums.size(), -1);
        vector<int> memo2(memo);
        int firstSol = recursiveRob(nums, 0, nums.size() - 1, memo);
        int secondSol = recursiveRob(nums, 1, nums.size(), memo2);
        
        //cout << firstSol << " " << secondSol << endl;
        return max(firstSol, secondSol);
    }
    
	// recursive + memoized solution
    int recursiveRob(vector<int>& nums, int index, int end, vector<int>& memo)
    {
        if (index >= end)
        {
            return 0;
        }
        if (memo[index] == -1)
        {

            memo[index] = max(nums[index] + recursiveRob(nums, index + 2, end, memo), recursiveRob(nums, index + 1, end, memo));    
        }
        return memo[index];

    }
};