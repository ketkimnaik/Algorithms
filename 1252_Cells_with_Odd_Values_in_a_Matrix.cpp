class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        vector<vector<int>> result(n,vector<int> (m,0));
        for(int i=0;i<indices.size();++i)
        {
            for(int j=0;j<m;j++)
                result[indices[i][0]][j]+=1;
            for(int j=0;j<n;++j)
                result[j][indices[i][1]]+=1;
        }
        
        int sum=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(result[i][j]%2)
                    sum+=1;
            }
        }
        
        return sum;
    }
};