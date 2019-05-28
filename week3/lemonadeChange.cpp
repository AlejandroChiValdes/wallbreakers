class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // R(n) = R(n - 1) - bills[n]
        // R(0) = 
        
        //vector<int> change(bills.size(), 0);
        map<int, int> change;
        if (bills[0] > 5 || !bills.size()) return false;
        change[5]++;
        for (int i = 1; i < bills.size(); ++i)
        {
            if (!makeChange(change, bills[i] - 5))
            {
                return false;
            }
            change[bills[i]]++;
        }
        return true;
    }
    
    bool makeChange(map<int,int>& change, int total)
    {
        int amts[3] = {20, 10, 5};
        for (int i = 0; i < 3; ++i)
        {
            while (total - amts[i] >= 0 && change[amts[i]])
            {
                total -= amts[i];
                --change[amts[i]];
            }
        }
        return total == 0;
    }
};