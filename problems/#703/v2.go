type KthLargest struct {
	k        int
	elements []int // min heap
}

func Constructor(k int, nums []int) KthLargest {
	kthLargest := KthLargest{k, make([]int, 0)}
	heap.Init(&kthLargest)
	for _, num := range nums {
		heap.Push(&kthLargest, num)
	}
	return kthLargest
}

func (this *KthLargest) Add(val int) int {
	heap.Push(this, val)
	return this.elements[0]
}

func (this KthLargest) Len() int {
	return len(this.elements)
}

func (this KthLargest) Swap(i, j int) {
	this.elements[i], this.elements[j] = this.elements[j], this.elements[i]
}

func (this KthLargest) Less(i, j int) bool {
	return this.elements[i] < this.elements[j]
}

func (this *KthLargest) Push(x interface{}) {
	if len(this.elements) == this.k {
		if x.(int) < this.elements[0] {
			return
		}
		heap.Pop(this)
	}
	this.elements = append(this.elements, x.(int))
}

func (this *KthLargest) Pop() interface{} {
	n := len(this.elements)
	x := this.elements[n-1]
	this.elements = this.elements[:n-1]
	return x
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */