class Solution:

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        otpt =[]
        nums.sort()
        n = len(nums)


        for ind,t in enumerate(nums):
            i = ind+1
            j = n-1
            
            while(i<j):
                print(ind,i,j)
                if(nums[i]+nums[j]==-t):
                    curr = [t,nums[i],nums[j]]
                    if(curr not in otpt):
                        otpt.append(curr)
                    i+=1

                elif(nums[i]+nums[j]<-t):
                    i+=1
                else:
                    j-=1

        return otpt;