/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    odd := head
    even := head.Next
    evenhead := even
    if odd == nil || even == nil {
        return head
    }
    temp := head.Next.Next
    if temp == nil {
        return head
    }
    flag := true
    for temp != nil {
        if flag {
            odd.Next = temp
            odd = odd.Next
        } else {
            even.Next = temp
            even = even.Next
        }
        flag = !flag
        temp = temp.Next
    }
    odd.Next = evenhead
    even.Next = nil
    return head
}