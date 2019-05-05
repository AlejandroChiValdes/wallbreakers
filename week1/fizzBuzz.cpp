class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // 8ms runtime with 10.4mb storage
        vector<string> result;
        for (int i = 1; i <= n; ++i)
        {
            
            result.push_back( i % 15 == 0 ? string("FizzBuzz") :
                i % 5 == 0 ? string("Buzz") :
                i % 3 == 0 ? string("Fizz"):
                intToStr(i) );
        }
        return result;
    }
    
    string intToStr(int i)
    {
        string result;
        int remainder(0);
        int leftOver = i;
        int power = 0;
        while (leftOver > 0)
        {
            remainder = leftOver % 10;
            leftOver = leftOver / 10;
            result += char(remainder + 48);
        }
        reverse(result);
        return result;
    }
    
    void reverse(string& rev)
    {
        int sz = rev.size();
        for (int i = 0; i < sz / 2; ++i)
        {
            swap(rev[i], rev[sz - 1 - i]);
        }
    }
    
    void swap(char& x, char& y)
    {
        char temp = x;
        x = y;
        y = temp;
    }
};