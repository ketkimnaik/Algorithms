class Solution {
public:
    string dectobinary(int a)
    {
        string res="";
        
        while(a>0)
        {
            res+=to_string(a%2);
            a/=2;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
    bool queryString(string S, int N) {
        
        int size=S.size();
        
        int a=log2(N);
        
        if(pow(2,a)-N==0)
            a=a+1;
        
        if(size<a)
            return false;
        
        for(int i=N;i>=N/2;--i)
        {
            string temp=dectobinary(i);
            
            if(S.find(temp)==string::npos)
                return false;
        }
        
        
        return true;
        
        
    }
};