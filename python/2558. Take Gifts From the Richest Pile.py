class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:

        gifts = [ -g for g in gifts] #list comprehension. Turns each value to -1 and make a list
        heapq.heapify(gifts)

        for _ in range(k):
           n = -heapq.heappop(gifts)

           heapq.heappush(gifts, -floor(sqrt(n)))

        return -sum(gifts)