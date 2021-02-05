#include <iostream>

const int n = 4;

int i = 0;

void IsSingular(float tab[n][n]);

/*

void IsSingular(float tab[r][c]);

void FixRowZero(float tab[r][c]);

void FixRowOne(float tab[r][c]);

void FixRowTwo(float tab[r][c]);

void FixRowThree(float tab[r][c]);
*/
void swap_rows(int index1, int index2, float tab[n][n]);


int main()
{
	
	float arr[n][n] = { {5, 6, 6, 8}, {2, 2, 2, 8}, {6, 6, 2, 8}, {2, 3, 6, 7} }; // det = -8. has inverse

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	IsSingular(arr);

	std::cout << "The matrix after echelon transformation: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout<<std::endl;
	}
}


void IsSingular(float tab[n][n])
{
	float* pivot = &tab[i][i];

	for(int j = i; j < n; j++)
	{
		if (*pivot == 0)
		{
			swap_rows(i, j+1, tab);
		}
		else 
			break;
	}

	if (*pivot == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist. " << std::endl;
		return;
	}
	// set value of pivot to one

	for (int k = 0; k < n; k++)
	{
		tab[i][k] = tab[i][k] / *pivot;
	}

	// set the sub-diagonal elements to zero
	
	int m = i+1;
	do
	{

		for (int k = 0; k < n; k++)
		{
			tab[m][k] = tab[m][k] - tab[m][i] * tab[i][k];
		}

		m++;

	} while (m < n);
	
	i++;

	if (i >= n)
		return;

	return IsSingular(tab);
}

/*
void IsSingular(float tab[r][c])
{
	FixRowZero(tab);
	FixRowOne(tab);
	FixRowTwo(tab);
	FixRowThree(tab);

}

void FixRowZero(float tab[r][c])
{
	float* pivot = &tab[0][0];

	if (*pivot == 0)
	{
		swap_rows(0, 1, tab);
	}
	if (*pivot == 0)
	{
		swap_rows(0, 2, tab);
	}
	if (*pivot == 0)
	{
		swap_rows(0, 3, tab);
	}
	if (*pivot == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist. " << std::endl;
		return;
	}

	for (int i = 0; i < c; i++)
	{
		tab[0][i] = tab[0][i] / *pivot;
	}
}

void FixRowOne(float tab[r][c])
{
	// First we'll set the sub-diagonal elements to zero, i.e. A[1,0].
	for (int i = 0; i < c; i++)
	{
		tab[1][i] = tab[1][i] - tab[1][0] * tab[0][i];
	}

	for (int i = 0; i < c; i++)
	{
		tab[2][i] = tab[2][i] - tab[2][0] * tab[0][i];
	}

	for (int i = 0; i < c; i++)
	{
		tab[3][i] = tab[3][i] - tab[3][0] * tab[0][i];
	}

	float* pivot = &tab[1][1];

	if (*pivot == 0)
		swap_rows(1, 2, tab);
	if (*pivot == 0)
		swap_rows(1, 3, tab);
	if (*pivot == 0)
		{
			std::cout << "The matrix is singular. Inverse does not exist." << std::endl;
			return;
		}
// Python: A[1] = A[1] / A[1, 1]
	for (int i = 0; i < c; i++)
	{
		tab[1][i] = tab[1][i] / *pivot;
	}

}

void FixRowTwo(float tab[r][c])
{
	for (int i = 0; i < c; i++)
	{
		tab[2][i] = tab[2][i] - tab[2][1] * tab[1][i];
	}

	for (int i = 0; i < c; i++)
	{
		tab[3][i] = tab[3][i] - tab[3][1] * tab[1][i];
	}

	float* pivot = &tab[2][2];

	if (*pivot == 0)
		swap_rows(2, 3, tab);
	if (*pivot == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist." << std::endl;
		return;
	}

	for (int i = 0; i < c; i++)
	{
		tab[2][i] = tab[2][i] / *pivot;
	}

}

void FixRowThree(float tab[r][c]) 
{
	for (int i = 0; i < c; i++)
	{ 
		tab[3][i] = tab[3][i] - tab[3][2] * tab[2][i];
	}

	float* pivot = &tab[3][3];

	if(*pivot == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist." << std::endl;
		return;
	}

	for (int i = 0; i < c; i++)
	{
		tab[3][i] = tab[3][i] / *pivot;
	}

}
*/

void swap_rows(int index1, int index2, float tab[n][n])
{
	for (int i = 0; i < n; i++)
	{
		float temp = tab[index1][i];
		tab[index1][i] = tab[index2][i];
		tab[index2][i] = temp;
	}
}