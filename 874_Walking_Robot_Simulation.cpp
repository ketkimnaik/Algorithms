class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i,j,k,x;
        unordered_map<int, unordered_set<int>> u;
        for(i = 0; i < obstacles.size(); i++){
            u[obstacles[i][0]].insert(obstacles[i][1]);
        }
        i = 0;
        j = 0;
        x = 0;
        vector<vector<int>> directions ;
        directions.push_back({0,1});//N
        directions.push_back({1,0});//E
        directions.push_back({0,-1});//S
        directions.push_back({-1,0});//W
        int res = 0;
        for(k = 0; k < commands.size(); k++){
            if(commands[k] == -1){
                x = (x+1) % 4;
            }else if(commands[k] == -2){
                x = (x-1 + 4) % 4;
            }else{
                while(commands[k]--){
                    if(u[i + directions[x][0]].count(j + directions[x][1]) != 0){
                        break;
                    }
                    i += directions[x][0];
                    j += directions[x][1];
                    res = max((i*i + j* j),res);
                }
            }
        } 
        return res;
    }
};