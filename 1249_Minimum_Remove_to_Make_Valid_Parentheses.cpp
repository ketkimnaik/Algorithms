class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        string result="";
        int k=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                st.push(result.size());
                result+=s[i];
            }
            
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    result+=s[i];
                    
                    st.pop();
                }
                
                    
            }
            else
                result+=s[i];
            
           
        }
        
        while(!st.empty())
        {
            result.erase(st.top(),1);
            st.pop();
        }
        
        return result;
        
    }
};