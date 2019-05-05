class Solution {
public:
    bool detectCapitalUse(const string& word) {
		// 4ms runtime with 8.3mb storage
        int sz = word.size();
        int caps = calcStringVal(word, sz);
        //first letter is capital
        if (word[0] <= 90)
            return caps == 1 || caps == sz;
        // case where no letters are capital
        else if (word[0] >= 97)
        {
            // there's a capital letter somewhere
            return !caps;
        }
        return false;
    }
    
    int calcStringVal(const string& word, int sz)
    {
        int total(0);
        for (int i = 0; i < sz; ++i)
        {
            total += word[i] <= 90 ? 1 : 0;
        }
        return total;
    }
};