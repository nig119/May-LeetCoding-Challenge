func max (a,b int) int {
    if a < b {
        return b
    }
    return a
}
func min (a,b int) int {
    if a <b {
        return a
    }
    return b
}
func intervalIntersection(A [][]int, B [][]int) [][]int {
    i := 0
    j := 0
    out := [][]int{}
    for i<len(A) && j < len(B){
       if A[i][1] < B[j][0] {
           i ++
       }else if B[j][1] < A[i][0] {
           j ++
       }else {
           out = append(out, ([]int{max(A[i][0],B[j][0]) , min(A[i][1],B[j][1])}) );
           if (B[j][1] > A[i][1]){
               i++
           }else {
               j++
           }
       }
    }
    return out
}
