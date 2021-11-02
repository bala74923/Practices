package Recursion;
import java.util.*;
public class subsets1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//String s = sc.next();
		int[] arr = {1,2,3,4,5};
		String s = "Ram";
		// List<List<Integer>> powerset  = getPowerSetForArray(arr,0);
		// System.out.println(powerset+"\nSize="+powerset.size());
		List<String> list = getPowerSetForString(s,0);
		System.out.println(list+"\nSize="+list.size());
	}
	static List<List<Integer>> getPowerSetForArray(int[] arr,int curr)
	{
		if(curr==arr.length-1)
		{
			List<List<Integer>>ans = new ArrayList<>();
			ans.add(new ArrayList<Integer>());
			List<Integer> sub = new ArrayList<Integer>();
			sub.add(arr[curr]);
			ans.add(sub);
			//System.out.println(ans);
			return ans;
		}
		List<List<Integer>> prev_result =getPowerSetForArray(arr, curr+1);
		return combine(arr, curr, prev_result);
	}
	static List<List<Integer>> combine(int[] arr,int curr,List<List<Integer>> prev_result)
	{
		List<List<Integer>> ans = new ArrayList<>();
		for(List<Integer> list:prev_result)
		{
			ans.add(new ArrayList<>(list));
			list.add(arr[curr]);
			ans.add(new ArrayList<>(list));
		}
		//System.out.println("curr"+curr+"=>"+prev_result+"\n-->"+ans);
		return ans;
	}

	static List<String> getPowerSetForString(String s,int curr)
	{
		if(curr==s.length()-1)
		{
			List<String> list = new ArrayList<>();
			list.add("");
			list.add(s.charAt(curr)+"");
			return list;
		}
		List<String> prev = getPowerSetForString(s, curr+1);
		return combine(s, curr, prev);
	}
	static List<String> combine(String s,int curr,List<String>prev)
	{
		List<String> ans = new ArrayList<>(prev);
		for(String sub:prev) ans.add(s.charAt(curr)+sub);
		return ans;
	}
}
