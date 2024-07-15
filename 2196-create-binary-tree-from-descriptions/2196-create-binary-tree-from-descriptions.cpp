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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        // Create nodes and track children
        for (const auto& description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            bool isLeft = description[2];

            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
            
            children.insert(childVal);
        }
        
        // Find the root node (the one which is not a child)
        TreeNode* root = nullptr;
        for (const auto& node : nodes) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
                break;
            }
        }
        
        return root;
        
    }
};
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}