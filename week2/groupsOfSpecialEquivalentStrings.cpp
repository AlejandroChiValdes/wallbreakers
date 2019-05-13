class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        // runtime 28ms storage 19.7mb
        
        // for every string, we want to know if has the same odd-numbered indices as other strings and even-numbered indices as other strings
        // if this condition is met, they're special equivalent and they should be put in the same group.
        // how to match word groups to their entry conditions? you need two separate sets for each word group, and the word group itself is a set
        
        // create a map, key = pair of sets, value = set of words of which comprise the 'group'
        
        // game plan: 
        // 1. split string into odd-and-even-numbered sets
        // 2. put those sets into a pair, index the pair & see if you get any hits
        // 3. If you get a hit, insert your word into the corresponding value set, if not, then you create a new key-value pair.
        
        // dang, you don't even need a map to do the checking, you can just have a set of pair<multiset<char>,multiset<char>> and for every word, insert its pair into the set. if it has a unique pair, it will increase the size of the set, and if not (aka it's a duplicate) the size of the set will stay the same. then just count up the size of the set and voila.
        
        set<pair<vector<char>, vector<char>>> groups;
        int numGroups(0);
        for (int i = 0; i < A.size(); ++i)
        {
            vector<char> oddSet;
            vector<char> evenSet;
            string current = A[i];
            for (int j = 0; j < current.size(); j += 2)
                evenSet.push_back(current[j]);
            for (int k = 1; k < current.size(); k += 2)
                oddSet.push_back(current[k]);
            pair<vector<char>, vector<char>> group(evenSet, oddSet);
            groups.insert(group);
        }
        return groups.size();
        
    }
};