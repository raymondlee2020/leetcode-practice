class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt0, cnt1 = 0, 0
        for student in students:
            if student == 0:
                cnt0 += 1
            else:
                cnt1 += 1
        for sandwich in sandwiches:
            if sandwich == 0:
                if cnt0 == 0:
                    break
                cnt0 -= 1
            else:
                if cnt1 == 0:
                    break
                cnt1 -= 1
        return max(cnt0, cnt1)
        
        