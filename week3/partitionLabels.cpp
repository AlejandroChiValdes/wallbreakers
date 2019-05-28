class Solution {
public:
    vector<int> partitionLabels(string s) {
        // solution runtime: O(N)
        // I perform 1 traversal through s, which is O(N) complexity, then I iterate through the key-value pairs, which will be capped at 26 (number of letters in the alphabet), then I sort the regions, which is O(26log(26)), and then I iterate through each region, which is O(26). Overall, the complexity is actually O(N).
        if (s.size() == 1) return vector<int> {1};
        map<char,vector<int>> regions;
        for (int i = 0; i < s.size(); ++i)
        {
            if (regions.find(s[i]) == regions.end())
            {
                regions[s[i]] = vector<int>(2, i);
            }
            else
            {
                regions[s[i]][1] = i;
            }
        }
        
        vector<vector<int>> sortedRegions;
        for (auto pair : regions)
        {
            sortedRegions.push_back(pair.second);
            //cout << pair.first << " " << pair.second[0] << pair.second[1] << endl;
        }
        sort(sortedRegions.begin(), sortedRegions.end(), [=](vector<int> x, vector<int> y) { return x[0] < y[0]; });
        int curStart(sortedRegions[0][0]);
        int curEnd(sortedRegions[0][1]);
        vector<int> result;
        for (vector<int> region : sortedRegions)
        {
            // current region intersects with previous region
            if (region[0] <= curEnd)
            {
                curEnd = region[1] > curEnd ? region[1] : curEnd;
            }
            else
            {
                result.push_back(curEnd - curStart + 1);
                curStart = region[0];
                curEnd = region[1];
            }
        }
        result.push_back(curEnd - curStart + 1);
        
        return result;
        
    }
};