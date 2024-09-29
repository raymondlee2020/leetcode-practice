type AllOne struct {
    kc map[string]int
    ck map[int]map[string]bool
}


func Constructor() AllOne {
    return AllOne{
        kc: make(map[string]int),
        ck: make(map[int]map[string]bool),
    }
}


func (this *AllOne) Inc(key string)  {
    c, exist := this.kc[key]
    this.kc[key]++
    if exist {
        delete(this.ck[c], key)
    }
    if this.ck[c + 1] == nil {
        this.ck[c + 1] = make(map[string]bool)
    }
    this.ck[c + 1][key] = true
}


func (this *AllOne) Dec(key string)  {
    c, _ := this.kc[key]
    this.kc[key]--
    delete(this.ck[c], key)
    if this.kc[key] == 0 {
        delete(this.kc, key)
    } else {
        this.ck[c - 1][key] = true
    }
}


func (this *AllOne) GetMaxKey() string {
    if len(this.ck) == 0 {
        return ""
    }
    for c := len(this.ck); c > 0; c-- {
        for k := range this.ck[c] {
            return k
        }
    }
    return ""
}


func (this *AllOne) GetMinKey() string {
    if len(this.ck) == 0 {
        return ""
    }
    n := len(this.ck)
    for c := 1 ; c <= n; c++ {
        for k := range this.ck[c] {
            return k
        }
    }
    return ""
}


/**
 * Your AllOne object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Inc(key);
 * obj.Dec(key);
 * param_3 := obj.GetMaxKey();
 * param_4 := obj.GetMinKey();
 */