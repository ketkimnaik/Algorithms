More Efficient:

class Solution {
public:
    int thirdMax(vector<int>& nums) {
  
            long long int lo  = LLONG_MIN;
            long long int mid = LLONG_MIN;
            long long int hi  = LLONG_MIN;
        
            for (auto n : nums){
                            
                if (n <= lo || n == mid || n == hi ) {
                    continue;
                }
                
                else if (n > hi){
                    lo = mid;
                    mid = hi;
                    hi = n;
                }
                
                else if ( lo < n && n < mid   ){
                    lo = n;
                }
                
                else if ( mid < n && n < hi){
                    lo = mid;
                    mid = n;
                }    
            }
            return (lo == LLONG_MIN) ? int(hi) : int(lo);
    }
};


Brute Force:

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        map<int, int> mp;
        
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        
        
        if(mp.size() < 3) {
            auto it = mp.rbegin();
            return it->first;
        }
        
        int result = 0;
        int count = 0;
        
        for(auto i = mp.rbegin(); i != mp.rend(); ++i) {
            count++;
            // cout << count <<"   "<<i->first<<endl;
            if(count == 3) {
                result = i->first;
                break;
            }
                
        }
        
        return result;
    }
};