func rec(image [][]int, sr int , sc int, old int , newC int ,  mu sync.Mutex) {
    mu.Lock()
    if sr == -1 || sc == -1 || sr == len(image) || sc == len(image[0]) || image[sr][sc] != old {
        mu.Unlock()
        return
    }
    image[sr][sc] = newC
    mu.Unlock()
    var wg sync.WaitGroup
    mov := [][]int{{0,1},{1,0},{-1,0},{0,-1}}
    for _,v:= range mov {
        wg.Add(1)
        go func(sr int, sc int){
            defer wg.Done()
            rec(image,sr,sc,old,newC,mu)
        }(sr+v[0],sc+v[1])
    }
    wg.Wait()
}
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
    var mu sync.Mutex
    mu.Lock()
    var old = image[sr][sc]
    if old == newColor {
        mu.Unlock()
        return image
    }
    mu.Unlock()
    rec(image,sr,sc,old,newColor,mu)
    return image
}
