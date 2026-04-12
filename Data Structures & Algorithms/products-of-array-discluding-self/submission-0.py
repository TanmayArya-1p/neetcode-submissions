class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = 1
        zf = 0
        for i in nums:
            if(i==0):
                 zf+=1
            else:
                prod*=i
        otpt = []
        for i in range(len(nums)):
            if(zf):
                if(nums[i]!=0):
                    otpt.append(0)
                else:
                    if(zf>1):
                        otpt.append(0)
                    else:
                        otpt.append(prod)
            else:
                otpt.append(prod//nums[i])
        return otpt
        