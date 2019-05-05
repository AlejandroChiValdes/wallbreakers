class Solution {
public:
    int findComplement(int num) {
        if (num <= 1) return !num;
        int mask = findMask(num);
        return num^mask;
    }
    
    int findMask(int num)
    {
        unsigned int mask = 1;
        int currentPow = 0;
        // iterate until we find the power
        // of two that's greater or equal to
        //the current number
        while (mask <= num)
        {
            mask *= 2;
            ++currentPow;
        }
        if (mask == num)
        {
            return pow(2, currentPow + 1) - 1;
        }
        return mask - 1;
    }
};