class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // runtime 144ms storage 47.2mb
		if (s == "" || p.size() > s.size()) return vector<int>{};
        multiset<char> anagram;
        vector<int> result;
        for (int i = 0; i < p.size(); ++i)
        {
            anagram.insert(p[i]);
        }
        // iterate through string. when you hit a character that is located in the 
        // 'anagram' set, you trail off and test if the series of characters starting at i
        // is an anagram. if so, you append that index to the 'anagramStart' array. If not,
        // you move on to the next index.
        // this multiset will store the previous index's result
        multiset<char> last = anagram;
        bool previousIndexIsAnagram = isAnagram(s, 0, p.size(), last);
        if (previousIndexIsAnagram) result.push_back(0);
        for (int i = 1; i <= s.size() - p.size(); ++i)
        {
            int lastItem = i + p.size() - 1;
            if (!previousIndexIsAnagram)
            {
                // this sequence will also not be an anagram
                if (s[lastItem] == s[i - 1])
                    continue;

                else if (last.find(s[lastItem]) != last.end() && last.size() == 1)
                {
                    previousIndexIsAnagram = true;
                }
                last = anagram;
                previousIndexIsAnagram = isAnagram(s, i, i + p.size(), last);
                if (previousIndexIsAnagram)
                {
                    result.push_back(i);
                }
            }
            else
            {
                if (s[lastItem] == s[i - 1])
                {
                    //cout << "other condit. index " << i << endl;
                    //for (auto item : last) cout << item << " ";
                    //cout << " compared to " << s[lastItem] << endl;
                    result.push_back(i);
                }
                else 
                {
                    last = anagram;
                    previousIndexIsAnagram = false;
                }
            }
            
        }
        return result;
    }
    
    bool isAnagram(string& s, int start, int end, multiset<char>& anagram)
    {
        //cout << "index " << start << endl;
        //cout << "comparing ";
        //for (auto i : anagram) cout << i << " ";
        //cout << " with " << s[start] << endl;
        if (end > s.size()) return false;
        for (int i = start; i < end; ++i)
        {
            if (anagram.find(s[i]) == anagram.end())
            {
                //cout << "couldn't find item: " << s[i] << endl;
                return false;
            }
            anagram.erase(anagram.find(s[i]));
        }
        return true;
    }
};