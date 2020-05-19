class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        if(arr.size()==0)
            return arr;
        
        int maximum=INT_MIN;
        for(int i=arr.size()-1;i>=1;--i)
        {
            int curr=arr[i-1];
            arr[i-1]=max(arr[i],maximum);
            maximum=curr;
        }
        
        arr[arr.size()-1]=-1;
        return arr;
    }
};