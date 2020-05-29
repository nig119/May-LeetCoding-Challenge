func max (a,b int) int {
    if a <b {
        return b
    }
    return a
}
func findMaxLength(nums []int) int {
    umap := make(map[int]int)
    umap[0] = -1
    sum := 0
    out := 0
    for i:=0 ; i< len(nums) ; i++{
        if nums[i] == 1 {
            sum++
        }else {
            sum--
        }
        val, ok := umap[sum]
        if !ok {
            umap[sum] = i
        }else {
            out = max(out,i-val)
        }
    }
    return out
}
