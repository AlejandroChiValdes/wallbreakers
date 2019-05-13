class Solution {
public:
	// 8ms runtime 9.1mb storage
    bool wordPattern(string pattern, string str) {
        // split string into an array of words
        // begin to map letters to words. Before you insert a pair, check to see if the current letter already corresponds to a word. If it does, and that word is different from the one you were about to map the letter to, return false
        if (!str.size() || !pattern.size()) return false;
        stringstream s(str);
        vector<string> words;
        string cur;
        // extract words from str and insert into words vector
        while (getline(s, cur, ' '))
            words.push_back(cur);
        int numWords(words.size());
        if (pattern.size() != numWords) return false;
        map<char, string> patternMap;
        set<string> found;
        for (int i = 0; i < numWords; ++i)
        {
            map<char, string>::iterator cur = patternMap.find(pattern[i]);
            // a pair starting with our current pattern character already exists
            if ( cur != patternMap.end())
            {
                // if the existing item isn't equal to our current item, return false
                if (cur->second != words[i])
                    return false;
            }
            // no matching pair was found
            else
            {
                if (found.find(words[i]) != found.end()) return false;
                patternMap[pattern[i]] = words[i];
                found.insert(words[i]);
            }
        }
        return true;
    }
};