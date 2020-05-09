func isPerfectSquare(num int) bool {
    s := 1
    e := 46340
    var mid int
    var mid2 int
    for s <= e {
        mid = s + (e-s)/2
        mid2 = mid*mid
        if mid2 == num {
            return true
        }else if mid2 > num {
            e = mid-1
        }else {
            s = mid+1
        }
    }
    return false
}
