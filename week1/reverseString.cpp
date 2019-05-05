class Solution {
public:
    void reverseString(vector<char>& s) {
        // 52ms runtime with 15.1mb storage
        for (int i = 0; i < s.size() / 2; ++i)
        {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};