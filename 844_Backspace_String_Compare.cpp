class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=0;
        while(i<S.size())
        {
            if(i !=0 && S[i]=='#')
            {
                S.erase(i-1,2);
                i--;
            }
            else if(i==0 and S[i]=='#')
                S.erase(0,1);
            else if(S[i] !='#')
                i++;
        }
        
        i=0;
       // cout<<S<<endl;
        while(i<T.size())
        {
            if(i !=0 && T[i]=='#')
            {
                T.erase(i-1,2);
                i--;
            }
            else if(i==0 and T[i]=='#')
                T.erase(0,1);
            else if(T[i] !='#')
                i++;
        }
        
        //cout<<T<<endl;
        
        if(S.compare(T)==0)
            return true;
        
        return false;
        
    }
};