func max(A int , B int) int {
    if A>B {
        return A
    }
    return B
}
func min (A int , B int) int {
    if A>B {
        return B
    }
    return A
}
func maxSubarraySumCircular(A []int) int {
    local_max := A[0]
    global_max := A[0]
    local_min := A[0]
    global_min := A[0]
    sum := A[0]
    for i := 1; i < len(A) ; i++ {
        sum += A[i]
        local_max = max(local_max+A[i],A[i])
        global_max = max(global_max , local_max)
        local_min = min(local_min+A[i],A[i])
        global_min = min(global_min,local_min)
    }
    if global_max <0 {
        return global_max
    }
    return max(global_max , sum - global_min)
}
