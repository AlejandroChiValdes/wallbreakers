class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        topological sort:
queue to hold current items with 0 prerequisites
adjacency list to keep track of all nodes w/ their respective prerequisites
visited set to make sure you don't insert duplicate nodes into the queue

algorithm:
search for first item with no prereqs, add it it visited and queue
search for all courses that have current item as prereq, remove the course from the prereq list
perform another search for courses with 0 prereqs, if they haven't been visited before add them to the queue
rinse and repeat

if there are no courses with prereqs left in the adjacency list, return true. else, false.
    */
        queue<int> q;
        set<int> visited;
        // initialize set to contain numCourses empty sets.
        vector<set<int>> nodeList(numCourses, set<int>());
        vector<int> result;
        for (vector<int> pair : prerequisites)
        {
            nodeList[pair[0]].insert(pair[1]);
        }
        // if the course sequence is legal, return our resulting course sequence, else return an empty vector
        addCoursesToQueue(q, visited, nodeList, result);
        while (q.size())
        {
            int currentCourse = q.front();
            q.pop();
            // add current course to our resulting course ordering
            result.push_back(currentCourse);
            // remove course from all prerequisite lists
            removePrereq(currentCourse, nodeList);
            // current course has now been visited
            // visited.insert(currentCourse);
            // cout << "inserted " << currentCourse << " into the visited set" << endl;
            // add newly freed courses to the queue
            addCoursesToQueue(q, visited, nodeList, result);
        }
        return isLegal(nodeList) ? result : vector<int>(); 
    }
    
    //function to add all unvisited courses with 0 prerequisites to the queue
    void addCoursesToQueue(queue<int>& q, set<int>& visited, vector<set<int>>& nodeList, vector<int> result)
    {
        for (int i = 0; i < nodeList.size(); ++i)
        {
            // if a node doesn't have any prerequisites and has not been visited yet
            if (!nodeList[i].size() && visited.find(i) == visited.end())
            {
                // add node to queue
                cout << "added course: " << i << "to q" << endl;
                q.push(i);
                visited.insert(i);
            }
        }
    }
    // function to remove a course from all prerequiste lists
    void removePrereq(int course, vector<set<int>>& courseLists)
    {
        for (int i = 0; i < courseLists.size(); ++i)
        {
            courseLists[i].erase(course);
        }
    }
    
    // function to check if the course sequence is possible
    bool isLegal(vector<set<int>>& courseLists)
    {
        for (set<int> courseList : courseLists)
        {
            if (courseList.size())
                return false;
        }
        return true;
    }
};