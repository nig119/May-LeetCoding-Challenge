func findComplement(num int) int {
    k := num
    pow := 1
    for k>0 {
        k = k>>1
        pow +=1
    }
    out := 1
    for pow!= 1{
        out *= 2
        pow -=1
    }
    out -= 1
    out -= num
    return out
}
