class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int,int>> v;
        unordered_map<int,int> mp;
        pair<int,int> p;
        for(int i=0;i<values.size();++i)
        {
            p.first=values[i];
            p.second=labels[i];
            
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),[](auto &a,auto &b){ return a.first>b.first;});
        int result=0;
        for(auto &i: v)
        {
           if(num_wanted==0) 
               break;
            
            if(mp[i.second]<use_limit)
            {
                mp[i.second]++;
                num_wanted--;
                result+=i.first;
            }
            

            
            
        }
        
        return result;
    }
};