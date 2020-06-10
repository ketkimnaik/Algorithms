class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        int index, curr_high, overall_high;
        int count = 0;
        
        sort(clips.begin(), clips.end());
        
        if(clips[0][0] != 0)
            return -1;
        
        for(int i = 0; i < n; ++i) {
            if(clips[i][0] != 0)
                break;
            
            index = i;
            curr_high = clips[i][1];
        }
        
        overall_high = curr_high;
        count++;
        int temp_ind;
        
        while(curr_high < T) {
            for(int i = index; i < n && clips[i][0] <= clips[index][1]; ++i) {
                if(clips[i][1] > curr_high) {
                    curr_high = clips[i][1];
                    temp_ind = i;
                }
            }
            index = temp_ind;
            count++;
            
            if(curr_high <= overall_high)
                return -1;
            overall_high = curr_high;
            
        }
        
        return count;
        
    }
};