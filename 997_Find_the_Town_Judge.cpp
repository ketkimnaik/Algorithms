class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1)
            return 1;
        vector<int> trust2(N+1,0);
        vector<int> trust1(N+1,0);
        
        for(auto& i: trust)
        {
            trust1[i[0]]++;
            trust2[i[1]]++;
        }
        
        auto it=find(trust2.begin(),trust2.end(),N-1);
        if(it !=trust2.end())
        {
           int ind=distance(trust2.begin(),it);
            
            if(trust1[ind]==0)
                return ind;
        }
            return -1;
            
        
    }
};