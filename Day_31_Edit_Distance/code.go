func min(a,b int) int {
    if a<b {
        return a
    }
    return b
}
func minDistance(word1 string, word2 string) int {
    N := len(word1)
    M := len(word2)
    if N ==0 {
        return M
    }
    if M == 0 {
        return N
    }
    DP := make([][]int, N)
    for i:=0 ; i < N ; i++ {
        DP[i] = make([]int,M)
    }
    for i:=0; i < N; i++ {
        for j:= 0 ; j < M ; j++ {
            if i==0 && j==0 {
                if word1[i]!= word2[j] {
                    DP[i][j]= 1
                }
                continue
            }
            if i==0 {
                if word1[i]==word2[j] {
                    DP[i][j] = j
                }else {
                    DP[i][j] = 1+min(DP[i][j-1], j)
                }
                continue
            }
            if j==0 {
                 if word1[i]==word2[j] {
                    DP[i][j] = i
                }else {
                    DP[i][j] = 1+min(DP[i-1][j], i)
                }
                continue
            }
            if word1[i]==word2[j] {
                DP[i][j] = DP[i-1][j-1]
            }else {
                DP[i][j] = 1+min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))
            }
        }
    }
    return DP[N-1][M-1]
}

