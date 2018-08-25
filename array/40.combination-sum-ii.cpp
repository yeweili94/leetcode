class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size = candidates.size();
        vector<vector<int>> ret;
        if (size <= 0) {
            return ret;
        }
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(ret, candidates, temp, 0, target);
        return ret;
    }

    void helper(vector<vector<int>>& ret, const vector<int>& candidates,
                vector<int>& temp, int pos, int target) {
        if (target == 0) {
            ret.push_back(temp);
            return;
        }
        if (pos >= candidates.size() || target < 0) {
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i-1]) {
                continue;
            }
            temp.push_back(candidates[i]);
            helper(ret, candidates, temp, i + 1, target - candidates[i]);
            temp.pop_back();
        }
    }
};
