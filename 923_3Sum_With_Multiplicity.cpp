class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int size = A.size();
        int result = 0;
        int j , k, sum;
        sort(A.begin(), A.end());
        int left, right;
        int mod = 1000000007;
        
        
        for(int  i = 0; i < size - 2; ++i) {
            j = i + 1;
            k = size - 1;
            while(j < k) {
                sum = A[i] + A[j] + A[k];
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    if (A[j] != A[k]){
                        left = 1; right = 1;
                        while (j + 1 < k && A[j + 1] == A[j]) {
                            left++; j++;
                        }
                        while (k - 1 > j && A[k - 1] == A[k]) {
                            right++; k--;
                        }
                        result = (result + left * right) % mod;
                        j++; k--;
                    }else{
                        result = (result + (k - j + 1) * (k - j) / 2) % mod;
                        break;
                    }
                    
                }
            }
        }
        
        return result;
    }
};