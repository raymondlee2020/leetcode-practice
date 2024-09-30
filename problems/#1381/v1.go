type CustomStack struct {
    values []int
    bound  int
}


func Constructor(maxSize int) CustomStack {
    return CustomStack{make([]int, 0), maxSize}
}


func (this *CustomStack) Push(x int)  {
    if len(this.values) == this.bound {
        return
    }
    this.values = append(this.values, x)
}


func (this *CustomStack) Pop() int {
    if len(this.values) == 0 {
        return -1
    }
    idx := len(this.values) - 1
    ret := this.values[idx]
    this.values = this.values[:idx]
    return ret
}


func (this *CustomStack) Increment(k int, val int)  {
    k = min(len(this.values), k)
    for i := range k {
        this.values[i] += val
    }
}


/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */