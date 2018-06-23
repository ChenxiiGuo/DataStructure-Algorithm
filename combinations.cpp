//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> member;
        helper(member, n, k, 1);
        return res;
    }
    void helper(vector<int> member, int n, int k, int index) {
        if (member.size() == k) {
            res.push_back(member);
            return;
        }
        for (int i = index; i <= n; i++) {
            member.push_back(i);
            helper(member, n, k, i + 1);
            member.pop_back();
        }
    }
};