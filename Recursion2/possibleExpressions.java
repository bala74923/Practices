import java.util.*;
public class possibleExpressions {
	public static void main(String[] args) {
		List<String> soln = new ArrayList<>();
		String s = "125";
		int target=7;
		getAllPossibleExpressionsToTarget(s,0, soln, target,"");
		System.out.println(soln);
		
	}
	static void getAllPossibleExpressionsToTarget(String s,int curr,List<String> soln,int target,String curr_string)
	{
		String[] arr = {"+","-","*"};
		String current_num = s.charAt(curr)+"";
		if(curr>=s.length()-1)
		{
			curr_string+=current_num;
			System.out.print(curr_string);
			System.out.println("=>"+eval(curr_string));
			if(eval(curr_string)==target) soln.add(curr_string);
			return ;
		}
		for(String op:arr)
			getAllPossibleExpressionsToTarget(s, curr+1,soln,target,curr_string+current_num+op);
	}
	static int eval(String s)
	{
		//System.out.println(s);
		s = doMul(s);
		int ind=0;
		int ans=0;
		while(Character.isDigit(s.charAt(ind))) ans = ans*10 + (int)(s.charAt(ind++)-'0');
		while(ind<s.length())
		{
			char op = s.charAt(ind++);
			int b=0;
			while(ind<s.length() && Character.isDigit(s.charAt(ind))) 
				b = b*10 + (int)(s.charAt(ind++)-'0');
			ans =(op=='+'?ans+b:ans-b);
		}
		return ans;
	}
	static String doMul(String s)
	{
		StringBuilder sb = new StringBuilder(s);
		int ind=0;
		while(ind<sb.length())
		{
			if(sb.charAt(ind)=='*')
			{
				//System.out.println(sb);
				int start = ind-1,end=ind+1;
				while(start>=0 && Character.isDigit(s.charAt(start))) start--;
				while(end<sb.length()&& Character.isDigit(s.charAt(end))) end++;
				int a = Integer.parseInt(sb.substring(start,ind));
				int b = Integer.parseInt(sb.substring(ind+1,end));
				sb.replace(start,end,(a*b)+"");
				ind--;
			}
			ind++;
		}
		return sb.toString();
	}
}
