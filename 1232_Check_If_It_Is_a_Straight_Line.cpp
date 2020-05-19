class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int count=0;
        float y=coordinates[0][1]-coordinates[1][1];
        float x=coordinates[0][0]-coordinates[1][0];
        float slope=0;
        if(x==0)
            count++;
        else
            slope=y/x;
        
        for(int i=1;i<coordinates.size()-1;++i)
        {
            float a=coordinates[i][1]-coordinates[i+1][1];
            float b=coordinates[i][0]-coordinates[i+1][0];
            
            if(b==0 && slope==0)
            {
                count++;
                continue;
            }
            
            if(slope != (a/b))
                return false;
                
            
        }
        
        if(x==0 && count!=coordinates.size()-1)
            return false;
        
        return true;
        
        
    }
};