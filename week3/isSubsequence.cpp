class Solution {
public:
    bool isSubsequence(string s, string t) {
        string result;
        int curIndex(0);
        for (int chr = 0; chr < s.size(); ++chr)
        {
            int traverseIndex(curIndex);
            while (traverseIndex < t.size() && t[traverseIndex] != s[chr])
            {
                ++traverseIndex;
            }
            if (traverseIndex >= t.size())
            {
                //cout << "exited" << endl;
                break;
            }
                
            result += t[traverseIndex];
            curIndex = traverseIndex + 1;
        }
        //cout << result << endl;
        return result == s;
    }
};