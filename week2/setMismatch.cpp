class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // runtime 92ms storage 22.1mb
        set<int> unique;
        int total = (nums.size() * (nums.size() + 1)) / 2;
        int current(0);
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            current += nums[i];
            pair<set<int>::iterator, bool> dup = unique.insert(nums[i]);
            if (!dup.second)
            {
                result.push_back(nums[i]);
                current -= nums[i];
            }
        }
        result.push_back(total - current);
        return result;
    }
};