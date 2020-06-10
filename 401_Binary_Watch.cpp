class Solution {
public:
    void Backtracking(string &path, int start, int num, vector<string> &result){
        int hour = bitset<4>(path.substr(6, 4)).to_ulong();
        if(hour > 11)
            return;
        
        int minute = bitset<6>(path.substr(0, 6)).to_ulong();
        if(minute > 59)
            return;
        
        if(num == 0){
            result.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
            return;
        }
        
        if(start == path.length())
            return;
        
        for(int i=start; i < path.size(); ++i){
            path[i] = '1';
            Backtracking(path, i + 1, num - 1, result);
            path[i] = '0';
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> result{};
        if(num > 8)
            return result;
        
        string path="0000000000";
        Backtracking(path, 0, num, result);
        
        return result;
        
    }
};