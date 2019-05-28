class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)     {
        // solved in 11 min
        sort(g.begin(), g.end());
        sort(s.begin(), s.end(), [=](int x, int y) {return x > y;});
        // for (auto i : g) cout << i << " ";
        // cout << endl;
        // for (auto j : s) cout << j << " ";
        // cout << endl;
        // stack of cookies
        stack<int, vector<int>> cookies(s);
        
        int satisfied(0);
        for (int child = 0; child < g.size(); ++child)
        {
            if (!cookies.size()) break;
            int currentCookie = -1;
            while (g[child] > currentCookie && cookies.size())
            {
                currentCookie = cookies.top();
                cookies.pop();
            }
            //cout << g[child] << " " << currentCookie << endl;
            if (g[child] <= currentCookie)
            {
                ++satisfied;
            }
        }
        return satisfied;
        
    }
};