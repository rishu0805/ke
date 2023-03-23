#include<iostream>
using namespace std;
int main()
{
	float a[]= {20.75,8.3,14.6,7.315,9.8,19.35,6.305,5.985,16.6,6.59,4.785,16.75,6.135,19.85,
    17.85,13.6,7.1,19.2,13.65,19.2,6.785,13,19,5.825,13.8,12.8,9.5,12.5,5.78,10.39,18.35,21.1
    ,19.75,8.43 ,15.35,6.71,10.19,11.65,12.85};
	int n=sizeof(a)/sizeof(a[0]);
    cout<<"Data before normalization: "<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	} cout<<endl;
    int j=1;
    double output[n];
    double ans;
    for(int i=0;i<n;i++)
	{
        if(a[i]<10 && a[i]>1)
		ans=((double)a[i]/10);
        else if(a[i]>=10 && a[i]<100)
        ans=((double)a[i]/100);
        else
        ans=a[i];
		output[i]=ans;
	}
    cout<<"After decimal-scaling normalization : "<<endl;
	for(int i=0;i<n;i++)
    {
    	cout<<output[i]<<" ";
	} cout<<endl;
    return 0;
}