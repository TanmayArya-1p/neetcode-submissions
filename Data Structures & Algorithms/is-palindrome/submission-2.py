class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        t = []
        for i in s:
            if(i.isalnum()):
                t.append(i)
        otpt = "".join(t)

        return otpt==otpt[::-1]