#include <ctype.h>
class Solution {
public:
    bool isPalindrome(string s) {
        // 16ms runtime and 9.4mb storage
        if (s == "") return true;
        int i = 0;
        int j = s.size() - 1;
        while ( i < j)
        {
            while (isNotLetter(s[i]) && i < j) ++i;
            while (isNotLetter(s[j]) && j > i) --j;
            //if (i > j) return false;
            if (tolower(s[i]) != tolower(s[j])) return false;
            ++i, --j;
        }
        return true;
    }
    
    bool isNotLetter(char a)
    {
        return a < 48 || (a < 65 && a > 57) || (a > 90 && a < 97) || a > 123;
    }
};