class Solution {
public:
    bool Allneedcomplete(vector<int> &needs)
    {
        for(auto& n: needs)
        {
            if(n)
              return false  ;
        }
        
        return true;
    }
    
    bool canuseoffer(vector<int> &deal,vector<int> &needs)
    {
        for(int i=0;i<needs.size();++i)
        {
            if(deal[i]>needs[i])
                return false;
        }
        
        return true;
    }
    
    void UseDeal(vector<int> &deal,vector<int> &needs,bool use, int &current)
    {
        if(use)
        {
            int i=0;
            for(;i<needs.size();++i)
            {
                needs[i]-=deal[i];
            }
            
            current+=deal[i];
            
        }
        else
        {
           int i=0;
            for(;i<needs.size();++i)
            {
                needs[i]+=deal[i];
            }
            
            current-=deal[i]; 
        }
        
        
    }
    
    void DFS(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int &result,int current)
    {
        //base condition
        if(Allneedcomplete(needs))
        {
            result=min(result,current);
            return;
        }
        
        for(auto &deal: special)
        {
            if(canuseoffer(deal,needs))
            {
                UseDeal(deal,needs,true,current);
                DFS(price,special,needs,result,current);
                UseDeal(deal,needs,false,current);
            }
            else
            {
                int individual_sum=0;
                
                for(int i=0;i<needs.size();++i)
                {
                    individual_sum+=needs[i]*price[i];
                }
                current+=individual_sum;
                result=min(result,current);
                current-=individual_sum;
                    
            }
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        int result=0;
        for(int i=0;i<needs.size();++i)
        {
            result+=needs[i]*price[i];
        }
        
        DFS(price,special,needs,result,0);
        return result;
        
    }
};