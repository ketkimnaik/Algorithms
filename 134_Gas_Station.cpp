class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int index=0,sum=0,current_sum=0;
        for(int i=0;i<gas.size();++i)
        {
            gas[i]-=cost[i];
            sum+=gas[i];
            current_sum+=gas[i];
            
            if(current_sum<0)
            {
                current_sum=0;
                index=i+1;
            }
        }
        
        return sum<0?-1:index;
    }
};