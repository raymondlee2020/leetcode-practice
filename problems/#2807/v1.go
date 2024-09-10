/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func insertGreatestCommonDivisors(head *ListNode) *ListNode {
    curr, next := head, head.Next
    for next != nil {
        curr.Next = &ListNode{gcd(curr.Val, next.Val), next}
        curr, next = next, next.Next
    }
    return head
}

func gcd(a, b int) int {
	if a < 0 {
		a *= -1
	}
	for a > 0 {
		a, b = b % a, a
	}
	return b
}