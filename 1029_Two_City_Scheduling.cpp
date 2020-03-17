class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        
        // if number of applicants increases in particular city then add that difference to ans
        vector<int> diffA;
        vector<int> diffB;
        
        int ans=0;
        for(auto & c: costs)
        {
            if(c[0]<c[1])
            {
                ans+=c[0];
                diffA.push_back(c[1]-c[0]);
            }
            else
            {
                ans+=c[1];
                diffB.push_back(c[0]-c[1]);
            }
        }
        
        if(diffA.size()>diffB.size())
        {
            sort(diffA.begin(),diffA.end());
            for(int i=0;i<diffA.size()-costs.size()/2;++i)
                ans+=diffA[i];
        }
        
        else if(diffA.size()<diffB.size())
        {
            sort(diffB.begin(),diffB.end());
            for(int i=0;i<diffB.size()-costs.size()/2;++i)
                ans+=diffB[i];
        }
        
        return ans;
       
    }
};