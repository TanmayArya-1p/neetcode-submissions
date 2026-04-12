class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for i in strs:
            l = [0 for i in range(26)]
            for j in i:
                l[ord(j)-ord('a')]+=1;

            k  =tuple(l)
            if(mp.get(k,-1) == -1):
                mp[k] = [i]
            else:
                mp[k].append(i)
        otpt = []
        for i in mp:
            otpt.append(mp[i])
        return otpt