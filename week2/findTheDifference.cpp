class Solution {
public:
    char findTheDifference(string s, string t) {
        // runtime 4ms storage 9mb
        int result(0);
        for (int i = 0; i < t.size(); ++i)
        {
            result += t[i];
        }
        for (int j = 0; j < s.size(); ++j)
        {
            result -= s[j];
        }
        char res = result;
        return res;
    }
};