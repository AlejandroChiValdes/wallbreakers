class Solution {
public:
    string reverseVowels(string& s) {
        // 12ms runtime with 10.1mb storage
        if (s == "") return s;
        int i = 0;
        int j = s.size() - 1;
        while ( i < j )
        {
            while ( !isVowel(s[i]) && i < j ) ++i;
            while ( !isVowel(s[j]) && j > i ) --j;
            if (i > j) return s;
            swap(s[i], s[j]);
            ++i, --j;
        }
        return s;
    }
    
    bool isVowel(char a)
    {
        return a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' ||
            a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }
};