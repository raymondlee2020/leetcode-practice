/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func modifiedList(nums []int, head *ListNode) *ListNode {
    m, dummy := make(map[int]bool), &ListNode{0, head}
    for _, num := range nums {
        m[num] = true
    }
    head = dummy
    for head != nil {
        for head.Next != nil && m[head.Next.Val] {
            head.Next = head.Next.Next
        }
        head = head.Next
    }
    return dummy.Next
}