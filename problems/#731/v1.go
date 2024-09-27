type MyCalendarTwo struct {
    one [][]int
    two [][]int
}


func Constructor() MyCalendarTwo {
    return MyCalendarTwo{}
}


func (this *MyCalendarTwo) Book(start int, end int) bool {
    end--
    new := []int{start, end}
    for _, event := range this.two {
        tmp := this.interact(new, event)
        if len(tmp) > 0 {
            return false
        }
    }
    for _, event := range this.one {
        tmp := this.interact(new, event)
        if len(tmp) > 0 {
            this.two = append(this.two, tmp)
        }
    }
    this.one = append(this.one, new)
    return true
}

func (this *MyCalendarTwo) interact(a, b []int) []int {
    if a[0] > b[0] {
        a, b = b, a
    }
    if b[0] > a[1] {
        return []int{}
    }
    if a[0] == b[0] && a[1] <= b[1] {
        return a
    }
    if a[1] >= b[1] {
        return b
    }
    return []int{b[0], a[1]}
}


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */