class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector <int> count(numCourses);
        
        for(auto i: prerequisites)//adjucency matrix
        {
            graph[i[1]].push_back(i[0]);
            count[i[0]]++;
        }
        
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                if(!count[j])
                    break;
            }
            if(j==numCourses)
                return false;
            
            count[j]--;
            
            for(auto a: graph[j])
            {
                count[a]--;
            }
            
        
        }
        
        return true;
    }
};