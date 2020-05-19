class Solution {
public:
    int distance(vector<int> a,vector<int> b)
    {
        return (abs(a[0]-b[0])+abs(a[1]-b[1]));
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<int>> temp(8);//for 8 directions
        
        for(auto &i: queens)
        {
            //left direction
            if(king[0]==i[0] && king[1]>i[1])
            {
                if(temp[3].size()==0 || distance(temp[3],king)>distance(i,king))
                    temp[3]=i;
            }
            
            //right direction
            if(king[0]==i[0] && king[1]<i[1])
            {
                if(temp[4].size()==0 || distance(temp[4],king)>distance(king,i))
                    temp[4]=i;
            }
            
            //up direction
            
            if(king[1]==i[1] && king[0]>i[0])
            {
                if(temp[1].size()==0 || distance(temp[1],king)>distance(king,i))
                    temp[1]=i;
            }
            
            //down direction
            
            if(king[1]==i[1] && king[0]<i[0])
            {
                if(temp[6].size()==0 || distance(temp[6],king)>distance(king,i))
                    temp[6]=i;
            }
            
            //up-left direction
            
            if(king[0]-i[0]==king[1]-i[1] && king[0]>i[0])
            {
                if(temp[0].size()==0 || distance(temp[0],king)>distance(king,i))
                    temp[0]=i;
            }
            
            //down-right direction
            
            if(king[0]-i[0]==king[1]-i[1] && king[0]<i[0])
            {
                if(temp[7].size()==0 || distance(temp[7],king)>distance(king,i))
                    temp[7]=i;
            }
            
            //up-right direction
            if(king[0]-i[0]==-(king[1]-i[1]) && king[0]>i[0])
            {
                if(temp[2].size()==0 || distance(temp[2],king)>distance(king,i))
                    temp[2]=i;
            }
            
            //down-left direction
            if(king[0]-i[0]==-(king[1]-i[1]) && king[0]<i[0])
            {
                if(temp[5].size()==0 || distance(temp[5],king)>distance(king,i))
                    temp[5]=i;
            }
            
        }
        
        vector<vector<int>> result{};
        for(auto &i: temp)
        {
            if(i.size())
                result.push_back(i);
                
        }
        
        return result;
        
    }
};