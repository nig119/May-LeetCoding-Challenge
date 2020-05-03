func canConstruct(ransomNote string, magazine string) bool {
    var arr = make([]int,128)
    for _, c := range magazine {
        arr[int(c)] +=1
    }
    for _, c := range ransomNote {
        if arr[int(c)] >0 {
            arr[int(c)] -= 1
        }else {
            return false
        }
    }
    return true
}