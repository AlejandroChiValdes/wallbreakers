class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // runtime 4ms storage 8.9mb
        
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // keep track of the number of unique string solutions
        int numUnique(0);
        // used to compare strings to decide which ones are unique
        set<string> unique;
        for (int i = 0; i < words.size(); ++i)
        {
            string current("");
            // build up morse string
            for (int chr = 0; chr < words[i].size(); ++chr)
            {
                // since all letters are lowercase, you can index the 'morse'
                // array by taking the current character and subtracting it by
                // 97, which is the value of lowercase 'a'
                current += morse[words[i][chr] - 97];
            }
            // attempt to insert string into set; check if the insertion was
            // successful. If it was, then the string was unique. Increment
            // uniqueCount
            pair<set<string>::iterator, bool> isUnique = unique.insert(current);
            if (isUnique.second)
                ++numUnique;
        }
        
        return numUnique;
    }
};