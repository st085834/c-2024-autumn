#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

int* initMass(int n)
{
	int* res = (int*)malloc(sizeof(int) * n);
	printf("%s\n", "���� ������ ������ ������ � ���������� � ������� 2, ����� � 1.");
	bool f = true;
	while (f == true)
	{
		int b = 0;
		scanf_s("%d", &b);
		if (b == 2)
		{
			printf("%s\n", "������� ������");
			for (int i = 0; i < n; ++i)
			{
				scanf_s("%d", &res[i]);
			}
			f = false;
			return res;
		}
		else if (b == 1)
		{
			printf("%s\n", "���� ������ ������ �������� ������ � ������� 2, ����� � 1 (������ ����� ����� ������� ��������� �����).");
			int c = 0;
			scanf_s("%d", &c);
			if (c == 2)
			{
				printf("%s\n", "������� �������� � ������� ��������� ������");
				int mn1 = 0;
				int mx1 = 0;
				scanf_s("%d", &mn1);
				scanf_s("%d", &mx1);
				int mx = (int)fmax(mn1, mx1);
				int mn = (int)fmin(mn1, mx1);
				for (int i = 0; i < sizeof(res); ++i)
				{
					res[i] = rand() % (mx - mn + 1) + mn;
				}
				printf("\n");
				printf("%s\n", "��������������� ������:");
				for (int i = 0; i < n; ++i)
				{
					printf("%d ", res[i]);
				}
				printf("\n");
				f = false;
				return res;
			}
			else if (c == 1)
			{
				for (int i = 0; i < n; ++i)
				{
					res[i] = rand();
				}
				printf("\n");
				printf("%s\n", "��������������� ������:");
				for (int i = 0; i < n; ++i)
				{
					printf("%d ", res[i]);
				}
				printf("\n");
				f = false;
				return res;
			}
			else
			{
				printf("%s\n", "���� �� ���������, ��������� �������");
			}
		}
		else
		{
			printf("%s\n", "���� �� ���������, ��������� �������");
		}
	}
}

void menu()
{
	printf("\n");
	printf("%s\n", "������� �����, ��������������� ������ ����������� ��������:");
	printf("%s\n", "1 - ���������� �������� � ������ �������");
	printf("%s\n", "2 - ���������� �������� � ����� �������");
	printf("%s\n", "3 - �������� ������� �������� �������");
	printf("%s\n", "4 - �������� ���������� �������� �������");
	printf("\n");
}

void addBeg(int* a, int n)
{
	int* res = (int*)malloc(sizeof(int) * (n + 1));
	printf("%s\n", "������� �������");
	scanf_s("%d", &res[0]);
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		res[i + 1] = a[i];
	}
	printf("%s\n", "������������ ������:");
	for (int i = 0; i < n + 1; ++i)
	{

		printf("%d ", res[i]);
	}
	printf("\n");
}

void addEnd(int* a, int n)
{
	int* res = (int*)malloc(sizeof(int) * (n + 1));
	printf("%s\n", "������� �������");
	scanf_s("%d", &res[n]);
	for (int i = 0; i < n; ++i)
	{
		res[i] = a[i];
	}
	printf("%s\n", "������������ ������:");
	for (int i = 0; i < n + 1; ++i)
	{

		printf("%d ", res[i]);
	}
	printf("\n");
}

void delBeg(int* a, int n)
{
	int* res = (int*)malloc(sizeof(int) * (n - 1));
	for (int i = 0; i < n - 1; ++i)
	{
		res[i] = a[i + 1];
	}
	printf("%s\n", "������������ ������:");
	for (int i = 0; i < n - 1; ++i)
	{
		printf("%d ", res[i]);
	}
	printf("\n");
}

void delEnd(int* a, int n)
{
	int* res = (int*)malloc(sizeof(int) * (n - 1));
	for (int i = 0; i < n - 1; ++i)
	{
		res[i] = a[i];
	}
	printf("%s\n", "������������ ������:");
	for (int i = 0; i < n - 1; ++i)
	{
		printf("%d ", res[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int* a = nullptr;
	int n = 0;
	printf("%s\n", "������� ����� ��������� ������� (����������� �����).");
	scanf_s("%d", &n);
	bool f = true;
	while (f == true)
	{
		if (n > 0)
		{
			a = initMass(n);
			f = false;
		}
		else
		{
			printf("%s\n", "���� �� ���������, ��������� �������");
		}
	}
	menu();
	int g = 0;
	scanf_s("%d", &g);
	printf("\n");
	switch(g)
	{
		case 1:
			addBeg(a, n);
			break;
		case 2:
			addEnd(a, n);
			break;
		case 3:
			delBeg(a, n);
			break;
		case 4:
			delEnd(a, n);
			break;
		default:
			break;
	}
	return 0;
}