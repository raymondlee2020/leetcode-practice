func maximumBeauty(items [][]int, queries []int) []int {
    sort.Slice(items, func(i, j int) bool {
        return items[i][0] < items[j][0]
    })
    bound := 0
    for r, item := range items {
        if items[bound][1] >= item[1] {
            continue
        }
        bound++
        items[bound], items[r] = items[r], items[bound]
    }
    n, items := bound + 1, items[:bound + 1]
    binarySearch := func(t int) int {
        l, r := 0, n
        for l < r {
            mid := l + (r - l) / 2
            if items[mid][0] > t {
                r = mid
            } else {
                l = mid + 1
            }
        }
        if l == 0 {
            return 0
        }
        return items[l - 1][1]
    }
    for i, query := range queries {
        queries[i] = binarySearch(query)
    }
    return queries
}