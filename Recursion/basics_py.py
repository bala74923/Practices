def min(arr,curr=0,minim = None):
	if(curr == len(arr)): return minim
	if(minim==None):minim = arr[curr]
	minim = minim if minim<arr[curr] else arr[curr]
	return min(arr,curr+1,minim)
print(min([5,3,2,1]))

def fibo(n,curr=3,t1=0,t2=1):
	if(n<=1): return n
	if(curr==n): return t2+t1
	return fibo(n,curr+1,t2,t1+t2)

print(fibo(5))