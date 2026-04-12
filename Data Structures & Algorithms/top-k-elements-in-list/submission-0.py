class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}

        for i in nums:
            if(freq.get(i,-1) == -1):
                freq[i] = 1;
            else:
                freq[i]+=1;
        

        otpt = [(freq[i],i) for i in freq]
        otpt.sort(reverse=True,key=lambda x: x[0])
        return [i[1] for i in otpt[:k]]
