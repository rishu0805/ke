#include <bits/stdc++.h>
using namespace std;
int main()
{
    float active[]= {1,3,5,15,6,23,35,41,43,17,3,1275,1389,3,0,164,16,0,91,5,88,1,23,46,28,58};
	int n=sizeof(active)/sizeof(active[0]);

    float passive[]= {107,87,241,155,234,117,50,81,95,
    186,118,85,240,122,52,151,198,192,109,
    193,175,239,47,142,180,209}; 
   int m=sizeof(passive)/sizeof(passive[0]);
    double asum=0.0;
    double psum=0.0;
    double sq_asum=0.0;
    double sq_psum=0.0;
    for(int i=0;i<n;i++){
        asum+=active[i];
        sq_asum+=(active[i]*active[i]);
    }
    for(int i=0;i<m;i++){
        psum+=passive[i];
        sq_psum+=(passive[i]*passive[i]);
    }

    double ap=0.0;
    for(int i=0;i<n;i++){
        ap+=(active[i]*passive[i]);
    }
    double a=((double)(psum*sq_asum)-(double)(asum*ap))/(n*sq_asum - asum*asum);
    double b=((double)(n*ap)-(double)(asum*psum))/(n*sq_asum- asum*asum);
    cout<<"Regression line is :    y = "<<a<<"x + "<<b<<endl;
    return 0;
}
