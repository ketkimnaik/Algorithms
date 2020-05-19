class Solution {
public:
    string decodeString(string s) {
        
        stack<int> count;
        stack<string> st;
        int i=0;
        string res="";
        while(i<s.size())
        {
            if(isdigit(s[i]))
            {
                int num=0;
                while(isdigit(s[i]))
                {
                    
                    num=num*10+(s[i]-'0');
                    ++i;
                }
                
                count.push(num);
                
            }
            
            else if(s[i]=='[')
            {
                st.push(res);
                res="";
                ++i;
                
            }
            
            else if(s[i]==']')
            {
                int c=count.top();
                count.pop();
                string a="";
                a+=st.top();
                st.pop();
                for(int i=0;i<c;++i)
                    a.append(res);
                res=a;
                ++i;
            }
            
            else
            {
                res+=s[i];
                ++i;
            }
        }
        return res;
    }
};