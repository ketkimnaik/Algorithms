Brute Force:

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0) return true;
        
        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) return true;
        
        int count = 0;
        int zero_count = 0;
        int start;
        
        if(flowerbed.size() >= 3) {
            if(flowerbed[0] == 0 && flowerbed[1] == 0 && flowerbed[2] == 1) count++;
        }
        
        for(int i = 0; i < flowerbed.size(); ) {
            
            zero_count = 0;
            
            if (flowerbed[i] == 0) {
                start = i;
                while(i < flowerbed.size() && flowerbed[i] == 0) {
                    i++;
                    zero_count++;
                }
            } else {
                i++;
                continue;
            }
            
            if(zero_count > 2) {
                if (zero_count % 2 == 0) {
                    if(i == flowerbed.size() || start == 0) {
                        count += zero_count / 2 ;
                    } else {
                        count += (zero_count / 2 - 1);
                    }
                    
                } else {
                    if(start == 0 && i == flowerbed.size()) {
                        count += zero_count / 2 + 1 ;
                    } else {
                        count += zero_count / 2 ;
                    }
                    
                }
                
            }
            
        }
        
        if(zero_count == 2) {
            count++;
        }
        
        if(count >= n) return true;
        
        return false;
        
    }
};