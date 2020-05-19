Optimized approach:

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> mp(26,0);
        int n=S.length();
         vector<int> result{};
    
        for(int i=0;i<n;++i)
        {
            mp[S[i]-'a']=i;
        }
        
        int start=0, currmax=-1;
       
        for(int i=0;i<n;++i)
        {
            currmax=max(currmax,mp[S[i]-'a']);
            
            if(i==currmax)
            {
                result.push_back(i-start+1);
                start=i+1;
            }
        }
        
        return result;
    }
};

Brute force:

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,pair<int,int>> m;
        vector<int> result{};
        m[S[0]].first=-1;
        for(int i=1;i<S.size();++i)
        {
            
            if(m[S[i]].first ==0)
                m[S[i]].first=i;
            else
                m[S[i]].second=i;
            
        }
        m[S[0]].first=0;
        vector<pair<int,int>> temp;
        int a=0;
        for(auto it=m.begin();it !=m.end();++it)
        {
            //cout<<it->second<<"\n";
           
            temp.push_back(it->second);
            //cout<<"["<<temp[a].first<<","<<temp[a].second<<"]"<<"   ";
            ++a;
        }
        sort(temp.begin(),temp.end());
        //cout<<temp.size()<<"\n";
        vector<pair<int,int>> temp1;
        temp1.push_back(temp[0]);
        int j=0;
        
        for(int i=1;i<temp.size();++i)
        {
            if(temp[i].second==0)
                temp[i].second=temp[i].first;
            if(temp[i].first<temp1[j].second)
            {
                temp1[j].second=max(temp[i].second,temp1[j].second);
            }
            else
            {
                temp1.push_back(temp[i]);
                j++;
            }
        }
        //cout<<temp1.size()<<"\n";
        
        for(int i=0;i<temp1.size();++i)
        {
            result.push_back(temp1[i].second-temp1[i].first+1);
        }
       // cout<<result.size()<<"\n";
        return result;
    }
};