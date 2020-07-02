Optimized Approach:

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n, 0);
        if(prerequisites.size() == 0) {
            return vector<bool>(queries.size(), false);
        }
        
        for(auto& i : prerequisites ) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<unordered_set<int>> s(n);
        vector<bool> result{};
        
        while(! q.empty()) {
            int temp = q.front();
            q.pop();
            for(auto &i : adj[temp]) {
                if(--indegree[i] == 0) {
                    q.push(i);
                }
                
                s[i].insert(temp);
                for(auto &j : s[temp]) {
                    s[i].insert(j);
                }
            }
        }
        
        for(auto &i : queries) {
            if(s[i[0]].count(i[1])) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};

All test cases pass but TLE:

class Solution {
public:
    bool BFS(int prereq, int course, map<int, vector<int>> &mp, int n) {
        if(mp.find(course) == mp.end() && mp.find(prereq) == mp.end()) return false;
        
        queue<int> q;
        vector<bool> visited(n, false);
        visited[course] = true;
        q.push(course);
        
        while(! q.empty()) {
            int temp = q.front();
            q.pop();
            // cout<< temp<<endl;
            if(temp == prereq) return true;
            
            for(auto &i : mp[temp]) {
                if(visited[i] == true) continue;
                visited[i] = true;
                q.push(i);
            }
        }
        
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<int, vector<int>> mp;
        if(prerequisites.size() == 0) {
            vector<bool> result(queries.size(), false);
            return result;
        }
        
        for(auto &i : prerequisites) {
            mp[i[1]].push_back(i[0]);
        }
        
        vector<bool> result{};
        
        for(auto& i : queries) {
            result.push_back(BFS(i[0], i[1], mp, n));
        }
        
        return result;
        
    }
};