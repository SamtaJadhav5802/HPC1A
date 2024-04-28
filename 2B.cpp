#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;


void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

void mergesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
    	mid=(i+j)/2;
   	 
    	#pragma omp parallel sections
    	{

        	#pragma omp section
        	{
            	mergesort(a,i,mid);   	 
        	}

        	#pragma omp section
        	{
            	mergesort(a,mid+1,j);    
        	}
    	}

    	merge(a,i,mid,mid+1,j);    
	}

}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[1000];    
	int i,j,k;
	i=i1;    
	j=i2;    
	k=0;
    
	while(i<=j1 && j<=j2)    
	{
    	if(a[i]<a[j])
    	{
        	temp[k++]=a[i++];
    	}
    	else
    	{
        	temp[k++]=a[j++];
    }    
	}
    
	while(i<=j1)    
	{
    	temp[k++]=a[i++];
	}
   	 
	while(j<=j2)    
	{
    	temp[k++]=a[j++];
	}
   	 
	for(i=i1,j=0;i<=j2;i++,j++)
	{
    	a[i]=temp[j];
	}    
}


int main()
{
	int *a,n,i;
	cout<<"\n enter total no of elements=>";
	cin>>n;
	a= new int[n];

	cout<<"\n enter elements=>";
	for(i=0;i<n;i++)
	{
    	cin>>a[i];
	}
   //	 start=.......
//#pragma omp…..
	mergesort(a, 0, n-1);
//          stop…….
	cout<<"\n sorted array is=>";
	for(i=0;i<n;i++)
	{
    	cout<<a[i]<<" ";
	}
  	// Cout<<Stop-Start
	return 0;
}

/*
OUTPUT
gescoe@gescoe-OptiPlex-3010:~/Desktop/SamtaHPC$ g++ -o gfg -fopenmp 2B.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop/SamtaHPC$ ./gfg

enter total no of elements=>50

enter elements=>33
14
23
34
55
31
1
5
6
7
12
13
56
33
38
35
24
25
22
18
20
13
40
41
42
35
66
34
37
88
69
45
47
41
43
59
62
87
0 
99
26
87
49
77
72
76
97
34
31
98

sorted array is=>0 1 5 6 7 12 13 13 14 18 20 22 23 24 25 26 31 31 33 33 34 34 34 35 35 37 38 40 41 41 42 43 45 47 49 55 56 59 62 66 69 72 76 77 87 87 88 97 98 99 
*/


