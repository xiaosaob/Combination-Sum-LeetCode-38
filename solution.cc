// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, sol, res);
        return res;
    }
    
    void helper(vector<int> &candidates, int target, int startIdx, vector<int> &sol, vector<vector<int> > &res) {
        if(target == 0) {
            res.push_back(sol);
            return;
        }
        
        for(int i = startIdx; i < candidates.size(); ++i) {
            if(candidates[i] > target) return;
            sol.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, sol, res);
            sol.pop_back();
        }
    }
};
