/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
	if head.Next == nil {
		return head
	}
	rmax := removeNodes(head.Next)
	if head.Val < rmax.Val {
		return rmax
	}
	head.Next = rmax
	return head
}