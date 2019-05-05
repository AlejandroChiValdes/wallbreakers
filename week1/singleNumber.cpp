class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //16ms runtime and 9.9mb storage
        int cur(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            cur ^= nums[i];
        }
        return cur;
    }
};