class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int currentPartition = 0;
        vector<set<int>> partitions{ set<int>(), set<int>() };
        queue<int> toVisit;
        set<int> visited;
        set<int> touched;
        int currentNode = 0;
        // populateVisitQueue(toVisit, partitions);
        while (currentNode < graph.size() && !graph[currentNode].size())
            ++currentNode;
        if (currentNode == graph.size())
            return true;
        toVisit.push(currentNode);
        partitions[0].insert(currentNode);
        while (toVisit.size())
        {
            currentNode = toVisit.front();
            toVisit.pop();
            //cout << "currentNode: " << currentNode << endl;
            // our current node will either be in partition 0 or 1. Find which partition our currentNode belongs to.
            currentPartition = partitions[0].find(currentNode) != partitions[0].end() ? 0 : 1;
            if (visited.find(currentNode) != visited.end())
            {
                continue;
            }
            partitions[currentPartition].insert(currentNode);
            // iterate through all neighbors of our current node
            for (int neighbor : graph[currentNode])
            {
                // if neighbor is in current partition, return false
                if (partitions[currentPartition].find(neighbor) != partitions[currentPartition].end())
                    return false;
                // else, add neighbor to opposite partition
                partitions[!currentPartition].insert(neighbor);
                if (touched.find(neighbor) == touched.end())
                    toVisit.push(neighbor);
                touched.insert(neighbor);
            }
            visited.insert(currentNode);
            touched.insert(currentNode);
            if (!toVisit.size() && visited.size() < graph.size())
            {
                //cout << "visit empty." << endl;
                while (currentNode < graph.size() && (!graph[currentNode].size() || !containsUnique(graph[currentNode], touched)))
                    ++currentNode;
                if (currentNode < graph.size())
                {
                    toVisit.push(currentNode);
                    touched.insert(currentNode);
                    partitions[currentPartition].insert(currentNode);
                }
            }
        }
        return true;
    }
    
    bool containsUnique( vector<int> neighbors, set<int> touched )
    {
        for (int neighbor : neighbors)
        {
            if (touched.find(neighbor) == touched.end())
            {
                //cout << "unique neighbor: " << neighbor << endl;
                return true;
            }
                
        }
        return false;
    }
    
//     void populateVisitQueue(queue<int>& toVisit, vector<set<int>>& partitions, vector<vector<int>>& graph)
//     {
//         set<int> visited;
//         for (int i = 0; i < graph.size(); ++i)
//         {
//             // if node has already been touched, don't do anything with it.
            
//             // if node has not been touched, it is a new node 
//         }
//     }
};