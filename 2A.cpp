#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);


void bubble(int *a, int n)
{
    for(  int i = 0;  i < n;  i++ )
     {  	 
   	 int first = i % 2; 	 

   	 #pragma omp parallel for shared(a,first)
   	 for(  int j = first;  j < n-1;  j += 2  )
   	   {  	 
   		 if(  a[ j ]  >  a[ j+1 ]  )
   		  {  	 
     			 swap(  a[ j ],  a[ j+1 ]  );
   		  }  	 
   		   }  	 
     }
}


void swap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

int main()
{

    int *a,n;
    cout<<"\n enter total no of elements=>";
    cin>>n;
    a=new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++)
    {
   	 cin>>a[i];
    }
    
    bubble(a,n);
    
    cout<<"\n sorted array is=>";
    for(int i=0;i<n;i++)
    {
   	 cout<<a[i]<<" ";
    }


return 0;
}

/*
OUTPUT 
gescoe@gescoe-OptiPlex-3010:~/Desktop/SamtaHPC$ g++ -o gfg -fopenmp 2A.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop/SamtaHPC$ ./gfg

 enter total no of elements=>42

 enter elements=>19
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

 sorted array is=>0 1 5 6 7 12 13 13 14 18 19 20 22 23 24 25 26 31 33 34 34 35 35 37 38 40 41 41 42 43 45 47 55 56 59 62 66 69 87 87 88 99 
*/
