import java.util.*;
public class palindromic_partition {
	public static void main(String[] args) {
		String s = "12321";
		List<List<String>> part = new ArrayList<>();
		//myrec(part, s,new ArrayList<String>(), 0);
		//print(part);
		System.out.println(isPalindromeReccursion(s,0,s.length()-1));
	}
	static void myrec(List<List<String>> soln,String s,List<String> list,int curr)
	{
		// is valid state
		if(curr==s.length())
		{
			if(isPalindromeList(list)) soln.add(list);
			return ;
		}
		if(!isPalindromeList(list)) return;
		for(int i=1;i<=s.length()-curr;i++)
		{
			String current_string = s.substring(curr,curr+i);
			list.add(current_string);
			myrec(soln, s, new ArrayList<String>(list), curr+i);
			list.remove(current_string);
		}
	}
	static boolean isPalindrome(String s)
	{
		char[] arr = s.toCharArray();
		int lo = 0,hi =s.length()-1;
		while(lo<hi)
		{
			if(arr[lo]!=arr[hi]) return false;
			lo++;
			hi--;
		}
		return true;
	}
	static boolean isPalindromeReccursion(String s,int lo,int hi)
	{
		if(lo>hi) return true;
		return s.charAt(lo)==s.charAt(hi)?isPalindromeReccursion(s, lo+1, hi-1):false;
	}
	static boolean  isPalindromeList(List<String> list)
	{
		for(String curr: list) if(!isPalindrome(curr)) return false;
		return true;
	}
	static void print(List<List<String>> list)
	{
		for(List<String> sub: list)
		{
			for(String s:sub) System.out.print(s+" ");
			System.out.println();
		}
	}
}
