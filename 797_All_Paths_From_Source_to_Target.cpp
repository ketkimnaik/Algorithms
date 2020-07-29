class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<vector<int>> &result, vector<int> &path, int dest, int node) {
        
        path.push_back(node);
        
        if (node == dest) {
            result.push_back(path);
            return;
        } else {
            for(auto n: graph[node]) {
                DFS(graph, result, path, dest, n);
                path.pop_back();

            }
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result{};
        vector<int> path{};
        int dest = graph.size() - 1;
        
        DFS(graph, result, path, dest, 0);
        
        return result;
        
    }
};