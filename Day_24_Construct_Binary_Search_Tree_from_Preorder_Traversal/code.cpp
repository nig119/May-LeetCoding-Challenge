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
    TreeNode* rec (vector<int> &preorder, int s, int e){
        if (s==e) return nullptr ;
        TreeNode * root = new TreeNode();
        root->val = preorder[s] ;
        int r = s+1 ;
        while(r < e && preorder[r] < preorder[s]) {
            r++;
        }
        root->left = rec(preorder,s+1,r) ;
        root->right = rec(preorder,r,e) ;
        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return rec(preorder, 0 ,preorder.size());

    }
};
