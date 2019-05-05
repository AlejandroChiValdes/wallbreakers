class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 8ms runtime and 8.7mb storage
        // takes care of most cases; only need to increment the first item
        int sz = digits.size();
        if (digits[sz - 1] < 9)
            {
                ++digits[sz - 1];
                return digits;
            }
        for (int i = sz - 1; i >= 0; --i)
        {
            if (digits[i] < 9)
            {
                ++digits[i];
                return digits;
            }
            else
            {
                digits[i] = 0;
                if (!i)
                {
                    digits.insert(digits.begin(), 1);
                }
            }
        }
        
        
        return digits;


    }
};