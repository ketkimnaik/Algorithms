class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n,0);
        
        if(n==1)
            return result;
        
        if(n%2)
        {
            result[n/2+1]=0;
            int j=n-1;
            for(int i=0;i<n/2;++i)
            {
                result[i]=i+1;
                result[j]=-1*(i+1);
                j--;
            }
        }
        else
        {
          int j=n-1;
            for(int i=0;i<n/2;++i)
            {
                result[i]=i+1;
                result[j]=-1*(i+1);
                j--;
            }  
        }
       
        return result;
    }
};