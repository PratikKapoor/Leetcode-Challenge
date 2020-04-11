/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // To calculate height of a tree.
    int height(TreeNode* node) {
        if(node==NULL) {
            return 0;
        }
        
        return max(height(node->left), height(node->right)) + 1;
    }
    
    // To calculate diameter of a tree.
    int diameter(TreeNode* node) {
        if(node==NULL) {
            return 0;
        }
        
        int left_diameter = diameter(node->left);
        int right_diameter = diameter(node->right);
        
        int left_height = height(node->left);
        int right_height = height(node->right);
        
        // Maximum possible diameter would be max of heights of subtrees, or
        // previously seen diameters.
        return max(left_height + right_height + 1, max(left_diameter, right_diameter));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        
        return diameter(root) - 1;
    }
};
