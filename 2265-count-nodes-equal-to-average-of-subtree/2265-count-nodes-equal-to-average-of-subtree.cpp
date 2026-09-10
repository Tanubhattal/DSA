class Solution {
    int count = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0}; 
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int currentSum = root->val + left.first + right.first;
        int currentNodes = 1 + left.second + right.second;
        if (root->val == currentSum / currentNodes) {
            count++;
        }
        return {currentSum, currentNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};