class Solution {
public:
    int firstUniqChar(string s) {
		// runtime 76ms storage 13.1mb
        // game plan:
        // firs iteration - place all characters along with the number of their occurrences in the map
        // second iteration - check each character to see how many times it occurred in the string. If it occurred only once, return the index. once you reach the end, return -1
        map<char, int> occurrences;
        
        for (int i = 0; i < s.size(); ++i)
        {
            ++occurrences[s[i]];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (occurrences[s[i]] == 1)
            {
                return i;
            }
        }
     
        return -1;
    }
};