class Solution {
public:
    string longestWord(vector<string>& words) {
        // runtime 224ms storage 19.7mb
        if (!words.size()) return "";
        // game plan: set to contain all of our words
        // for each word:
        // for each character in each word: does the current subword show up in our set? if it does, continue iteration. if not, move onto the next word
        string max("");
        set<string> unique;
        for (int i = 0; i < words.size(); ++i)
        {
            unique.insert(words[i]);
        }
        for (int i = 0; i < words.size(); ++i)
        {
            string subWord("");
            bool completed(true);
            for (int chr = 0; chr < words[i].size(); ++chr)
            {
                subWord += words[i][chr];
                if (unique.find(subWord) != unique.end())
                    continue;
                else
                {
                    completed = false;
                }
            }
            if (!completed)
                continue;
            max = subWord.size() > max.size() ? subWord : 
                    subWord.size() == max.size() ? smallerLexOrder(subWord, max) :
                    max;
        }
        return max;
        
    }
    
    string smallerLexOrder(string lhs, string rhs)
    {
        int min = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
        for (int i = 0; i < min; ++i)
        {
            if (lhs[i] < rhs[i])
                return lhs;
            else if (rhs[i] < lhs[i])
                return rhs;
        }
        return lhs.size() < rhs.size() ? lhs :
                rhs.size() < lhs.size() ? rhs :
                lhs;
    }
};