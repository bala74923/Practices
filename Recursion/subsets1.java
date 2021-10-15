import java.util.*;
public class subsets1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//String s = sc.next();
		int[] arr = {1,2,3,4,5};
		List<List<Integer>> powerset  = getPowerSetForArray(arr,0);
		System.out.println(powerset+"\nSize="+powerset.size());
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
}
