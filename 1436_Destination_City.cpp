class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        string res="";
        for(auto& i:paths)
        {
            mp[i[0]]++;
            if(mp[i[1]]>0)
                continue;
            else
                mp[i[1]]=0;
        }
        
        for(auto it=mp.begin();it !=mp.end();++it)
        {
            if(it->second==0)
            {
               res=it->first; 
                break;
            }
        }
        
        return res;
        
    }
};