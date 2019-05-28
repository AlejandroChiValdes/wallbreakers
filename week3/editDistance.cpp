class Solution {
public:
    int minDistance(string word1, string word2) {
        // min distance from 3 options at each character i and j in word1 and word2, respectively
        // insert j in front of i, then move onto j + 1 and stay at i
        // remove i, move into i + 1 and j
        // replace i with j (this takes into account if i == j, in which case the replace will cost 0, otherwise, the cost is 1)
        // take min of all these, store the result in the memo, which is word1 len x word2 len 
        vector<vector<int>> memo;
        for (int i = 0; i < word1.size() + 1; ++i)
        {
            vector<int> row(word2.size() + 1, -1);
            memo.push_back(row);
        }
        
        for (int i = word1.size(); i >= 0; --i)
        {
            for (int j = word2.size(); j >= 0; --j)
            {
                if (i == word1.size())
                {
                    memo[i][j] = word2.size() - j;
                }
                else if (j == word2.size())
                {
                    memo[i][j] = word1.size() - i;
                }
                else
                {
                    int isEqual = word1[i] == word2[j] ? 0 : 1;
                    memo[i][j] = 
                        min( min (
                        // insert char word2[j] into word[1]
                        1 + memo[i][j+1],
                        // remove char word1[i]
                        1 + memo[i+1][j]
                         ), 
                        // replace char word1[i] with word2[j]
                        isEqual + memo[i+1][j+1]
                            );
                }
            }
        }
        return memo[0][0];
    }
};