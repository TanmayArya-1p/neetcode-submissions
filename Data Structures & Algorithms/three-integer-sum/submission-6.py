class Solution:

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        otpt =[]
        nums.sort()
        n = len(nums)

        prev = -1
        for ind,t in enumerate(nums):
            if(ind!=0 and t==prev):
                continue
            prev= t;
            i = ind+1
            j = n-1
            
            while(i<j):
                print(ind,i,j)
                if(nums[i]+nums[j]==-t):
                    curr = [t,nums[i],nums[j]]
                    otpt.append(curr)
                    prevI = nums[i]
                    prevJ = nums[j]
                    while(i<j and nums[i] == prevI):
                        i+=1
                    while(j>i and nums[j] == prevJ):
                        j-=1
                    

                elif(nums[i]+nums[j]<-t):
                    i+=1
                else:
                    j-=1

        return otpt;