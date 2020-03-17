class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> st;
        st.push(s[0]);
        int n=s.size();
        int i=1;
        int count=0;
        while(i<n)
        {
            if(st.empty())
            {
                st.push(s[i]);
                count+=1;
            }
            else
            {
            if(s[i]=='L' && st.top()=='R')
            {
                
                st.pop();
            }
            else if(s[i]=='R' && st.top()=='L')
            {
                
                st.pop();
            }
                else
                {
                    st.push(s[i]);
                }
                
                
            }
            
            i++;
        }
        
        return count+1;
    }
};