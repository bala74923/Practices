#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row,col;
	printf("Enter the Row\n:");
	scanf("%d",&row);

	printf("Enter the Row\n:");
	scanf("%d",&col);

	int **mat = (int**)malloc(sizeof(int*)*row);
	
	for(int i=0;i<3;i++)
	{
		*(mat+i) = (int*)malloc(sizeof(int)*col);
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",*(mat+i)+j);
		}
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d",*(*(mat+i)+j));
		}
	}
	getchar();
	return 0;
}

