class Solution {
public:
    vector<string> uncommonFromSentences(string& A, string& B) {
        // runtime 8ms, 9.5mb storage
        multiset<string> aOccurrences;
        vector<string> aWords;
        extractString(A, aOccurrences, aWords);
        
        multiset<string> bOccurrences;
        vector<string> bWords;
        extractString(B, bOccurrences, bWords);
        
        vector<string> result;
        for (int i = 0; i < aWords.size(); ++i)
        {
            if (aOccurrences.count(aWords[i]) < 2 && bOccurrences.find(aWords[i]) == bOccurrences.end())
            {
                result.push_back(aWords[i]);
            }
        }
        for (int j = 0; j < bWords.size(); ++j)
        {
            if (bOccurrences.count(bWords[j]) < 2 && aOccurrences.find(bWords[j]) == aOccurrences.end())
            {
                result.push_back(bWords[j]);
            }
        }
        return result;
    }
    
    void extractString(string& in, multiset<string>& out, vector<string>& outStr)
    {
        stringstream s(in);
        string temp;
        while( getline( s, temp, ' ' ) )
        {
            out.insert(temp);
            outStr.push_back(temp);
        }
    }
};