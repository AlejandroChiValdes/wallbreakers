class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create a prerequisite list from our edge list
        // start algorithm w/ node containing 0 prerequisites
        // algorithm:
        // remove node's entry from prerequisite list
        // remove node from all other nodes' entries
        // repeat until the prereq list is empty or there are no nodes in the lsit w/ 0 prerequisites. If there are any nodes left in the list, the sequence is impossible
        // i is node, numberOfPrereqs[i] is number of prereqs node i has
        vector<set<int>> prereqs(numCourses, set<int>());
        queue<int> noPrereqs;
        set<int> visited;
        for (vector<int> pair : prerequisites)
        {
            prereqs[pair[1]].insert(pair[0]);
        }
        // add the initial course to the queue
        addToQueue(prereqs, noPrereqs, numCourses, visited);
        while (noPrereqs.size())
        {
            int currentCourse = noPrereqs.front();
            noPrereqs.pop();
            removePrereq(prereqs, currentCourse);
            addToQueue(prereqs, noPrereqs, numCourses, visited);
            //cout << "currentCourse: " << currentCourse << endl;
        }
        return isLegal(prereqs);
    }
    
    // find courses whose prerequisites have been cleared, add them to the queue
    void addToQueue(vector<set<int>>& prereqs, queue<int>& noPrereqs, const int& numCourses, set<int>& visited)
    {
        for (int i = 0; i < numCourses; ++i)
        {
            if (!prereqs[i].size() && visited.find(i) == visited.end())
            {
                noPrereqs.push(i);
                visited.insert(i);
            }
        }
    }
    
    // if a node contains currentCourse as prereq, remove currentCourse from its prereq list
    void removePrereq(vector<set<int>>& prereq, int currentCourse)
    {
        for (int i = 0; i < prereq.size(); ++i)
        {
            
            if (prereq[i].find(currentCourse) != prereq[i].end())
            {
                prereq[i].erase(currentCourse);
            }
        }
    }
    
    bool isLegal(vector<set<int>>& prereqs)
    {
        for (int i = 0; i < prereqs.size(); ++i)
        {
            if (prereqs[i].size())
                return false;
        }
        return true;
    }
};