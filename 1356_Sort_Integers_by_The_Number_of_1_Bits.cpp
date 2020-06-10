Using built in functions:

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
	/*
	Here, we are taking third comparator parameter for our own function to meet condition of sorting and it will sort according;
	if no. of 1's in a and b are same than comparator function will return true if(a<b) holds true.
	*/
        sort(arr.begin(), arr.end(), [](int a, int b)
             { if(__builtin_popcount(a) < __builtin_popcount(b))return true;      
              else if(__builtin_popcount(a) == __builtin_popcount(b))if(a<b) return true;
              return false;
             });
        
        return arr;
    }
};

without builtin functions:

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int size = arr.size();
        int n;
        vector<pair<int,int>> count(size);
        for(int i = 0; i < size; ++i) {
            int n = arr[i];
            count[i].second = n;
            while(n != 0) {
                n = n & (n - 1);
                (count[i].first)++;
            }
        }
        
        sort(count.begin(), count.end(), [](auto &a, auto &b)
             { if(a.first == b.first)
                 return a.second < b.second;
              else
                  return a.first < b.first;});
        
        for(int i = 0; i < size; ++i)
            arr[i] = count[i].second;
        
        return arr;
    }
};