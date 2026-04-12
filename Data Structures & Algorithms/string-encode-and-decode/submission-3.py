class Solution:

    def encode(self, strs: List[str]) -> str:
        otpt = "|".join(strs)
        otpt+="|"+str(len(strs))
        return otpt            

    def decode(self, s: str) -> List[str]:
        otpt = s.split("|")
        n = int(otpt.pop())
        while(len(otpt) > n):
            otpt.pop()
        
        if(len(otpt) != n):
            while(len(otpt) < n):
                otpt.append("")

        return otpt