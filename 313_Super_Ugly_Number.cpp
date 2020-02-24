class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int k=primes.size();
        if(n<=0)
            return 0;
        else if(n==1)
            return 1;
        
        vector<int> index(k,0);
        vector<int> result(n);
        result[0]=1;
        
        for(int i=1;i<n;i++)
        {
            result[i]=INT_MAX;
            for(int j=0;j<k;j++)
            {
                result[i]=min(result[i],result[index[j]]*primes[j]);
            }
            for(int j=0;j<k;j++)
            {
            
            if(result[i]==result[index[j]]*primes[j])
            {
                index[j]++;
            }
            }
                
        }
            
          return result[n-1];  
        
    }
};