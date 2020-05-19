class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n=deck.size();
        vector<int> result(n,0);
        sort(deck.begin(),deck.end());
        
        int i=0;
        bool place=true;
        
        while(i<n)
        {
            for(int j=0;j<deck.size();++j)
            {
                if(result[j]==0)
                {
                    if(place)
                    {
                        result[j]=deck[i];
                        i++;
                        place=false;
                    }
                    else
                    {
                        place=true;
                    }
                }
            }
        }
        
        return result;
        
    }
};