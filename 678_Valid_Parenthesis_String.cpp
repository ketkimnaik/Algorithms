Solution 1 using 2 stacks:

class Solution {
public:
    bool checkValidString(string s) {
        
        int n=s.size();
        
        stack<int> s1,s2;
        
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
                s1.push(i);
            else if(s[i]=='*')
                s2.push(i);
            else
            {
                if(!s1.empty())
                    s1.pop();
                else if(!s2.empty())
                    s2.pop();
                else
                    return false;
            }
        }
        
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top()>s2.top())
                return false;
            
            s1.pop();
            s2.pop();
        }
        
        return s1.empty();
        
    }
};


optimized Solution:

class Solution {
public:
    bool checkValidString(string s) {
        
        int n=s.size();
        
        int open=0,close=0;
        
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(' || s[i]=='*')
                open++;
            else
                open--;
            
            if(s[n-1-i]==')' || s[n-1-i]=='*')
                close++;
            else
                close--;
            
            if(open<0 || close<0)
                return false;
                
        }
        
        
        
        return true;
        
    }
};