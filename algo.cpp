#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
void indata();
void bubblesort();
void selectionsort();
void number_counter();
void linearsearch(int key);
void binarysearch(int key);
ifstream read; ofstream write;
int arr[1000];
int main()
{
	indata();
	number_counter();
	bubblesort();
	indata();
	selectionsort();
	linearsearch(2000);
	binarysearch(2000);
	system("pause>0");
}
void bubblesort()
{
	clock_t start = clock(), end;
	for (int i = 1; i < 1000; i++)
	{
		for (int j = 0; j < 1000 - i; j++)
			if (arr[j]>arr[j + 1])
			{
			arr[j] += arr[j + 1];
			arr[j + 1] = arr[j] - arr[j + 1];
			arr[j] -= arr[j + 1];
			}
	}
	end = clock();
	write.open("Bubble_sorted.txt");
	write << (end - start) / double(CLOCKS_PER_SEC) * 1000 << endl;
	for (int i = 0; i < 1000; i++)
	{
		write << arr[i];
		if (i<999) write << " ";
	}
	write.close();
}
void selectionsort()
{
	clock_t start = clock(), end;
	int S_index;
	for (int i = 0; i < 1000-1; i++)
	{
		S_index = i;
		for (int j = i+1; j < 1000; j++)
			if (arr[j]<arr[S_index]) {S_index = j;}
		arr[S_index] += arr[i];
		arr[i] = arr[S_index] - arr[i];
		arr[S_index] -= arr[i];
	}
	end = clock();
	write.open("Selection_sorted.txt");
	write << (end - start) / double(CLOCKS_PER_SEC) * 1000 << endl;
	for (int i = 0; i < 1000; i++)
	{
		write << arr[i];
		if (i<999) write << " ";
	}
	write.close();
}
void number_counter()
{
	int data1,counter=0;
	read.open("DATA.txt");
	read >> data1;
	while (!read.eof())
	{
		read >> data1;
		counter++;
	}
	read.close();
	cout << "count = " << counter;
}
void indata()
{
	read.open("DATA.txt");
	int x;	read >> x;
	for (int i = 0; i < 1000; i++)
	{read >> arr[i];}
	read.close();
}
void linearsearch(int key)
{
	clock_t start = clock(), end;
	bool flag=false;
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i]==key)
		{
			flag = true;
			break;
		}
	}
	end = clock();
	write.open("LinearSearch.txt");
	write << (end - start) / double(CLOCKS_PER_SEC) * 1000 << endl;
	if (flag == true)
	{
		write << "Entry found";
	}
	else write << "Data not found";
	write.close();
}
void binarysearch(int key)
{
	clock_t start = clock(), end;
	bool flag=false;
	int low = 0, high = 1000 - 1, middle;
	while (high >= low)
	{
		middle = (low + high) / 2;
		if (arr[middle] == key)
		{
			flag = true; break;
		}
		else if (arr[middle] > key)
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	end = clock();
	write.open("BinarySearch.txt");
	write << (end - start) / double(CLOCKS_PER_SEC)*1000 << endl;
	if (flag == true)
	{
		write << "Entry found";
	}
	else write << "Data not found";
	write.close();
}

