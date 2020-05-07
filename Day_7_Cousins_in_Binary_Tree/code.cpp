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
    bool toDepth(TreeNode* root, int x, vector<int> &out) {
        if (root == nullptr) return false ;
        if (root->val == x || toDepth(root->left, x, out) || toDepth(root->right, x, out)){
            out.push_back(root->val) ;
            return true ;
        }
        return false ;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> sx ;
        vector<int> sy ;
        toDepth(root, x, sx) ;
        toDepth(root, y, sy) ;
        return sx.size() == sy.size() && sx.size() > 2 && sx[1] != sy[1] ;
    }
};
