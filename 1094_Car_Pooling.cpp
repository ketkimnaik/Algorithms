Optimized Solution:

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> m;
        for(auto t:trips){
            m[t[1]] += t[0];
            m[t[2]] -= t[0];
        }
        int cnt = capacity;
        for(auto item:m){
            cnt -= item.second;
            if(cnt < 0) return false;
        }
        return true;
    }
};

Brute force:
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> slot(1001,0);
        
        for(int i=0;i<trips.size();++i)
        {
            for(int j=trips[i][1];j<trips[i][2];++j)
            {
                slot[j]+=trips[i][0];
                //cout<<j<<": "<<slot[j]<<endl;
                if(slot[j]>capacity)
                {
                    //cout<<"hi";
                    return false;
                }
            }
        }
        
        return true;
        
    }
};