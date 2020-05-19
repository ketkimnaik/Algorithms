class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        int m=A.size();
        int n=A[0].size();
        int f;
        if(n%2)
            f=n/2;
        else
            f=n/2-1;
        for(int i=0;i<m;++i)
        {
            
            int k=n-1;
            for(int j=0;j<=f;++j)
            {
                
                int temp=A[i][j];
                A[i][j]=A[i][k];
                A[i][k]=temp;
                
                
                
                if(A[i][j]==0)
                    A[i][j]=1;
                else
                    A[i][j]=0;
                if(j !=k)
                {
                if(A[i][k]==0)
                    A[i][k]=1;
                else
                    A[i][k]=0;
                }  
                k--;
            }
            
        }
       return A; 
    }
};