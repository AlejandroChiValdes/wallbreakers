class Solution {
public:
    vector<int> selfDividingNumbers(int& left, const int& right) {
        //4ms runtime with 8.5mb storage
        vector<int> result;
        while ( left <= right)
        {
            if (left % 10 == 0)
            {
                ++left;
                continue;
            }
            if (isSelfDividing(left)) result.push_back(left);
            //cout << 'incremented i' << endl;
            ++left;
        }
        return result;
    }
    
    bool isSelfDividing(const int& current)
    {
        int remainder;
        int leftOver = current;
        while (leftOver > 0)
        {
            
            remainder = (leftOver % 10);
            
            leftOver /= 10;
            // either the number contains a 0 or the number is not divisible
            // by the current digit
            if (!remainder || current % remainder != 0) return false;
        }
        return true;
    }
};