class Solution {
    
    void DFS(string s,int ind, int step,string path,vector<string> &result)
    {
        //base condition
        if(ind==s.size() && step==4)//if already ip is formed then add that to result
        {
            //remove last .
            path.erase(path.end()-1);
            result.push_back(path);
            return;
        }
        
        //induction condition
        
        if(s.size()-ind>((4-step)*3))//atmost 12 characters are possible
            return;
        if((s.size()-ind)<(4-step))
           return;
        
        int num=0; 
        for(int i=ind;i<ind+3;++i)
           {
               //form number from string
               num=num*10+(s[i]-'0');
            
               if(num<=255)
               {
                   path+=s[i];
                   DFS(s,i+1,step+1,path+'.',result);
               }
               
               if(num==0)
                   break;
           }
           
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result{};
        if(s.length()==0)
            return result;
        string path="";
        DFS(s,0,0,path,result);
        return result;
      
    }
};