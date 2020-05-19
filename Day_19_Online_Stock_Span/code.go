type StockSpanner struct {
    arr [][]int
}


func Constructor() StockSpanner {
    return StockSpanner{}
}


func (this *StockSpanner) Next(price int) int {
    arr := this.arr
    out := 1 ;
    for  len(arr)> 0 && arr[len(arr)-1][0] <= price {
        out += arr[len(arr)-1][1]
        arr = arr[:len(arr)-1]
    }
    add := []int{price,out}
    this.arr = append(arr,add)
    return out
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
