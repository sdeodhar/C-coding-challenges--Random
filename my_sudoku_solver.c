#include <stdio.h>

int availablity(int sudoku[][9], int row, int col, int num)
{
    int row_Start = (row/3) * 3;
    int col_Start = (col/3) * 3;
    int i, j;

    for( i = 0 ; i < 9; ++i )
    {

        if (sudoku[row][i] == num) {
		return 0;
	}
        if (sudoku[i][col] == num){
		return 0;
	}
        if (sudoku[row_Start + (i%3)][col_Start + (i/3)] == num){
		return 0;
	}


    }

    return 1;
}

int solve_Sudoku(int sudoku[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(sudoku[row][col] != 0)
        {
            if((col+1)<9) 
	    {
		return solve_Sudoku(sudoku, row, col+1);
	    }

            else if((row+1)<9)
	    {
		return solve_Sudoku(sudoku, row+1, 0);
	    }

            else{ return 1;}
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(availablity(sudoku, row, col, i+1))
                {
                    sudoku[row][col] = i+1;

                    if((col+1)<9)
                    {
                        if(solve_Sudoku(sudoku, row, col +1)){ return 1;}
                        else{ sudoku[row][col] = 0;}
                    }

                    else if((row+1)<9)
                    {
                        if(solve_Sudoku(sudoku, row+1, 0)){ return 1;}
                        else{ sudoku[row][col] = 0;}
                    }

                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
    int i, j;
    int Sudoku[9][9];

    printf("enter the sudoku: \n");

    for(i=0;i<9;i++)
    {

	for(j=0;j<9;j++)
	{
	      printf("(%d, %d): ", i+1, j+1);
	      scanf("%d", &Sudoku[i][j]);
		
		if(Sudoku[i][j]>9){ 
			printf("Value exceeds 9\n Please enter value again... \n");
			if(j)
			{	
				j--;	
			}
			else
			{ 
				i--; 
				j = 9;
			}
		}

		else if(Sudoku[i][j]<0){ 
			printf("Value -ve: incorrect value inserted\n Please enter value again... \n");
			if(j)
			{
				j--;
			}
			else
			{ 
				i--; 
				j = 9;
			}
		}
		
	}
    }

    if(solve_Sudoku(Sudoku, 0, 0))
    {
        printf("\n+-----+-----+-----+-----+\n");
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) 
	    {
		if ((j-1)%3 == 0) 
	    	{
			printf(" || %d", Sudoku[i-1][j-1]);
		}
		else
		{
			printf("|%d", Sudoku[i-1][j-1]);
		}
	    }

            printf("|\n");
            if (i%3 == 0) 
	    {
		printf("+-----+-----+-----+-----+\n");
	    }
        }
    }
 
   else 
    {
	printf("\n\nNO SOLUTION\n\n");
    }

    return 0;
}


