func findJudge(N int, trust [][]int) int {
    vote := make([]int,N)
    for _,v := range trust {
        vote[v[0]-1] = -1
        if vote[v[1]-1] != -1 {
            vote[v[1]-1] ++
        }
    }
    for i,k := range vote {
        if k==N-1 {
            return i+1
        }
    }
    return -1
}