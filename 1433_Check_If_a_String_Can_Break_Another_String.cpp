class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> p(26,0);
        
        for(int i=0;i<s1.size();++i)
        {
            p[s1[i]-'a']++;
            p[s2[i]-'a']--;
        }
        
        bool S1=true,S2=true;
        
        int total=0;
        
        for(auto &i: p)
        {
            total+=i;
            if(total<0)
                S1=false;
            if(total>0)
                S2=false;
            
            if(S1==false && S2==false)
                return false;
        }
        
        return true;
    }
};