class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a=s.size() ,b=t.size();
        if(a==0)
            return true;
        if(a>b)
            return false;
        
        for(int i=0,j=0;i<b;i++)
        {
            if(s[j]==t[i])
                ++j;
            
            if(j == a)
                return true;
        }
        
        return false;
    }
};