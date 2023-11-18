#import sys
#sys.stdin = open("input.txt", "r")
T = int(input())
for i in range(1, T+1):
	aa=list(map(int, input().split()))
	max=0
	for j in aa:
		if max<j:
			max=j
            
	print("#%d %d" %(i, max))
	
        
