class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n=points.size();
        if(n==0)
            return 0;
        
        vector<vector<int>> result{};
        sort(points.begin(),points.end(),[](const auto &a,const auto &b){return a[1]<b[1];});
        
        int j=0;
        result.push_back(points[0]);
        for(int i=1;i<n;++i)
        {
            if(points[i][0]<=result[j][1])
            {
                result[j][1]=min(result[j][1],points[i][1]);
            }
            else
            {
                result.push_back(points[i]);
                j++;
            }
        }
        
        return result.size();
        
    }
};