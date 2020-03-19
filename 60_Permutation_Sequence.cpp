class Solution {
public:
    string getPermutation(int n, int k) {
        
        //find the factorial of each number till n
        
        vector<int> fact(n+1,1);
        string s="";
        int prod=1;
        for(int i=1;i<=n;++i)
        {
            s.push_back('0'+i);
            
            prod=prod*i;
            
            fact[i]=prod;
        }
        
        k--;// n!=n *n-1! then we just have n-1 groups
        string result="";
        for(int i=1;i<=n;++i)
        {
            int index= k/fact[n-i];
            result.push_back(s[index]);
            s.erase(s.begin()+index);
            k%=fact[n-i];//decide the next group
        }
        
        return result;
    }
};