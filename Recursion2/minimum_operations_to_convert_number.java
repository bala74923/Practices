/**
 * minimum_operations_to_convert_number
 */
public class minimum_operations_to_convert_number {
	public static void main(String[] args) {
		int[] nums = {1,3};
		int start=6,goal=4;
		System.out.println(minimumOperations(nums,start,goal));
	}
	public static int minimumOperations(int[] nums, int start, int goal) {
		return rec(nums,start,goal,Integer.MAX_VALUE,0);
    }
	static int rec(int[] nums,int start,int goal,int min,int steps)
	{

		if(steps>min) return min;
		if(start==goal) return steps;
		int one=Integer.MAX_VALUE,two=Integer.MAX_VALUE,three=Integer.MAX_VALUE;
		for(int i=0;i<nums.length;i++)
		{
			int curr=nums[i];
			if(i>=steps)one=rec(nums, start^curr, goal, min, steps+1);
			if(start+curr<=goal)two=rec(nums, start+curr, goal, min, steps+1);
			if(start+curr>=goal)three=rec(nums, start-curr, goal, min, steps+1);
		}
		System.out.println("=>".repeat(steps)+start);
		return Math.min(one,Math.min(two,three));
	}
}