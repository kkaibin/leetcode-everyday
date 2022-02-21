class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>out;
        helper(candidates, target, 0, out, res);
        return res;
    }

    void helper(vector<int>& candidates, int target, int i, vector<int> out, vector<vector<int>>& res){
        if (target==0){
            res.push_back(out);
            return;
        }
        if (target<0) return;

        if (i>=candidates.size()) return;
        //without can[i], target, out
        helper(candidates, target, i+1, out, res);
        //with can[i], target-can[i], out can[i]
        out.push_back(candidates[i]);
        helper(candidates, target-candidates[i], i, out, res);
    }
};
