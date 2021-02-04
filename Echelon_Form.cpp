#include <iostream>

const int r = 4;
const int c = 4;

void IsSingular(float tab[r][c]);

void FixRowZero(float tab[r][c]);

void FixRowOne(float tab[r][c]);

void FixRowTwo(float tab[r][c]);

void FixRowThree(float tab[r][c]);

void swap_rows(int index1, int index2, float tab[r][c]);

int main()
{
	
	float arr[r][c] = { {5, 6, 6, 8}, {2, 2, 2, 8}, {6, 6, 2, 8}, {2, 3, 6, 7} }; // det = -8. has inverse

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	IsSingular(arr);

	std::cout << "The matrix after echelon transformation: " << std::endl;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout<<std::endl;
	}
}

void IsSingular(float tab[r][c])
{
	FixRowZero(tab);
	FixRowOne(tab);
	FixRowTwo(tab);
	FixRowThree(tab);

}

void FixRowZero(float tab[r][c])
{
	if (tab[0][0] == 0)
	{
		swap_rows(0, 1, tab);
	}
	if (tab[0][0] == 0)
	{
		swap_rows(0, 2, tab);
	}
	if (tab[0][0] == 0)
	{
		swap_rows(0, 3, tab);
	}
	if (tab[0][0] == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist. " << std::endl;
		return;
	}

	for (int i = 0; i < c; i++)
	{
		tab[0][i] = tab[0][i] / tab[0][0];
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

	if (tab[1][1] == 0)
		swap_rows(1, 2, tab);
	if (tab[1][1] == 0)
		swap_rows(1, 3, tab);
	if (tab[1][1] == 0)
		{
			std::cout << "The matrix is singular. Inverse does not exist." << std::endl;
			return;
		}
// Python: A[1] = A[1] / A[1, 1]
	for (int i = 0; i < c; i++)
	{
		tab[1][i] = tab[1][i] / tab[1][1];
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

	if (tab[2][2] == 0)
		swap_rows(2, 3, tab);
	if (tab[2][2] == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist." << std::endl;
		return;
	}

	for (int i = 0; i < c; i++)
	{
		tab[2][i] = tab[2][i] / tab[2][2];
	}

}

void FixRowThree(float tab[r][c]) 
{
	for (int i = 0; i < c; i++)
	{ 
		tab[3][i] = tab[3][i] - tab[3][2] * tab[2][i];
	}

	if(tab[3][3] == 0)
	{
		std::cout << "The matrix is singular. Inverse does not exist." << std::endl;
		return;
	}

	for (int i = 0; i < c; i++)
	{
		tab[3][i] = tab[3][i] / tab[3][3];
	}

}

void swap_rows(int index1, int index2, float tab[r][c])
{
	for (int i = 0; i < c; i++)
	{
		float temp = tab[index1][i];
		tab[index1][i] = tab[index2][i];
		tab[index2][i] = temp;
	}
}