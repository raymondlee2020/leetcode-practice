class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        n = len(deck)
        ret, q = [0] * n, [i for i in range(n)]
        deck.sort()
        while len(q) > 0:
            ret[q.pop(0)] = deck.pop(0)
            if len(q) > 0:
                q.append(q.pop(0))
        return ret
