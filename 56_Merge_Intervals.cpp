class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     
        if(intervals.size()==0)
            return intervals;
        
        if(intervals.size()==1)
            return intervals;
        vector<vector<int>> result{};
        
        
        sort(intervals.begin(),intervals.end());
        
         
        for(auto &i : intervals)
        {
            if(!result.empty() && i[0]<=result.back()[1])
            {
                result.back()[1]=max(i[1],result.back()[1]);
            }
           else
           {
                result.push_back(i);
           }
            
        }
        
        return result;
    }
};