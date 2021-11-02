//package Recursion2;
import java.util.*;
public class count_nodes_with_highst_score 
{
	public static void main(String[] args) {
		System.out.println();
	}	
	public static int countHighestScoreNodes(int[] parents) {
		Map<Integer,List<Integer>> parent = getmap(parents);
		int max = Integer.MIN_VALUE;
		Map<Integer,List<Integer>> map = new HashMap<>();
		for(int i=0;i<parent.length();i++){
			int c=count(parents,i,parent);
			List<Integer> val = map.getOrDefault(c,new ArrayList<>());
			val.add(c);
			map.put()
			max = Math.max(max,c);
		}
	    return max;
   }
   static int count (int[] parent,int ind,Map<Integer,List<Integer>> map)
   {
	   return parentcount(parent, ind)+childcount(parent, ind);
   }
   static int parentcount(int[] parent,int ind,Map<Integer,List<Integer>> map)
   {
	   int parent_ind = parent[parent[ind]];
	   int childind= map.get(parent_ind).get(0)==parent[ind]?1:0;
	   int childcount = childcount(parent, childind, map)+1;
	   int pcount=0;
	   if(parent_ind!=-1) pcount = parentcount(parent,parent_ind, map);
	   return pcount+childcount;
   }
   static int childcount(int[] parent,int ind,Map<Integer,List<Integer>> map)
   {
	   if(map.get(arr[ind])==null) return 0;
	   int left = childcount(parent, map.get(parent[ind]).get(0), map);
	   int right = childcount(parent, map.get(parent[ind]).get(1), map);
	   return left+right+1;
   }
   static Map<Integer,List<Integer>>  getmap(int[] arr)
   {
	   Map<Integer,List<Integer>> map= new TreeMap<>(); 
	   
	   for(int i=0;i<arr.length;i++)
	   {
		   int child = i,parent = arr[i];
		   List<Integer> list = map.getOrDefault(parent,new ArrayList<Integer>());
		   list.add(child);map.put(parent,list);
	   }
	   System.out.println(map);
	   return map;
   }
}
