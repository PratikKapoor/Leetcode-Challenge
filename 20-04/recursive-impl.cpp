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
    TreeNode* construct(vector<int>& preorder, int start, int end) {
        if(start>end) {
            return NULL;
        }
        
        int root = preorder[start];
        TreeNode* rootNode = new TreeNode(root);
        
        // Find first element which in the array which is greater than root.
        int pivot = start + 1;
        while(pivot<preorder.size() && preorder[pivot] <= root) {
            pivot += 1;
        }
        
        // Recurse for left and right subtrees.
        rootNode->left = construct(preorder, start+1, pivot-1);
        rootNode->right = construct(preorder, pivot, end);
        
        return rootNode;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size()-1);
    }
};
