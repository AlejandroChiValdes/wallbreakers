class Solution {
public:
    int numJewelsInStones(string& J, string& S) {
        // runtime 0ms storage 8.7mb
        int total(0);
        std::set<char> jewels;
        for (int j = 0; j < J.size(); ++j)
        {
            jewels.insert(J[j]);
        }
        for (int s = 0; s < S.size(); ++s)
        {
            if (jewels.find(S[s]) != jewels.end())
                ++total;
        }
        return total;
    }
};