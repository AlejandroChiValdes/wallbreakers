class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // 28ms runtime with 10.2mb storage
        int sz = A.size();
        vector<int> result;
        vector<int> odds;
        for (int i = 0; i < sz; ++i)
        {
            if (A[i] % 2 == 0) 
            {
                result.push_back(A[i]);
            }  
            else 
            {
                odds.push_back(A[i]);
            }      
        }
        int oddSz = odds.size();
        for (int cur = 0; cur < oddSz; ++cur)
        {
            result.push_back(odds[cur]);
        }
        return result;
    }
};