class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string,vector<string>> mp;
        
        vector<vector<string>> res{};
        for(auto& i: paths)
        {
            string pref="";
            int j=0;
            int temp=0;
            for(;j<i.size();++j)
            {
                if(i[j]==' ')
                    break;
                pref+=i[j];
            }
            temp=j+1;
            pref+='/';
            string t="";
            for(;j<i.size();)
            {
                int end;
                if(i[j-1]=='(')
                {
                    end=j-1;
                    while(i[j] !=')')
                    {
                        t+=i[j];
                        j++;
                    }
                    string final=pref+i.substr(temp,end-temp);
                    mp[t].push_back(final);
                    
                t="";
                temp=j+2;
                }
                
                ++j;
            }
        }
        
        for(auto i=mp.begin();i !=mp.end();++i)
        {
            if((i->second).size()>1)
            res.push_back(i->second);
        }
        
        return res;
    }
};