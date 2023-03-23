#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double MEAN(int a[],int n)
{
	double mean=0;
	for(int i=0;i<n;i++)
	{
		mean+=a[i];
	}
	mean=(double)(mean/n);
	
	return mean;
}
double STANDARD_DEVIATION(int a[],int n)
{
	double mean=MEAN(a,n);
	double variance = 0.0;
	for(int i=0;i<n;i++)
	{
		variance+= pow(a[i] - mean , 2);
	}
	return sqrt(variance/n);
}
void Z_normalization(int a[],int n,double output[],double mean,double sd)
{
	  for(int i=0;i<n;i++)
	  {
	      output[i]= (double)(a[i] - mean) / sd;
	  }
}

int main()
{
	float a[]= {20.75,8.3,14.6,7.315,9.8,19.35,6.305,5.985,16.6,6.59,4.785,16.75,6.135,19.85,
    17.85,13.6,7.1,19.2,13.65,19.2,6.785,13,19,5.825,13.8,12.8,9.5,12.5,5.78,10.39,18.35,21.1
    ,19.75,8.43 ,15.35,6.71,10.19,11.65,12.85};
	int n=sizeof(a)/sizeof(a[0]);
    cout<<"Data before normalization : "<<endl;
	for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	} 
    cout<<endl;
	double sum=0.0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	double mean=sum/n;
	double variance = 0.0;
	for(int i=0;i<n;i++)
	{
		variance+= pow(a[i] - mean , 2);
	}
	double sd= sqrt(variance/n);
	double output[n];
    for(int i=0;i<n;i++)
	  {
	      output[i]= (double)(a[i] - mean) / sd;
	  }
	cout<<"Output After Z-Score Normalization : "<<endl;
	for(int i=0;i<n;i++)
		cout<<output[i]<<" ";
	cout<<endl;	
	return 0;
}