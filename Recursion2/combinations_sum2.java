import java.util.*;
public class combinations_sum2 
{
	public static void main(String[] args)
	{
		combinations_sum2 obj = new combinations_sum2();
		int[] candidates = {10,1,2,7,6,1,5};
		int target = 8;
		System.out.println(obj.combinationSumtwo(candidates, target));
	}

	public List<List<Integer>> combinationSumtwo(int[] candidates, int target) 
	{
		List<List<Integer>> ans = new ArrayList<>();
		List<Map<Integer,Integer>> list_of_map = new ArrayList<>();
		comb(target,candidates,target,ans,new ArrayList<Integer>(),list_of_map,new TreeMap<>());
		return ans;
	}

	static void comb(int target,int[] nums,int remain,List<List<Integer>> ans,
	List<Integer> curr,List<Map<Integer,Integer>> list_of_map,Map<Integer,Integer> currmap)
	{
		if(remain==0)
		{
			List<Integer> sub = new ArrayList<>();
			for(Integer ind: curr) sub.add(nums[ind]);
			if(!list_of_map.contains(currmap)){
				ans.add(new ArrayList<>(sub));
				list_of_map.add(new TreeMap<>(currmap));
			}
		}
		for(int i=0;i<nums.length;i++)
		{
			List<Integer> doop = new ArrayList<>(curr);
			
			if(nums[i]<=remain && !doop.contains(i))
			{
				//System.out.println("".repeat(curr.size())+"curr.add("+nums[i]+")");
				doop.add(i);
				currmap.put(i,1);
				comb(target,nums,remain-nums[i],ans,new ArrayList<>(doop),list_of_map,currmap);
				//System.out.println("".repeat(curr.size())+"curr.remove("+nums[i]+")");
				currmap.remove(i);
			}
		}
	}
}