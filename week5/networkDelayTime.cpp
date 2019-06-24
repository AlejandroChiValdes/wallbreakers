class Solution {
public:
    int nodesTouched = 0;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // parse our 'times' vector into an adjacency list, described below:
        // key: source node --> int
        // value: dst node + travel time --> pair<int,int>
        
        // algorithm: simple breadth first search starting at node k
        // add all not-yet-visited neighbors to the queue, process them all
        
        // data structures needed:
        // 1. visited set
        // 2. toVisit queue
        // 3. adjacency list
        // 4. total time taken
        
        vector<set<pair<int,int>>> nodeList(N + 1, set<pair<int,int>>());
        
        // parse input into nodeList
        for (vector<int> triplet : times)
        {
            nodeList[triplet[0]].insert(pair<int,int>(triplet[1], triplet[2]));
        }
        int total = 0;
        queue<int> toVisit;
        set<int> visited;
        vector<int> costs(N + 1, std::numeric_limits<int>::max());
        costs[K] = 0;
        costs[0] = 0;
        addNeighborsAndUpdateTotal(K, total, nodeList, toVisit, costs);  
        while(toVisit.size())
        {
            int curNode = toVisit.front();
            // cout << "curNode: " << curNode << endl;
            toVisit.pop();
            addNeighborsAndUpdateTotal(curNode, total, nodeList, toVisit, costs);
        }
        // cout << "nodesTouched: " << nodesTouched << endl;
        int max = 0;
        for (int cost : costs)
        {
            if (cost == std::numeric_limits<int>::max())
                return -1;
            max = cost > max ? cost : max;
        }
        return max;
    }
    
    void addNeighborsAndUpdateTotal(int curNode, int& total, vector<set<pair<int, int>>>& nodeList, queue<int>& toVisit, vector<int>& costs)
    {
        for (pair<int, int> neighbor : nodeList[curNode])
        {
            if (costs[curNode] + neighbor.second < costs[neighbor.first])
            {
                toVisit.push(neighbor.first);
                // if the current path to this neighbor is the fastest one so far, update the neighbor's cost with this new value
                costs[neighbor.first] = costs[curNode] + neighbor.second;  
                //cout << "cost for node: " << neighbor.first << ": " << costs[neighbor.first] << endl;
            }  
        }
    }
};