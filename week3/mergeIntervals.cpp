class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // solved in 10 min
        vector<vector<int>> result;
        if (!intervals.size()) return result;
        sort(intervals.begin(), intervals.end(), [=] (vector<int> x, vector<int> y) { return x[0] < y[0];});
        int curStart(intervals[0][0]);
        int curEnd(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= curEnd)
            {
                curEnd = intervals[i][1] > curEnd ? intervals[i][1] : curEnd;
            }
            else
            {
                result.push_back(vector<int> {curStart, curEnd});
                curStart = intervals[i][0];
                curEnd = intervals[i][1];
            }
        }
        result.push_back(vector<int> {curStart, curEnd});
        return result;
    }
};