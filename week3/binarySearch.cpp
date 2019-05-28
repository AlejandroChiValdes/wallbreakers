class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, nums, target);
    }
    
    int binarySearch(int start, int end, vector<int>& nums, int target)
    {
        if (start > end) return -1;
        int midpoint = start + (end - start) / 2;
        if (target > nums[midpoint])
            return binarySearch(midpoint + 1, end, nums, target);
        else if (target < nums[midpoint])
            return binarySearch(start, midpoint - 1, nums, target);
        return midpoint;
    }
};