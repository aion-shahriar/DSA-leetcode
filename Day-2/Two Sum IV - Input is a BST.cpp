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
    // Helper function to perform inorder traversal (Left -> Root -> Right)
    // It stores the BST elements in sorted order inside 'arr'
    void Inorder(TreeNode* node, vector<int>& arr) {
        if (node == NULL) return;
        Inorder(node->left, arr);   // Visit left subtree
        arr.push_back(node->val);   // Store node value
        Inorder(node->right, arr);  // Visit right subtree
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;  // Stores inorder traversal values (sorted)
        Inorder(root, arr);

        int l = 0;  
        int r = arr.size() - 1;

        // Two-pointer approach to find if any two numbers sum up to 'k'
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == k) return true;  // Found the required pair
            else if (sum < k) l++;      // Increase sum by moving left pointer
            else r--;                   // Decrease sum by moving right pointer
        }
        return false;  // No such pair found
    }
};
