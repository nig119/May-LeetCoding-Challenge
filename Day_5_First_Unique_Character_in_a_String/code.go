func firstUniqChar(s string) int {
    arr  := make([]int , 128)
    for i, _ := range arr {
        arr[i] = -2
    }
    for i, k := range s {
        c := int(k)
        if arr[c] == -2 {
            arr[c] = i
        }else if arr[c] == -3 {

        }else {
            arr[c] = -3
        }
    }

    min := func (a int , b int) int {
        if a<b  {
            return a
        }else {
            return b
        }
    }
    out := 100000
    for _,i  := range arr {
        if i != -2 && i != -3 {
            out = min (out, i)
        }
    }
    if out == 100000 {
        return -1
    }
    return out 
}
