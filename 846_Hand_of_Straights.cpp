class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n=hand.size();
        int div_val=n/W;
        //cout<<div_val;
        if((n%W) !=0)
            return false;
        
        map<int,int> m;
        
        for(int i=0;i<n;++i)
        {
            m[hand[i]]++;
            
        }
        
        for(int i = 0;i<div_val;++i)
        {
            /*int min_val=INT_MAX;
            int max_val=INT_MIN;*/
            
            int temp=W;
            int num;
            for(auto it=m.begin();it != m.end() && temp>0;++it)
            {   
                m[it->first]--;
                if(temp!=W)
                {
                    if((it->first-num) !=1)
                        return false;
                }
                    
                
                num=it->first;
                if(m[it->first]==0)
                    m.erase(it->first);
                    
                temp--;
                
            }
            if(temp !=0)
                return false;
               
        }
        
        return true;
        
    }
};