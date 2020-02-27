class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int numberOfDigitsWithEven=0;
        for(auto& i:nums){
			
            numberOfDigitsWithEven+=( (int)floor(log10(i))+1 & 1) == 0;
        }
        return numberOfDigitsWithEven;
    }
};