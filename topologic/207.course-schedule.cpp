class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int size = prerequisites.size();
        vector<vector<int>> graph(numCourses, vector<int>(0));  //邻接表
        vector<int> in(numCourses, 0);  //入度
        vector<int> ret;
        for (const auto& elem : prerequisites) {
            graph[elem.second].push_back(elem.first);
            in[elem.first]++;
        }
        queue<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                queue.push(i);
            }
        }
        while (!queue.empty()){
            int tmp = queue.front();
            queue.pop();
            for (const auto& elem : graph[tmp]) {
                in[elem]--;
                if (in[elem] == 0) {
                    queue.push(elem);
                }
            }
            ret.push_back(tmp);
        }
        if (ret.size() < numCourses) {
            return false;
        }
        return true;
    }
};
