import java.util.*;
public class basics {
	public static void main(String[] args) 
	{
		// int[] arr = {1,2,4,5,8,10};
		// System.out.println(binarysearch(arr, 10));
		// System.out.println(factorial(5));
		// System.out.println(fibo(5));
		// fun(4,"");
		// System.out.println(sumUpTo(10));
		// System.out.println(pow(2,5));
		System.out.println(ack(2,2,0));
	}
	static Map<String,Integer> map = new HashMap<>();
	static int ack(int m,int n,int times)
	{ 
		//System.out.println("->".repeat(times)+"ack("+m+" , "+n+")");
		if(m==0)
		{
			System.out.println("->".repeat(times)+"Returning "+(n+1)+" to  ack("+m+" , "+n+")");
			return n+1;
		}
		else if(n==0) 
		{
			System.out.println("->".repeat(times)+"ack("+m+" , "+n+")");
			return ack(m-1,1,times+1);
		}
		System.out.println("->".repeat(times)+"ack("+(m-1)+" , "+"ack("+m+" , "+(n-1)+")"+")");
		return ack(m-1,ack(m,n-1,times+1),times+1);
	}

	static int pow(int a,int b,int... mul)
	{
		if(mul.length==0) return pow(a,b-1,a);
		if(b==0) return mul[0];
		return pow(a,b-1,mul[0]*a);
	}

	static int sumUpTo(int n,int ... sum)
	{
		if(sum.length==0) return sumUpTo(n-1,n);
		if(n==0) return sum[0];
		sum[0]+=n;
		return sumUpTo(n-1, sum);
	}

	static void fun(int n,String gap)
	{
		if(n==1)
		{
			System.out.println(gap+gap+"fun("+1+")");
		}
		else
		{
			System.out.println(gap+gap+"fun("+n+") puased");
			fun(n-1,gap+" ");
			System.out.println(gap+gap+"back to"+"fun("+n+")");
		}
	}

	static boolean isPrime(int curr,int n)
	{
		if(curr==n) return true;
		else if(n%curr==0) return false;
		return isPrime(curr+1,n);
	}

	static int binarysearch(int[] arr,int key)
	{
		return search(arr, key, 0,arr.length-1)+1;
	}

	static int search(int[] arr,int key,int lo,int hi)
	{
		int mid = (lo+hi)/2;
		if(arr[mid]==key) return mid;
		else if(arr[mid]<key) return search(arr,key,mid+1,hi);
		return search(arr,key,lo,mid-1);
	}

	static int factorial(int n)
	{
		if(n==0) return 1;
		return n*factorial(n-1);
	}

	static int fibo(int n)
	{
		if(n==1) return 0;
		else if(n==2) return 1;
		return fibo(n-1)+fibo(n-2);
	}
}