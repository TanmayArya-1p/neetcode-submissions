class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefProds = [nums[0]]
        sufProds = [nums[-1]]
        for i in range(1,len(nums)):
            prefProds.append(nums[i]*prefProds[-1])
        for i in range(2,len(nums)+1):
            sufProds.append(sufProds[-1]*nums[-i])
        
        otpt = [sufProds[-2]]
        for j in range(1,len(nums)-1):
            otpt.append(prefProds[j-1]*sufProds[-(j+2)])
        otpt.append(prefProds[-2])
        print(prefProds,sufProds)
        return otpt
