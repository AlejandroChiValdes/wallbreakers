class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 4ms runtime with 8.3mb storage
        if (n <= 0) return false;
        if (n == 1) return true;
        return !(n&(n-1));
    }
};