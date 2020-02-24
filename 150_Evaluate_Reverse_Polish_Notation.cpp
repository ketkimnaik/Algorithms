class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        
        s.push(tokens[0]);
        
        for(int i=1;i<tokens.size();i++)
        {
            s.push(tokens[i]);
            
            
            if(s.top()=="+" || s.top()=="-" || s.top()=="*" || s.top()=="/")
            {
                int a,b,result;
                string op=s.top();
                s.pop();
                a=stoi(s.top());
                s.pop();
                b=stoi(s.top());
                s.pop();
                
                if(op=="+")
                    result=b + a;
                else if(op == "-")
                    result=b - a;
                else if (op == "*")
                    result=b * a;
                else
                    result=b / a;
                
                string r=to_string(result);
                s.push(r);
            }
            
            
        }
        
                return (stoi(s.top()));
        
    }
};