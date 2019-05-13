class Solution {
public:
    string frequencySort(string s) {
		// runtime 168ms storage 38mb
        // 1. determine the number of occurrences for each character
        // 2. sort those numbers by size
        
        // game plan: use a map<int,set<int>>? when you find a new occurrence of a character you remove it from its previous location and add it to its new one
        
        map<int, set<char>> sortedOccurrences;
        map<char, int> totalOccurrences;
        int maxSize(1);
        //set<int> numsToCheck;
        for (int i = 0; i < s.size(); ++i)
        {
            // how do you know what a character's previous location was?
            // remove item from its current location in sorted
            // increment item's count in totalOccurrences
            // add item to its new location in sorted
            
            // if item has not been seen before
            if (!totalOccurrences[s[i]])
            {
                // increment its count in totalOcc
                ++totalOccurrences[s[i]];
                // add it to the sortedOcc set
                sortedOccurrences[1].insert(s[i]);
                //numsToCheck.insert(1);
            }
            else
            {
                sortedOccurrences[totalOccurrences[s[i]]].erase(s[i]);
                ++totalOccurrences[s[i]];
                sortedOccurrences[totalOccurrences[s[i]]].insert(s[i]);
                maxSize = totalOccurrences[s[i]] > maxSize ? totalOccurrences[s[i]] : maxSize;
            }
        }
        string result("");
        for (int i = maxSize; i > 0; --i)
        {
            // if there are characters with this number of occurrences
            if (sortedOccurrences.find(i) != sortedOccurrences.end())
            {
                // iterate through all the characters with this number of occurrences
                for (char letter : sortedOccurrences[i])
                {
                    for (int k = 0; k < i; ++k)
                    {
                        result += letter;
                    }
                }
            }
        }
        return result;
    }
};