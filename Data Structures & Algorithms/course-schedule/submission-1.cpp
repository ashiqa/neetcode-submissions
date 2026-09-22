class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        int coursesProcessed = 0;
        queue<int> q;

        // build graph
        for (int i = 0 ; i < prerequisites.size(); ++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        // Start BFS from course with no dependency
        for (int i = 0 ; i < numCourses; ++i){
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS
        while (!q.empty()){
            
            int node = q.front();
            q.pop();
            ++coursesProcessed;

            for (int i = 0; i < graph[node].size(); ++i){
                int nextNode = graph[node][i];

                // process this course if all its dependecies are resolved
                if (--indegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        if (coursesProcessed == numCourses){
            return true;
        }
        return false;
    }
};
