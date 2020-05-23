/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    var stack []*TreeNode
    for root != nil && k !=0 {
        for root != nil {
            stack = append(stack,root);
            root = root.Left ;
        }
        root = stack[len(stack)-1]
        for root.Right == nil && k!=0 {
            k--
            if k==0 {
                return root.Val
            }
            stack = stack[:len(stack)-1]
            root = stack[len(stack)-1]
        }
        stack = stack[:len(stack)-1]
        k--
        if k==0 {
            return root.Val
        }
        root = root.Right
    }
    return root.Val
}
