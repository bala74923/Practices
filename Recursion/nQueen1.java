package Recursion;
import java.util.*;
public class nQueen1
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the Length of Board n:");
		int n = sc.nextInt();
		String[][] board = getBoard(n);
		print_board(board);
		int ways = getcomb(board,0);
		System.out.println("There are "+ways+" Ways");
		sc.close();
	}
	static int getcomb(String[][] board,int row)
	{                                                                                                                                                                                                                                      
		int  n = board.length;
		int ans = 0;
		if(row>=n) 
		{
			print_board(board);
			return 1;
		}
		for(int i=0;i<n;i++)
		{
			if(!isAttacked(board, row, i))
			{
				board[row][i]="Q";
				ans+= getcomb(board, row+1);
				board[row][i]="-";
			}
		}
		return ans;
	}
	static boolean isAttacked(String[][] board,int i,int j)
	{
		if(isQueenInColumn(board,i,j) || isQueenInDiagonal(board,i,j))
		{
			return true;
		}
		return false;
	}
	static boolean isQueenInColumn(String[][] board,int row,int col)
	{
		for(int i=0;i<row;i++) if(board[i][col].equals("Q")) return true;
		return false;
	}
	static boolean isQueenInDiagonal(String[][] board,int row,int col)
	{
		int n = board.length;
		// top left to Bottom right from diagonal
		for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--) if(board[i][j].equals("Q")) return true;
		// bottom left to top right from diagonal
		for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++) if(board[i][j].equals("Q")) return true;
		return false;
	}
	static void print_board(String[][] board)
	{
		System.out.println("\nBoard is\n====================");
		for(int i=0;i<board.length;i++)
		{
			for(int j=0;j<board[i].length;j++) System.out.print(board[i][j]+" ");
			System.out.println();
		}
		System.out.println("====================");
	}	
	static String[][] getBoard(int n)
	{
		String[][] board = new String[n][n];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) board[i][j] = "-";
		return board;
	}
}