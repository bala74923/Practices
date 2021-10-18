import java.util.*;
public class atoi {
	public static void main(String[] args) {
		System.out.println(myAtoi("345",0));
	}
	static long myAtoi(String s,int index)
	{
		if(index==s.length()-1)
		{
			return (long)(s.charAt(index)-'0');
		}
		return  (long)(((long)(s.charAt(index)-'0'))*Math.pow(10,s.length()-1-index) + myAtoi(s,index+1));
	}
}
// "1234"
// 4,3,2,1