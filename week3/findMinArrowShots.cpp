class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (!points.size()) return 0;
        sort(points.begin(), points.end(), [=](vector<int> x, vector<int> y) {return x[0] < y[0];});
        int start = points[0][0];
        int end = points[0][1];
        int numProcesses(1); 
        
        for (int i = 1; i < points.size(); ++i)
        {
            int curStart = points[i][0];
            int curEnd = points[i][1];
            //cout << curStart << " " << curEnd << endl;
            // narrow the region from start - end to curStart - end
            start = curStart;
            //cout << curStart << " and " << end << endl;
            if (curStart > end)
            {
                
                ++numProcesses;
                end = curEnd;
            }
            else if (curEnd < end)
            {
                end = curEnd;
            }
        }   
        return numProcesses;
    }
};