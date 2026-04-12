class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(len(s)==0):
            return 0
        l=0
        r=0
        n= len(s)
        mp = {}
        mp[s[0]] = True
        ans = 1
        while l<=r and r!=n-1:
            print(l,r)
            if(mp.get(s[r+1],-1) == -1):
                r+=1
                mp[s[r]] = True;
            else:
                while(mp.get(s[r+1],-1) != -1):
                    del mp[s[l]]
                    l+=1
                r+=1
                mp[s[r]] = True

            ans = max(ans,r-l+1)
        return ans