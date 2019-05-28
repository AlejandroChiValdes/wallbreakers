class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [=] (int x, int y) {return x > y;});
        int total(0);
        for (int i = 1; i < nums.size(); i += 2)
        {
            total += nums[i];
        }
        return total;
    }
};