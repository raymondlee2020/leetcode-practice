class Solution:
    def checkValidString(self, s: str) -> bool:
        lps, stars = [], []
        for i, c in enumerate(s):
            if c == '(':
                lps.append(i)
            elif c == ')':
                if len(lps) > 0:
                    lps.pop()
                elif len(stars) > 0:
                    stars.pop(0)
                else:
                    return False
            else:
                stars.append(i)
        for lp in lps:
            while len(stars) > 0 and lp > stars[0]:
                stars.pop(0)
            if len(stars) == 0:
                return False
            stars.pop(0)
        return True
