class Solution {
public:
    int getKth(int lo, int hi, int k) {
        
        if(lo==hi)
            return k==1?lo:0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=lo;i<=hi;++i)
        {
            int j=i;
            int count=0;
            while(j !=1)
            {
                if(j%2==0)
                {
                    j/=2;
                    count++;
                }
                else
                {
                    j=j*3+1;
                    count++;
                }
            }
           
            pq.push(make_pair(count,i));
        }
        int count=1;
        while(count !=k)
        {
            pq.pop();
            count++;
        }
        
        pair<int,int> top=pq.top();
        return top.second;
    }
};