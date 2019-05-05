class Solution {
public:
    bool isAnagram(string s, string t) {
        //24ms runtime with 9.8mb storage
        map<char,int> index;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++i)
        {
            ++index[s[i]];
        }
        for (int j = 0; j < t.size(); ++j)
        {
            if (index.find(t[j]) == index.end() ||
                !index[t[j]]) return false;
            --index[t[j]];
        }
        return true;
    }
};