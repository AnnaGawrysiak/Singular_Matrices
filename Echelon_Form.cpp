#include <iostream>

const int n = 5;

int i = 0;

void IsSingular(float tab[n][n]);

void swap_rows(int index1, int index2, float tab[n][n]);


int main()
{
	
	float arr[n][n] = { {5, 6, 6, 6, 8}, {2, 2, 2, 7, 8}, {6, 6, 7, 2, 8}, {2, 3, 3, 6, 7}, {3, 4, 5, 6, 7} }; // det = -8. has inverse

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

	return 0;
}


void IsSingular(float tab[n][n])
{
	float* pivot = &tab[i][i];

	for(int j = i+1; j <= n; j++)
	{
		if (*pivot == 0)
		{
			swap_rows(i, j, tab);
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

	for (int k = 0; k <= n; k++)
	{
		tab[i][k] = tab[i][k] / *pivot;
	}

	// set the sub-diagonal elements to zero
	
	int m = i+1;
	
	while (m < n)
	{

		for (int k = 0; k < n; k++)
		{
			tab[m][k] = tab[m][k] - tab[m][i] * tab[i][k];
		}

		m++;
	}
	
	i++;

	if (i >= n)
		return;
		

	return IsSingular(tab);
}

void swap_rows(int index1, int index2, float tab[n][n])
{
	for (int i = 0; i < n; i++)
	{
		float temp = tab[index1][i];
		tab[index1][i] = tab[index2][i];
		tab[index2][i] = temp;
	}
}