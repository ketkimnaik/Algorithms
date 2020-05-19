class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end(),[](const auto &a,const auto &b){return a[1]<b[1];});
        
        vector<int> count(100002,0);
        int result;
        
        for(int i=0;i<events.size();++i)
        {
            for(int j=events[i][0];j<=events[i][1];++j)
            {
                if(count[j] !=0)
                    continue;
                count[j]=1;
                ++result;
                break;
            }
        }
        
        return result;
    }
};