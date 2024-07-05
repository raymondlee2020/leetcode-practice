/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
	if head == nil || head.Next == nil || head.Next.Next == nil {
		return []int{-1, -1}
	}
	ret, tmp, prev, curr, next := []int{math.MaxInt, -math.MaxInt}, make([]int, 2), head, head.Next, head.Next.Next
	for i := 1; curr.Next != nil; i, prev, curr, next = i+1, curr, next, next.Next {
		if (prev.Val > curr.Val && next.Val > curr.Val) || (prev.Val < curr.Val && next.Val < curr.Val) {
			if tmp[0] == 0 {
				tmp[0], tmp[1] = i, i
			} else {
				ret[0] = min(ret[0], i-tmp[1])
				tmp[1] = i
			}
		}
	}
	if ret[0] == math.MaxInt {
		return []int{-1, -1}
	}
	ret[1] = tmp[1] - tmp[0]
	return ret
}