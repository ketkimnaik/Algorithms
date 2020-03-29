Optimized Solution:

class Solution {
public:
bool static compare(pair<int,int>&i,pair<int,int>&j)
    {
        return i.second<j.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        vector<pair<int,int>>vect;
        for(int i=0;i<intervals.size();i++)
        {
            vect.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
    sort(vect.begin(),vect.end(),compare);
    vector<int>s;
    vector<int>f;
    for(int i=0;i<vect.size();i++)
    {
        s.push_back(vect[i].first);
        f.push_back(vect[i].second);
    }
    int n = s.size();
    int ans = 1;
    int k =0;
    for(int m=1;m<n;m++)
    {
        if(s[m]>=f[k])
        {
         ans++;
         k = m;
        }
    }
    return s.size()-ans;
    }
};

Brute Force:

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return 0;
        vector<vector<int>> result{};
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0]<result.back()[1])
            {
                result.back()[1]=min(result.back()[1],intervals[i][1]);
            }
            else
                result.push_back(intervals[i]);
                
        }
        
        return intervals.size()-result.size();
    }
};