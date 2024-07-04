/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeNodes(head *ListNode) *ListNode {
	tail, merged := head, &ListNode{0, nil}
	for curr := head.Next; curr != nil; curr = curr.Next {
		if curr.Val == 0 {
			tail.Next = merged
			tail = tail.Next
			merged = &ListNode{0, nil}
		}
		merged.Val += curr.Val
	}
	return head.Next
}