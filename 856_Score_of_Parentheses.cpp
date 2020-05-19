class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        
        for(int i=0;i<S.size();++i)
        {
            if(S[i]==')')
            {
                int sum=0;
                
                while(st.top() !=-1)
                {
                    sum+=st.top();
                    st.pop();
                }
                
                st.pop();
                st.push(max(1,2*sum));
            }
            else
                st.push(-1);
        }
        
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        
    }
};