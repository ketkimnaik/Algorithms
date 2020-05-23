class Solution {
public:
    struct comp
    {
     bool operator()( const pair<int,string>& a, const pair<int,string>& b)
    {
        return a.first<b.first or(a.first==b.first and a.second>b.second);
    }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int> mp;
        
        for(auto &i: words)
        {
            mp[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        
        for(auto it=mp.begin();it !=mp.end();++it)
        {
            pq.push({it->second,it->first});
            
        }
        
        vector<string> result{};
        
        
        while(k>0)
        {
            
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return result;
    }
};