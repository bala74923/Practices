import java.util.*;
public class permutation 
{
	public static void main(String[] args) {
		String s = "ABC";
		List<String> list = new ArrayList<>();
		getPermutations(s, 0, s.length()-1, list);
		System.out.println(list) ;
	}
	static void getPermutations(String s,int lo,int hi,List<String> list)
	{
		if(lo==hi){
			list.add(s);
			return ;
		}
		for(int i=lo;i<=hi;i++)
		{
			String curr = swap(s,i,lo);
			getPermutations(curr,lo+1, hi, list);
		}
	}
	static String swap(String s,int i,int j)
	{
		char temp = s.charAt(i);
		StringBuilder sb = new StringBuilder(s);
		sb.setCharAt(i, sb.charAt(j));
		sb.setCharAt(j,temp);
		return sb.toString();
	}
}