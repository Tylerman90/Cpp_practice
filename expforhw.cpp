func bubblesort(A []int, size int) {
    var swapped bool = true
    for swapped {
        swapped = false
        var i int = 1
        for i < size {
            if A[i-1] > A[i] {
                swap(A, i-1, i)
                swapped = true
            }
            i = i + 1
        }
    }
    return
}