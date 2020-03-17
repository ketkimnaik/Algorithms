class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        //find position is even or odd
        vector<int> count(2,0);
        for(int i=0;i<chips.size();++i)
        {
           if(chips[i]%2==0)
               count[0]++;
            else
                count[1]++;
        }
        //if even positions are more then return count of odd position and vice versa
        if(count[0]>count[1])
            return count[1];
        return count[0];
    }
};