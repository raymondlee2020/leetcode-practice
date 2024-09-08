/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func splitListToParts(head *ListNode, k int) []*ListNode {
    ret, cnt := make([]*ListNode, k), 0
    for curr := head; curr != nil; curr = curr.Next {
        cnt++
    }
    q, r := cnt / k, cnt % k
    for i := range k {
        ph, pt := head, &ListNode{0, head}
        for _ = range q {
            pt, head = pt.Next, head.Next
        }
        if r > 0 {
            pt, head = pt.Next, head.Next
            r--
        }
        pt.Next = nil
        ret[i] = ph
    }
    return ret
}