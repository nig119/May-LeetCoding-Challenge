func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func countSquares(matrix [][]int) int {
    out := 0
    for i:=0 ; i < len(matrix) ; i++ {
        for j := 0 ; j < len(matrix[0]) ; j++ {
            if i > 0 && j > 0 && matrix[i][j] > 0 {
                matrix [i][j] = min(matrix[i-1][j], min(matrix[i][j-1],matrix[i-1][j-1])) +1 
            }
            out += matrix[i][j]
        }
    }
    return out
}
