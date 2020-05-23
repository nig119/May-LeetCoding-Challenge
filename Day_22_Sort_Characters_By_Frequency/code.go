type pair struct {
    k int
    c rune
}

func frequencySort(s string) string {
    arr := make([]pair,256)
    for _, c := range s {
        arr[c].c = c
        arr[c].k += 1
    }
    sort.Slice(arr, func(i, j int)bool {
        return arr[i].k > arr[j].k 
    })
    out := ""
    for j:=0 ; j < 256 ; j++ {
        for k:= 0 ; k < arr[j].k ; k++ {
            out += string(arr[j].c)
        }
    }
    return out
}
