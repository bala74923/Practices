import java.util.*;
//refer https://www.geeksforgeeks.org/find-all-even-length-binary-sequences-with-same-sum-of-first-and-second-half-bits/
public class even_length_binary_sequence {
	public static void main(String[] args) {
		List<String> soln = new ArrayList<>();
		int n = 3;
		getAllEvenLengthBinarySequence(soln,"", n);
		System.out.println(soln);
	}
	static boolean isValidState(String s,int n)
	{
		if(s.length()==(2*n)) return true;
		return false;
	}
	static boolean isbalanced(String s)
	{
		int leftsum=0,rightsum=0;
		int lo=0,hi = s.length()-1;
		while(lo<hi)
		{
			if(s.charAt(lo++)=='1') leftsum++;
			if(s.charAt(hi--)=='1') rightsum++;
		}
		//System.out.println(s+"L="+leftsum+",R="+rightsum);
		return (leftsum==rightsum);
	}
	static void getAllEvenLengthBinarySequence(List<String> soln,String s,int n)
	{
		if(isValidState(s, n))
		{
			if(isbalanced(s))soln.add(s);
			return ;
		}
		getAllEvenLengthBinarySequence(soln,s+"0", n);
		getAllEvenLengthBinarySequence(soln,s+"1", n);
	}
}
