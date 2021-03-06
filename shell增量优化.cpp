// shell增量优化.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define NUMBER 100000
#define TESTCOUNT 5
bool lt(const int &k, const int &e)
{
	return k < e;
}
void swap(int *h, int i, int j)
{
	int z = h[i];
	h[i] = h[j];
	h[j] = z;
}
void inssort2(int A[], int n, int incr)
{
	int i, j;
	for (i = incr; i < n; i += incr)
		for (j = i; (j > incr) && (lt(A[j], A[j - incr])); j -= incr)
			swap(A, j, j - incr);
}
void shellsort(int A[], int n)
{
	int i, j;
	for (i = n / 2; i > 0; i /= 2)
		for (j = 0; j < i; j++)
			inssort2(&A[j], n - j, i);
	inssort2(A, n, 1);
}
void shellsort1(int A[], int n)
{
	int i, j, k, temp;
	for (i = n / 2; i > 0; i /= 2)
	{
		if (i % 2 == 0) i--;
		for (j = i; j < n; j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}
}
void shellsort2(int A[], int n)
{
	int i, j, k, temp;
	for (i = 1; i <= n / 4; i = i * 2 + 1);
	for (; i > 0; i = (i - 1) / 2)
	{
		for(j=i;j<n;j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}
}
void shellsort3(int A[], int n)
{
	int i, j, k, temp;
	for (i = 1; i <= n / 9; i = i * 3 + 1);
	for (; i > 0; i = i/3)
	{
		for (j = i; j<n; j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}
}
void shellsort4(int A[], int n)
{
	int i, j, k, t, temp;
	int incs[28] = { 262144,229376,200704,175616,153664,134456,117649,32768,28672,25088,21952,19208,16807,4096,3584,3136,2744,2401,512,448,392,343,64,56,49,8,7,1 };
	for (t = 0; t < 28; t++)
	{
		i = incs[t];
		for (j = i; j<n; j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}
}
void shellsort5(int A[], int n)
{
	int i, j, k, t, temp;
	for (t = 1; t*t < n / 4; t += t);
	for (i = n / 4; t > 0; t /= 2, i = t * t - (3 * t) / 2 + 1)
	{
		for (j = i; j<n; j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}
}
void shellsort6(int A[], int n)
{
	int i, j, k, temp;
	for (i = n; i > 1;)
	{
		i = (i < 5) ? 1 : (i * 5 - 1) / 11;
		for (j = i; j<n; j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}
}
void shellsort7(int A[], int n)
{
	int i, j, k, t, temp;
	int incs[16] = { 1391376,463792,198768,86961,33936,13776,4592,1968,861,336,112,48,21,7,3,1 };
	for (t = 0; t < 16; t++)
	{
		i = incs[t];
		for (j = i; j<n; j++)
		{
			temp = A[j];
			for (k = j - i; (k >= 0) && A[k] > temp; k -= i)
			{
				A[k + i] = A[k];
			}
			A[k + i] = temp;
		}
	}

}
int main()
{
	int data[NUMBER] = { 0 };
	int test[NUMBER] = { 0 };
	int i, j;
	double time, average;
	LARGE_INTEGER begin, end, freq;
	for (i = 0; i < NUMBER; i++)
	{
		data[i] = rand() % NUMBER;
	}
	QueryPerformanceFrequency(&freq);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort's average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort1(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Lazarus-Frank)'s average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort2(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Hibbard)'s average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort3(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Knuth)'s average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort4(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Pratt)'s average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort5(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Sedgewick)'s average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort6(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Gonnet)'s average time is:%lf\n", average / TESTCOUNT);
	for (i = 0, average = 0.0; i < TESTCOUNT; i++)
	{
		for (j = 0; j < NUMBER; j++)
			test[j] = data[j];
		QueryPerformanceCounter(&begin);
		shellsort7(test, NUMBER);
		QueryPerformanceCounter(&end);
		time = (end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
		average += time;
		printf("%lf\n", time);
	}
	printf("Shellsort(Incerpj-Sedgewick)'s average time is:%lf\n", average / TESTCOUNT);
	system("pause");
	return 0;
}