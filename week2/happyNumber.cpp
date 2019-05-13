class Solution {
public:
    bool isHappy(int n) {
        //runtime 4ms storage 8.6mb
        // compute the sum of squares of the number's digits.
        // Then attempt to find the number in the number map. If you find
        // it, that means that you've entered a cycle and you should return
        // false. Else, repeat the process for this new number.
        set<int> isCycle;
        return foundHappy(n, isCycle);
    }
    
    bool foundHappy(int n, set<int>& isCycle)
    {
        int result = sumOfSquares(n);
        if (result == 1)
            return true;
        else if (isCycle.find(result) != isCycle.end())
            return false;
        else
        {
            isCycle.insert(result);
            return foundHappy(result, isCycle);
        }
            
    }
    
    int sumOfSquares(int n)
    {
        int total(0);
        int current(n);
        while(current != 0)
        {
            total += pow(current % 10, 2);
            current = current / 10;
        }
        return total;
    }
};