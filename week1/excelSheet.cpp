class Solution {
public:
    int titleToNumber(string s) {
        // 4ms runtime and 8.4mb storage
        int total = s[s.size() - 1] - 65 + 1;
        int offset = 1;
        for (int i = s.size() - 2; i >= 0; --i, ++offset)
        {
            total += pow(26, offset) * (s[i] - 65 + 1);
        }
        return total;
    }
};