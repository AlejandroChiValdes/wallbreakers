class Solution {
public:
	// runtime 12ms storage 10mb
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)    {
       vector<int> out;
        set<int> u1;
        set<int> u2;
        for (int i = 0; i < nums1.size(); ++i)
        {
            u1.insert(nums1[i]);
        }
        for (int j = 0; j < nums2.size(); ++j)
        {
            u2.insert(nums2[j]);
        }
        
        //pair<set<int>::iterator, bool> res;
        for (auto i : u1)
        {
            if (u2.find(i) != u2.end()) out.push_back(i);
        }

        return out;
    }
    
    
};