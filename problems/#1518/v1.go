func numWaterBottles(numBottles int, numExchange int) int {
	ret := numBottles
	for numBottles >= numExchange {
		ret += numBottles / numExchange
		numBottles = (numBottles / numExchange) + (numBottles % numExchange)
	}
	return ret
}