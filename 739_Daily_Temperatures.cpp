class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
       
        int n=T.size();
         vector<int> result(n,0);
        
        for(int i=0;i<n;++i)
        {
            
            while(!s.empty() && T[s.top()]<T[i])
            {
                int j=s.top();
                s.pop();
                result[j]=i-j;
                
            }
            
            s.push(i);
        }
        
        return result;
    }
};