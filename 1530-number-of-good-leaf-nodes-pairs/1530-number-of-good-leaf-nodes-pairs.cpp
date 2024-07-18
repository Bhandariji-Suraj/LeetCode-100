/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        if (!node->left && !node->right) return {1}; 
        vector<int> left = dfs(node->left, distance, count);
        vector<int> right = dfs(node->right, distance, count);

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }
        vector<int> res;
        for (int l : left) res.push_back(l + 1);
        for (int r : right) res.push_back(r + 1);

        return res;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
        
    }
};