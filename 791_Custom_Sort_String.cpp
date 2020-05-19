Brute Force:

class Solution {
public:
    string customSortString(string S, string T) {
        
        if(S.size()==0)
            return T;
        if(T.size()==0)
            return "";
        map<int,char> m;
        unordered_map<char,int> mp;
        for(int i=0;i<S.size();++i)
        {
            m[i]=S[i];
            
        }
        
        for(int i=0;i<T.size();++i)
        {
            mp[T[i]]++;
        }
        
        string result="";
        
        for(auto it=m.begin();it !=m.end();++it)
        {
            if(mp.find(it->second) !=mp.end())
            {
                while(mp[it->second] >0)
                {
                    result+=(it->second);
                    mp[it->second]--;
                }
            }
        }
        
        for(auto it=mp.begin();it !=mp.end();++it)
        {
            if(it->second !=0)
            {
                while(it->second>0)
                {
                result+=(it->first);
                    it->second--;
                }
            }
        }
        
        return result;
        
    }
};

Optimized Solution:

class Solution {
public:
    string customSortString(string S, string T) {
        int n = 26;
        int count[n];
        for(int i= 0 ;i < n ;i++)
        {
           count[i] = 0;
        }
        for(auto c : T)
        {  
            count[c-97]++;   //count frequency of every character in T 
        }
        string ans = "";
        for(auto t: S)    //going through every character in pattern
        {
            while(count[t-97]>0)  //if count of that scanned character greater than 0, loop here and push that character into answer string 
			{
                count[t-97]--;
                ans.push_back(t);
            }
        }
		//printing remaining characters in T.
        for(auto t : T)
        {
            while(count[t-97]>0)     
            {
                count[t-97]--;
                ans.push_back(t);
            }
        }
        return ans;
    }
};