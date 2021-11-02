import java.util.*;

//package Recursion2;
public class combinations_sum 
{
	public static void main(String[] args) 
	{
		int target = 7;
		int[] candidates = {2,3,6,7};
		List<List<Integer>> ans = new ArrayList<>();
		List<Map<Integer,Integer>> map = new ArrayList<>();
		combinations(target,0,ans,map,candidates,new ArrayList<Integer>(),new TreeMap<>());
		System.out.println(ans);
	}
	static void combinations(int target,int sum,List<List<Integer>> ans,
							List<Map<Integer,Integer>> map,int[] candidates,
							List<Integer> curr_list,Map<Integer,Integer> curr_map)
	{
		if(sum==target)
		{
			if(!map.contains(curr_map)) {
				ans.add(new ArrayList<>(curr_list));
				map.add(new TreeMap<>(curr_map));
			}
			return ;
		}
		for(int i=0;i<candidates.length;i++)
		{
			if((candidates[i]+sum)<=target)
			{
				List<Integer> temp_list = new ArrayList<>(curr_list);
				temp_list.add(candidates[i]);
				curr_map.put(candidates[i],curr_map.getOrDefault(candidates[i],0)+1);
				combinations(target, sum+candidates[i], ans, map, candidates, temp_list, curr_map);
				curr_map.put(candidates[i],curr_map.get(candidates[i])-1);
			}
		}
	}
}