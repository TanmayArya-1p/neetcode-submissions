class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        suffMax = [height[-1]]
        prefMax = [height[0]]
        for i in range(1,n):
            prefMax.append(max(prefMax[-1],height[i]))
        for i in range(2,n+1):
            suffMax.append(max(suffMax[-1],height[-i]))
        

        filled=height.copy()

        #left limiting sweep

        running = False;
        prev = -1

        i = 0
        while(i<n-1):
            if(running):
                if(height[i]<prev):
                    filled[i]=max(prev,filled[i])

                else:
                    running=False
                    i-=1;
            else:
                if(suffMax[-(i+2)] >= height[i]):
                    running = True
                    prev = height[i]
            i+=1;
    
        print(filled)

        #right limiting sweep

        running = False;
        prev = -1

        i = n-1
        while(i>0):
            if(running):
                if(height[i]<prev):
                    filled[i]=max(prev,filled[i])
                else:
                    running=False
                    i+=1;
            else:
                if(prefMax[i-1] >= height[i]):
                    running = True
                    prev = height[i]
            i-=1;

        print(filled)
        otpt =0
        for i in range(n):
            otpt+=filled[i]-height[i]
        return otpt

