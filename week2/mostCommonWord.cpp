#include <algorithm>
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // runtime 16ms with 10.8mb of storage
        // extract words from paragraph
        // have a running 'max' value and a corresponding 'maxVal' corresponding
        // to the string with 'max' occurrences
        // iterate over each word in the paragraph
            // add the word to the multiset. if the number of those words
            // is greater than the current max, replace the max and maxVal with
            // the current string
        // return maxVal
        set<string> bannedWords;
        for (int i = 0; i < banned.size(); ++i)
        {
            bannedWords.insert(banned[i]);
        }
        vector<string> words;
        extractWords(paragraph, words);
        int max(0);
        string maxVal("");
        multiset<string> occurrences;
        for (int i = 0; i < words.size(); ++i)
        {
            std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
            // if the word is not banned
            if (bannedWords.find(words[i]) == bannedWords.end())
            {
                occurrences.insert(words[i]);
                int currentCount = occurrences.count(words[i]);
                if ( currentCount > max)
                {
                    max = currentCount;
                    maxVal = words[i];
                }                
            }
        }
        return maxVal;
        
    }
    
    // extracts all the words in the string and places them in the 'out' vector
    void extractWords(string& in, vector<string>& out)
    {
        char* str = const_cast<char*>(in.c_str());
        char* pch = strtok(str, "!?',;. ");
        
        while (pch)
        {
            out.push_back(string(pch));
            pch = strtok(NULL, "!?',;. ");
        }
    }
};