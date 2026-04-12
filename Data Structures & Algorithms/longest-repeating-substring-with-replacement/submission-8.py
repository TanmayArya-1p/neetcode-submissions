class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        alpha = [chr(ord('A')+i) for i in range(26)]
        alpha = filter(lambda x: x in s,alpha)
        ans = -1
        n = len(s)
        for l in alpha:
            i = 0
            j = 0

            running=False
            if(k==0):
                ct = 0
                for ind,g in enumerate(s):
                    if(running):
                        if(g==l):
                            ct+=1
                        else:
                            running=False
                            ans=max(ans,ct)
                            ct=0
                    else:
                        if(g==l):
                            running = True
                            ct+=1
                ans=max(ans,ct)
                continue;
                            
                

            used = k
            if(s[0]!=l):
                used-=1

            while(i<=j and j!=n-1):
                print(i,j,used,l)
                if(used==0):
                    ans=max(ans,j-i+1)
                    if(s[j+1] == l):
                        j+=1   
                    else:
                        if(s[i]!=l):
                            used+=1
                        i+=1
                else:
                    if(s[j+1] != l):
                        used-=1
                    j+=1
                    ans=max(ans,j-i+1)
            if(j==n-1):
                ans=max(ans,j-i+1)

        return ans

                    
        

        