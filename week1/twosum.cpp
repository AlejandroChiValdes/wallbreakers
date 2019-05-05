class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 12ms runtime and 10.1 mb storage
        map<int,int> index;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (index.find(nums[i]) != index.end()) 
                return vector<int> {index[nums[i]], i };
            else
            {
                index[target - nums[i]] = i;
            }
                
        }
        return vector<int>{};
    }
};