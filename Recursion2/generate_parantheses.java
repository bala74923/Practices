package Recursion2;
import java.util.*;
public class generate_parantheses 
{
	public static void main(String[] args) 
	{
		int n=3;
		List<String> ans = new ArrayList<>();
		generateParantheses(1,n,"()",ans);
		System.out.println(ans);
	}
	static void generateParantheses(int curr,int total,String s,List<String> ans)
	{
		if(curr==total)
		{
			if(!ans.contains(s)) ans.add(s);
			return ;
		}
		generateParantheses(curr+1, total,"("+s+")", ans);
		generateParantheses(curr+1, total,s+"()", ans);
		generateParantheses(curr+1, total,"()"+s, ans);
	}
}

