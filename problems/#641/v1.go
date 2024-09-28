type MyCircularDeque struct {
    bound int
    values []int
}


func Constructor(k int) MyCircularDeque {
    return MyCircularDeque{k, []int{}}
}


func (this *MyCircularDeque) InsertFront(value int) bool {
    if len(this.values) == this.bound {
        return false
    }
    this.values = append([]int{value}, this.values...)
    return true
}


func (this *MyCircularDeque) InsertLast(value int) bool {
    if len(this.values) == this.bound {
        return false
    }
    this.values = append(this.values, value)
    return true
}


func (this *MyCircularDeque) DeleteFront() bool {
    if len(this.values) == 0 {
        return false
    }
    this.values = this.values[1:]
    return true
}


func (this *MyCircularDeque) DeleteLast() bool {
    if len(this.values) == 0 {
        return false
    }
    this.values = this.values[:len(this.values) - 1]
    return true
}


func (this *MyCircularDeque) GetFront() int {
    if len(this.values) == 0 {
        return -1
    }
    return this.values[0]
}


func (this *MyCircularDeque) GetRear() int {
    if len(this.values) == 0 {
        return -1
    }
    return this.values[len(this.values) - 1] 
}


func (this *MyCircularDeque) IsEmpty() bool {
    return len(this.values) == 0
}


func (this *MyCircularDeque) IsFull() bool {
    return len(this.values) == this.bound
}


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */