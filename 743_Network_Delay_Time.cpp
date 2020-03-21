class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        if(times.size()==0 || N==0)
            return 0;
        
        vector<int> delay(N+1,INT_MAX);
        delay[K]=0;
        
        for(int i=0;i<N-1;++i)
        {
            bool flag=false;
            
            for(auto &t:times)
            {
                if(delay[t[0]] ==INT_MAX)
                {
                    continue;
                }
                 
                int newdelay=delay[t[0]]+t[2];
                
                if(newdelay<delay[t[1]])
                {
                    delay[t[1]]=newdelay;
                    flag=true;
                }
            }
            
            if(!flag)
                break;
        }
        
        int result=INT_MIN;
        
        for(int i=1;i<=N;i++)
        {
            result=max(result,delay[i]);
        }
        
        return result==INT_MAX?-1:result;
        
    }
};