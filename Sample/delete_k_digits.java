package Sample;
import java.util.*;
/**
 * delete_k_digits
 */
public class delete_k_digits {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a Number:");
		String s = sc.next();
		System.out.println("Enter K value:");
		int k = sc.nextInt();
		System.out.println(cut(s,k));
		sc.close();
	}
	static String cut(String s,int limit)
	{
		if(limit==0) return s;
		if(limit>=s.length()) return "0";
		String ans = "";
		Stack<Integer> stack = new Stack<>();
		int k=0;
		for(int i=0;i<s.length();i++)
		{
			int curr = (int)(s.charAt(i)-'0');
			if(!stack.isEmpty()&&stack.peek()> curr && k<limit)
			{
				stack.pop();k++;
				stack.push(curr);
			}
			else stack.push(curr);
			//System.out.println(stack);
		}
		while(k<limit)
		{
			stack.pop();
			k++;
		}
		while(!stack.isEmpty()) ans+=stack.pop();
		return new StringBuilder(ans).reverse().toString();
	}
}