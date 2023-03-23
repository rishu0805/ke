#include <bits/stdc++.h>
using namespace std;
int main()
{   
   
    vector<int> a{1,3,5,15,6,23,35,41,43,17,3,12,13,3,0,164,16,0,91,5,88,1,23,46,28,58};
    
    int mn=*min_element(a.begin(),a.end());
    int mx=*max_element(a.begin(),a.end());
    int n=a.size();
    
    cout<<"enter number of clusters you want : ";
    int c;
    cin>>c;
    cout<<"now select "<<c<<" centroids"<<endl;
    vector<double> random;
    int i=0;
    while(i<c){
        int x=rand()%mx;
        if(find(a.begin(),a.end(),x)==a.end()){
            random.push_back(x);
            cout<<x<<endl;
            i++;
        }
    }
    vector<vector<int>> prev(c);
   
    for(int i=0;i<n;i++){
        int min_idx=-1;
        int min_ele=INT_MAX;
        for(int j=0;j<c;j++){
            if(abs(a[i]-random[j])<min_ele){
                min_idx=j;
                min_ele=abs(a[i]-random[j]);
            }
        }
        
        prev[min_idx].push_back(a[i]);
    }
    vector<vector<int>> curr(prev.begin(),prev.end());
    int count=1;
    int flag=0;
    
    while(true){
        flag==1;
        prev=curr;
        curr.clear();
        curr.resize(c);
        for(int i=0;i<prev.size();i++){
            double mean=0.0;
            for(int j=0;j<prev[i].size();j++){
                mean+=prev[i][j];
            }
            mean=(mean/prev[i].size());
            double n=0.0;
            double sd=0.0;
            for(int j=0;j<prev[i].size();j++){
                n+=((prev[i][j]-mean)*(prev[i][j]-mean));
            }
            sd=sqrt(n/(prev[i].size()-1));
            random[i]=sd;
        }
        for(int k=0;k<random.size();k++){
            cout<<"random values generated in "<<count<<" iteration "<<"for centroid "<<(k+1)<<" is : ";
            cout<<random[k]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            int min_idx=-1;
            int min_ele=INT_MAX;
            for(int j=0;j<c;j++){
                if(abs(a[i]-random[j])<min_ele){
                    min_idx=j;
                    min_ele=abs(a[i]-random[j]);
                }
            }
            curr[min_idx].push_back(a[i]);
        }
        count++;
        if(curr==prev){
            break;
        }
    }
    cout<<"At "<<count<<"th iteration we will get same values for  particular centroid"<<endl;    
}
