/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doubleIt(head *ListNode) *ListNode {
	carry, s := 0, make([]*ListNode, 0)
	for head != nil {
		s = append(s, head)
		head = head.Next
	}
	for i := len(s) - 1; i >= 0; i-- {
		s[i].Val = s[i].Val*2 + carry
		carry = s[i].Val / 10
		if s[i].Val >= 10 {
			s[i].Val -= 10
		}
	}
	head = s[0]
	if carry > 0 {
		head = &ListNode{
			Val:  1,
			Next: head,
		}
	}
	return head
}