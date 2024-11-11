func primeSubOperation(nums []int) bool {
    n, isPrime, primes := len(nums), make([]bool, 1001), make([]int, 0)
    for i := range 1001 {
        isPrime[i] = true
    }
    // seive algorithm
    isPrime[0], isPrime[1] = false, false
    for i := 2; i * i < 1001; i++ {
        for j := 2 * i; j < 1001; j += i {
            isPrime[j] = false
        }
    }
    for i := range 1001 {
        if isPrime[i] {
            primes = append(primes, i)
        }
    }
    m := len(primes)
    for i, miss := n - 2, true; i >= 0; i, miss = i - 1, true {
        nxt := nums[i + 1]
        if nums[i] < nxt {
            continue
        }
        for j := 0; j < m && primes[j] < nums[i]; j++ {
            if nums[i] - primes[j] < nxt {
                nums[i] -= primes[j]
                miss = false
                break
            }
        }
        if miss {
            return false
        }
    }
    return true
}