/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(a, b) {
    if (a > b)
        return a;
    else
        return b;
}

int maxDepth(struct TreeNode* root){
    int h1=0, h2=0;
    
    /* base case */
    if (!root) 
        return 0;
   
    if (root->left)
        h1 = maxDepth(root->left);
    if (root->right)
        h2 = maxDepth(root->right);
    
    return (max(h1, h2) +1);
}
