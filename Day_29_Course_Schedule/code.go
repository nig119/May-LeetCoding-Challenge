func rec(umap map[int][]int, visit []int, index int) bool {
    if visit[index] == 1 {
        return false
    }
    visit[index] = 1
    for _, v:= range umap[index] {
        if visit[v] != 2 {
            if !rec(umap,visit,v) {
                return false
            }
        }
    }
    visit[index] = 2
    return true
}

func canFinish(numCourses int, prerequisites [][]int) bool {
    umap := make(map[int][]int)
    for _,v := range prerequisites {
        umap[v[1]] = append(umap[v[1]], v[0])
    }
    visit := make([]int,numCourses)
    for i:=0; i < numCourses; i++ {
        if visit[i] !=2 {
            if !rec(umap,visit,i){
                return false 
            }
        }
    }
    return true 
}
