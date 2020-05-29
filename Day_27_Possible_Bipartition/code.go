func possibleBipartition(N int, dislikes [][]int) bool {
    graph := make([][]bool, N)
    for i := range graph {
        graph[i] = make([]bool, N)
    }
    for _,v := range dislikes {
        graph[v[0]-1][v[1]-1] = true
        graph[v[1]-1][v[0]-1] = true
    }

    visited := make([]int, N)

    var queue []int
    for i :=0 ; i < N ; i++{
        if visited[i]== 0 {
            visited[i] = 1
            queue = append(queue,i)
            for len(queue) != 0 {
                k := queue[0]
                for j:= 0; j < N ; j++ {
                    if graph[k][j] {
                        if visited[j] == 0 {
                            visited[j] = -1*visited[k]
                            queue = append(queue, j)
                        }else if visited[j] == visited[k] {
                            return false
                        }
                    }
                }
                queue = queue[1:]
            }
        }
    }
    return true
}
