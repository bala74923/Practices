// refer https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
package Recursion2;
import java.util.*;
public class possible_string_from_set_of_characters {
	public static void main(String[] args) {
		int k=4;
		List<String> list = new ArrayList<>();
		Set<Character> set = new TreeSet<>();
		set.add('a'); set.add('b');//set.add('c');set.add('d');
		getPossibleStrings(set, list, "", k);
		System.out.println(list);
	}
	static void getPossibleStrings(Set<Character> set,List<String> soln,String s,int k)
	{
		// is valid state
		if(k==s.length())
		{
			soln.add(s);
			return ;
		}
		for(Character ch:set)
		{
			getPossibleStrings(set, soln, s+ch, k);
		}
	}
}