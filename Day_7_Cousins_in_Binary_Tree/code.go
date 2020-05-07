/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func toDepth (root *TreeNode, x int, out *[]int) bool {
    if root == nil {
        return false
    }
    if root.Val == x || toDepth(root.Left, x, out) || toDepth(root.Right, x, out) {
        *out = append(*out, root.Val)
        return true
    }
    return false
}

func isCousins(root *TreeNode, x int, y int) bool {
    sx := make([]int, 0)
    sy := make([]int, 0)
    toDepth(root, x, &sx)
    toDepth(root, y, &sy)
    // fmt.Printf("%+v\n%+v ", sx, sy)
    return len(sx) == len(sy) && len(sx) > 2 && sx[1] != sy[1]
}
