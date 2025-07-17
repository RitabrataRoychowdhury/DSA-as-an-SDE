class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> Q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }
        vector<int> res;
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            res.push_back(top);
            for (auto it : adj[top])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    Q.push(it);
            }
        }
        return res;
    }
};