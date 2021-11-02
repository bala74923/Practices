package Recursion2;
import java.util.*;
public class sum_of_all_substes_xor_total {
	public static void main(String[] args) 
	{
		int[] nums = {3,4,5,6,7,8};
		List<List<Integer>> list = subs(0, nums);
		//System.out.println(list);
		int sum=0;
		for(List<Integer> sub:list) sum+=sub.get(0);
		//System.out.println("sum is "+sum);
	}
	static List<List<Integer>>  subs(int step,int[] arr)
	{
		if(step==arr.length-1)
		{
			List<Integer> sub= new ArrayList<>();
			sub.add(0);
			List<List<Integer>> ans= new ArrayList<>();
			ans.add(new ArrayList<Integer>(sub));
			sub.remove(0);
			sub.add(arr[step]);
			sub.add(arr[step]);
			ans.add(new ArrayList<Integer>(sub));
			return ans;
		}
		List<List<Integer>> prev = subs(step+1, arr);
		return combine(prev,arr[step]);
	}
	static List<List<Integer>> combine(List<List<Integer>> ans,int n)
	{
		List<List<Integer>> list = new ArrayList<>();
		for(List<Integer> sub:ans)
		{
			list.add(new ArrayList<Integer>(sub));
			int xor = sub.get(0)^n;
			sub.add(n);
			sub.set(0, xor);
			list.add(new ArrayList<Integer>(sub));
		}
		return list;
	}
}
