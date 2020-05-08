func checkStraightLine(coordinates [][]int) bool {
    x1 := coordinates[0][0]
    y1 := coordinates[0][1]
    incx := coordinates[1][0]-x1
    incy := coordinates[1][1]-y1
    for i := 2 ; i < len(coordinates) ; i++ {
        if  (coordinates[i][1]-y1)*incx != incy*(coordinates[i][0]-x1) {
            return false
        }
    }
    return true
}