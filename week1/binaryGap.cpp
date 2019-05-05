class Solution {
public:
    int binaryGap(int N) {
        // 4ms runtime with 8.3mb storage
        if (!( N & (N - 1))) return 0;
        return longestDist(N);
    }
    
    int longestDist(int N)
    {
        int max(0);
        int current(0);
        normalize(N);
        while ( N )
        {
            if ( N % 2 != 0)
            {
                max = current > max ? current : max;
                current = 1;
            }
            else
                ++current;
            
            N = N >> 1;
        }
        return max;
    }
    
    void normalize(int& N)
    {
        // shift number until the least significant digit is a 1
        while ( !(N % 2) ) N = N >> 1;
    }
};