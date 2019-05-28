
// Iterative DP
class Solution {
public:
    int pSize;
    int sSize;
    bool isMatch(string s, string p) {
        pSize = p.size();
        sSize = s.size();
        vector<vector<int>> memo;
        for (int i = 0; i <= sSize; ++i)
        {
            vector<int> row(pSize + 1, -1);
            memo.push_back(row);
        }
        memo[sSize][pSize] = true;
        for (int i = sSize; i >= 0; --i)
        {
            for (int j = pSize; j >= 0; --j)
            {
                if (j >= pSize)
                    memo[i][j] = i >= sSize;
                else if (p[j] == '*')
                    continue;
                else if (j < pSize - 1 && p[j + 1] == '*')
                {
                    if (i < sSize && (s[i] == p[j] || p[j] == '.'))
                    {
                        memo[i][j] = memo[i + 1][j] || memo[i][j + 2];
                    }
                    else
                    {
                        memo[i][j] = memo[i][j + 2];
                    }     
                }
                else
                    memo[i][j] = i < sSize && (s[i] == p[j] || p[j] == '.') && memo[i + 1][j + 1];
            }
        }
        return memo[0][0];
    }
};

// Memoized Recursion
class Solution {
public:
    int pSize;
    int sSize;
    bool isMatch(string s, string p) {
        pSize = p.size();
        sSize = s.size();
        vector<vector<int>> memo;
        for (int i = 0; i <= sSize; ++i)
        {
            vector<int> row(pSize + 1, -1);
            memo.push_back(row);
        }
        return dpIsMatch(s, p, 0, 0, memo);
    }
    
    bool dpIsMatch(string s, string p, int i, int j, vector<vector<int>>& memo)
    {
        if (j >= pSize)
            return i >= sSize;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (j < pSize - 1 && p[j + 1] == '*')
        {
            if (i < sSize && (s[i] == p[j] || p[j] == '.'))
            {
                memo[i][j] = dpIsMatch(s, p, i + 1, j, memo) || dpIsMatch(s, p, i, j + 2, memo);
                return memo[i][j];
            }
            else
            {
                memo[i][j] = dpIsMatch(s, p, i, j + 2, memo);
                return memo[i][j];
            }
                
        }
        memo[i][j] = i < sSize && (s[i] == p[j] || p[j] == '.') && dpIsMatch(s, p, i + 1, j + 1, memo);
        return memo[i][j];

    }
};