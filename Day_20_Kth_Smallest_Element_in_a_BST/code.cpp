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
    void rec (TreeNode* root, int *k, int *out){
        if (root->left != nullptr){
            rec(root->left,k,out);
            if (*out != INT_MIN) return ;
        }
        if (*k==1){
            *out = root->val ;
            return ;
        }
        *k -= 1;
        if (root->right != nullptr){
            rec(root->right,k,out);
            if (*out != INT_MIN) return ;
        }

    }
    int kthSmallest(TreeNode* root, int k) {
        int p = k ;
        int out = INT_MIN ;
        rec(root, &p, &out);
        return out;

    }
};
