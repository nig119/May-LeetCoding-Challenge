/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func rec (preorder []int, s int , e int) *TreeNode {
    if s==e {
        return nil
    }
    root := TreeNode{}
    root.Val = preorder[s]
    r := s+1
    for r < e && preorder[r] < preorder[s] {
        r ++
    }
    root.Left = rec(preorder, s+1 ,r )
    root.Right = rec(preorder, r , e)
    return &root
}
func bstFromPreorder(preorder []int) *TreeNode {
    return rec(preorder, 0 ,len(preorder))
}
