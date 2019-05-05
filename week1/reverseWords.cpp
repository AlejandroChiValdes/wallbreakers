class Solution {
public:
    string reverseWords(string s) {
        // 28ms runtime with 16.3mb storage
        if (s == "") return s;
        stringstream sstream(s);
        string temp;
        string newS;
        while (getline(sstream, temp, ' '))
        {
            reverse(temp);
            newS += temp + ' ';
        }
        newS.pop_back();
        return newS;
    }
    
    template
        <typename T>
    void reverse(T& toRev)
    {
        for (int i = 0; i < toRev.size() / 2; ++i)
        {
            swap(toRev[i], toRev[toRev.size() - 1 - i]);
        }
    }
};