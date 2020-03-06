class Solution {

    unordered_map<char,string> mp;
	vector<string> result;
public:

	void dfs(string& digits, int ind, string str){
		if(ind==digits.size()){
			result.push_back(str);
            return;
		}
		for(auto& a:m[digits[ind]]){
			if(a=='1') continue;
			dfs(digits,index+1,path+a);
		}
	}
	vector<string> letterCombinations(string digits) {
		if(digits.size()==0) return ans;
		mp['2']="abc";
		mp['3']="def";
		mp['4']="ghi";
		mp['5']="jkl";
		mp['6']="mno";
		mp['7']="pqrs";
		mp['8']="tuv";
		mp['9']="wxyz";
		dfs(digits,0,"");
		return result;
	}
};
