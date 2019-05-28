// recursive + memoized solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        vector<int> maxVals(prices.size(), 0);
        maxVals[prices.size() - 1] = prices[prices.size() - 1];
        return findMaxProfit(0, prices.size() - 2, prices, maxVals);
    }
    
    int findMaxProfit(int curMax, int i, vector<int>& prices, vector<int>& maxVals)
    {
        if (i < 0) return curMax;
        // set the current running maximum value up to today
        maxVals[i] = prices[i] > maxVals[i + 1] ? prices[i] : maxVals[i + 1];
        int valueToday = maxVals[i] - prices[i];
        // update the running max if you've found a new max value
        curMax = valueToday > curMax ? valueToday : curMax;
        return findMaxProfit(curMax, i - 1, prices, maxVals);
        
    }
};

// iterative solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        // max(buying today + maxProfit(tomorrow), selling today + maxProfit(tomorrow), maxProfit(tomorrow)
        int largestPrice(prices[prices.size() - 1]);
        int currentMax(0);
        for (int i = prices.size() - 2; i >= 0; --i)
        {
            largestPrice = max(largestPrice, prices[i]);
            currentMax = max(largestPrice - prices[i], currentMax);
        }
        return currentMax;
    }
    
};