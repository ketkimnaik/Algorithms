class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp="";
        st.push(temp);
        for(int i=0;i<s.size();++i)
        {
            if(s[i]>='a' && s[i]<='z')
                st.top()+=s[i];
            
            else if(s[i]=='(')
            {
                st.push(temp);
                
                
            }
            else if(s[i]==')')
            {
                reverse(st.top().begin(),st.top().end());
                string curr=st.top();
                st.pop();
                if(!st.empty())
                    st.top()+=curr;
                else
                    st.push(curr);
            }
                
        }
        
        string result="";
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        
        return result;
    }
};