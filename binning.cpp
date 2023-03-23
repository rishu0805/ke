#include<bits/stdc++.h>
using namespace std;

int main()
{
	float a[]= {20.75,8.3,14.6,7.315,9.8,19.35,6.305,5.985,16.6,6.59,4.785,16.75,6.135,19.85,
    17.85,13.6,7.1,19.2,13.65,19.2,6.785,13,19,5.825,13.8,12.8,9.5,12.5,5.78,10.39,18.35,21.1
    ,19.75,8.43 ,15.35,6.71,10.19,11.65,12.85};
	int n=sizeof(a)/sizeof(a[0]);
	int bin_size=5;
	sort(a,a+n);
    cout<<"Sorted data before binning : "<<endl;
	for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	} 
    cout<<endl;
    
	//binning using mean
	float op1[n]={0.0};
    for(int i=0;i<n;i=i+bin_size)
	 {
	 	 float sum=0;
	 	 for(int j=i;j<i+bin_size;j++)
	 	 {
	 	 	   sum+=a[j];
		  }
		  float bmean=sum/bin_size;
		  for(int k=i;k<i+bin_size;k++)
		  {
		  	 op1[k]=bmean;
		  }
	 }
	cout<<"After applying bin mean smoothing "<<endl;
	for(int i=0;i<n;i++)
    {
    	cout<<op1[i]<<" ";
	} 
    cout<<endl;
	
	//binnig using median
	float op2[n] ={0.0};
	 for(int i=0;i<n;i=i+bin_size)
	 {
	 	   float arr[bin_size];
	 	   int j=0;
		  for(int k=i;k<i+bin_size;k++)
		  {
		  	 arr[j++]=a[k];
		  }
          int mid=bin_size/2;
		  float median=arr[mid] ;
		  for(int k=i;k<i+bin_size;k++)
		  {
		  	 op2[k]=median;
		  }
	 }
	cout<<"After applying bin median smoothing :"<<endl;
	for(int i=0;i<n;i++)
    {
    	cout<<op2[i]<<" ";
	} 
    cout<<endl;
	
	//binning using Boundary value
	float op3[n]={0.0};
    for(int i=0;i<n;i=i+bin_size)
	 {
	 	   float arr[bin_size];
	 	   int j=0;
		  for(int k=i;k<i+bin_size;k++)
		  {
		  	 arr[j++]=a[k];
		  }
    		 float b=arr[0];
    		 float c=arr[bin_size-1];
		  for(int k=i;k<i+bin_size;k++)
		  {
		  	    if( abs(a[k] - b )  < abs(a[k] - c ) )
		  	    	op3[k]=b;
		  	    else
		  	    	op3[k]=c;
		  }
	 }
	cout<<"After applying bin boundary smoothing:"<<endl;
	for(int i=0;i<n;i++)
    {
    	cout<<op3[i]<<" ";
	} 
    cout<<endl;
	
	return 0;	
}