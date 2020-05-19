class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        
        int mn=INT_MAX,sum=0,neg=0;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<0) neg++;
            sum+=abs(A[i]);
            mn=min(mn,abs(A[i]));
        }
        
       int ans; 
        if (K>=neg) 
        {
            if(K==neg) ans=sum;
            if((K-neg)%2==0) ans=sum;
            if((K-neg)%2!=0) ans=sum-2*mn;
        }
        else
        {
            int c=0; int s=0;
            sort(A.begin(),A.end());
            for(int i=0;i<A.size();i++)
            {
                if(c==K)
                {
                    s+=A[i];
                }
                else
                {
                    s+=abs(A[i]); c++;
                }
            }
            ans=s;
        }
        
        return ans;
    }
};