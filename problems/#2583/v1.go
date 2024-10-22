
type MinHeap []int64

func (m MinHeap) Len() int {
	return len(m)
}

func (m MinHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m MinHeap) Less(i, j int) bool {
	return m[i] < m[j]
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(int64))
}

func (m *MinHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
    q, pq := make([]*TreeNode, 0), MinHeap{}
    heap.Init(&pq)
    q = append(q, root)
    for len(q) > 0 {
        s, sum := len(q), int64(0)
        for _ = range s {
            cur := q[0]
            q = q[1:]
            sum += int64(cur.Val)
            if cur.Left != nil {
                q = append(q, cur.Left)
            }
            if cur.Right != nil {
                q = append(q, cur.Right)
            }
        }
        heap.Push(&pq, sum)
        if pq.Len() > k {
            heap.Pop(&pq)
        }
    }
    if pq.Len() < k {
        return -1
    }
    return heap.Pop(&pq).(int64)
}