class Solution {
public:
    int minDistance(string word1, string word2) {
       int m=word1.size();
        int n=word2.size();
        vector<vector<int>> result(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=m;++i)
       
            result[0][i]=i;
            
        
        
        for(int i=0;i<=n;++i)
        
            result[i][0]=i;
    
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int diff=0;
                if(word2[i-1] != word1[j-1] )
                    diff=1;
                result[i][j]=min(min(1+result[i-1][j],1+result[i][j-1]),diff+result[i-1][j-1]);
                
            }
           
        }
        
        
        
        return result[n][m];
    }
};