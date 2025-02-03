// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: 207: Course Scheduler
// Approach: BFS and Topological Sort
// TC: O(v + e)
// SC: O(v + e)

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Base Case
        if (numCourses == 0)
        {
            return true;
        }

        vector<int> indegrees(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        queue<int> q;
        int count = 0;

        // Build the graph and count indegrees
        for (const auto &prereq : prerequisites)
        {
            int to = prereq[0];
            int from = prereq[1];
            indegrees[to]++;
            graph[from].push_back(to);
        }

        // Push courses to queue with no prerequisites
        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
            {
                count++;
                q.push(i);
            }
        }

        // BFS / Topological Sort
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (graph.find(curr) == graph.end())
            {
                continue;
            }
            for (int next : graph[curr])
            {
                indegrees[next]--;
                if (indegrees[next] == 0)
                {
                    count++;
                    q.push(next);
                }
            }
        }

        return count == numCourses;
    }
};
