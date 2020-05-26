func max (A,B int) int {
    if A >B {
        return A 
    }
    return B 
}
func maxUncrossedLines(A []int, B []int) int {
    la := len(A) 
    lb := len(B)
    DP := make ([][]int , 1+ la)
    for i := 0 ; i < 1+la ; i++ {
        DP[i] = make([]int,1+lb)
    }
    
    for i := 1 ; i< 1+la ; i ++ {
        for j := 1 ; j < 1+lb ; j++ {
            k := 0 
            if A[i-1]==B[j-1] {
                k = 1 
            }
            DP[i][j] = max (max(DP[i-1][j], DP[i][j-1]), k + DP[i-1][j-1])
        }
    }
    return DP[la][lb]
}