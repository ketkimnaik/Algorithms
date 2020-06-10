class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s1,s2;
        int u=0, v;
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == "+"){
                //if(s1.size() >=2){
                    u = s1.top();
                    s1.pop();
                    v = s1.top() + u;
                    s2.push(s2.top() + v);
                    s1.push(u);
                    s1.push(v);
                //}
            }
            else if(ops[i] == "C"){
                //if(s1.size() >= 1){
                    s2.top() -= s1.top();
                    s1.pop();
                //}
                
            }
            else if(ops[i] == "D"){
                //if(s1.size() >= 1){
                    s1.push(s1.top() * 2);
                    s2.push(s2.top() + s1.top());
               // }
            }
            else{
                if(s2.empty())
                    s2.push(stoi(ops[i]));
                
                s1.push(stoi(ops[i]));
                if(i > 0)
                    s2.push(s1.top() + s2.top());
                
            }
            
           /* if(! s2.empty())
                cout<<s2.top()<<endl;*/
            
        }
        
        //if(!s2.empty())
            return s2.top();
        //return 0;
    }
};