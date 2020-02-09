class Solution {
public:
    string simplifyPath(string path) {
        
        int i=0; // to traverse the path
        string curr="";
        stack<string> s;
        path+='/';
        
        while(i<path.size())
        {
            if(path[i]=='/')
            {
                if(!curr.empty())
                {
                    if(curr==".")
                    {
                        //do nothing
                    }
                    
                    else if(curr=="..")
                    {
                       if(!s.empty())
                       {
                           s.pop();
                       }
                    }
                    
                    else
                    {
                        s.push(curr);
                    }
                }
                
                curr.clear();
                i++;
                
            }
            else
            {
                curr+=path[i];
                i++;
            }
        }
        
        string result="";
        while(!s.empty())
        {
            result='/'+s.top()+result;
            s.pop();
        }
        
        if(result.empty())
            result+='/';
        
        return result;
        
    }
};