class Solution {
    
    unordered_map<string,vector<string>> adj;
    unordered_map<string,int> out;
public:
    
    void Eulerian_path(string s,vector<string> &path)
    {
      while(out[s]>0)
      {
          Eulerian_path(adj[s][--out[s]],path);
      }
        
        path.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        if(tickets.size()==0)
            return {};
        
        for(auto & a: tickets)
        {
            adj[a[0]].push_back(a[1]);
            
            ++out[a[0]];
        }
        //sort the destinations in descending order
        
        for(auto & i: adj)
        {
            sort(i.second.begin(),i.second.end(),greater<string>());
        }
        
        vector<string> path;
        
        Eulerian_path("JFK",path);
        reverse(path.begin(),path.end());
        
        return path;
    }
};