class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 8ms runtime and 9mb storage
        if (!strs.size()) return "";
        int shortest = shortestStr(strs);
        string prefix;
        for (int i = 0; i < shortest && allMatch(strs, i); ++i)
        {
            prefix += strs[0][i];
        }
        return prefix;
    }
    
    int shortestStr(const vector<string>& strs)
    {
        int cur = numeric_limits<int>::max();
        for (int i = 0; i < strs.size(); ++i)
        {
            if (strs[i].size() < cur)
            {
                cur = strs[i].size();
            }
        }
        return cur;
    }
    
    bool allMatch(const vector<string>& strs, int index)
    {
        int curChar = strs[0][index];
        for (int i = 1; i < strs.size(); ++i)
        {
            if (strs[i][index] != curChar) return false;
        }
        return true;
    }
};