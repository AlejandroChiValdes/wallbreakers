class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // runtime 12ms storage 9.3mb
        // start with a map of characters
        // iterate through both strings, and map one character to another
        // if you come to an iteration where you hit an already existing pair,
        // check the key's value. if the value is different than the value you
        // were about to insert, return false.
        
        map<char,char> matchesS;
        map<char,char> matchesT;
        for (int i = 0; i < s.size(); ++i)
        {
            if (matchesS.find(s[i]) != matchesS.end())
            {
                if (matchesS[s[i]] != t[i])
                    return false;
            }
            else if (matchesT.find(t[i]) != matchesT.end())
            {
                if (matchesT[t[i]] != s[i])
                    return false;
            }
            else
            {
                matchesS.insert(pair<char,char>(s[i],t[i]));
                matchesT.insert(pair<char,char>(t[i],s[i]));
            }
        }
        return true;
    }
};