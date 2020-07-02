class Solution {
public:
    double BFS(string nr, string dr, map<string, vector<pair<string, double>>> &mp) {
        if(mp.find(nr) == mp.end() || mp.find(dr) == mp.end()) {
            return -1.0;
        }
        
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        visited.insert(nr);
        q.push(make_pair(nr, 1.0));
        
        while(! q.empty()) {
            string temp = q.front().first;
            double num = q.front().second;
            q.pop();
            
            if(temp == dr) return num;
            
            for(auto &i : mp[temp]) {
                if(! visited.count(i.first)) {
                    visited.insert(i.first);
                    q.push({i.first, i.second * num});
                }
            }
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> mp;
        int j= 0;
        for(auto &i : equations) {
            mp[i[0]].push_back(make_pair(i[1], values[j]));
            mp[i[1]].push_back(make_pair(i[0], 1.0 / values[j]));
            j++;
        }
        
        vector<double> result{};
        for(auto &i : queries) {
            result.push_back(BFS(i[0], i[1], mp));
        }
        
        return result;
    }
};