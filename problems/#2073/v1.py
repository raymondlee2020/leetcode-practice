class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        ret, n, cnt, prev = 0, len(tickets), dict(), 0
        for ticket in tickets:
            if ticket not in cnt:
                cnt[ticket] = 0
            cnt[ticket] += 1
        cnt = sorted(cnt.items())
        for item in cnt:
            ret += (item[0] - prev) * n
            if item[0] == tickets[k]:
                ret -= n
                break
            prev = item[0]
            n -= item[1]
        for i in range(k + 1):
            ret += 0 if tickets[i] < tickets[k] else 1
        return ret