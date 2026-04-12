class Solution:
    def maxArea(self, heights: List[int]) -> int:
        
        n = len(heights)
        i=0 
        j=n-1

        mx = -1

        while(i<j):
            print(i,j)
            mx = max(min(heights[i],heights[j])*(j-i),mx)
            if(heights[i]<heights[j]):
                i+=1;
            elif(heights[i]>heights[j]):
                j-=1;
            else:
                i+=1;
                j-=1;
        return mx
        

                       