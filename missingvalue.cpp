#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream fo,f1,f2,f3,f4,f6;
    string s;
    string str;
    string st;
    int i=0;
    f1.open("covid.txt",ios::in);
    fo.open("op2.txt",ios::out);
    fo<<"Missing Values Treatment"<<endl;
    fo<<"2. Delete the entire row"<<endl;
    while(f1>>s)
    {
        if(s!="NA")
        fo<<s<<"\t\t\t\t";
        else{
            f1>>s;
            f1>>s;
            f1>>s;
            i= -1;
        }
        if(i%4==3)
        fo<<endl;
        i++;
    }
    fo<<endl<<endl;
    f1.close();
     f2.open("covid.txt",ios::in);
    i=0;
    int random=55;
    fo<<"2.Replaced by constant value "<<endl;

    while(f2>>str)
    {
        if(str!="NA")
        {
        fo<<str<<"\t\t\t\t";
        }
        else
        {
        fo<<random<<"\t\t\t\t";
        }
        if(i%4==3)
        fo<<endl;
        i++;
    }
    fo<<endl<<endl;
    f3.open("covid.txt",ios::in);
    float sum=0.0;
    fo<<"3.Missing value replaced by the mean"<<endl;
    i=0;
    vector<int> a;
    int cnt=0;
    while(f3>>st)
    {
        if(st!="NA" && i%4==0)
        {
        stringstream g(st);
        int x=0;
        g>>x;
        sum+=x;
        a.push_back(x);
        cnt++;
        }
        
        i++;
    }
    f3.close();
    f4.open("covid.txt",ios::in);
    i=0;
    float mean=sum/cnt;
    while(f4>>st)
    {
        if(st!="NA")
        {
        fo<<st<<"\t\t\t\t";
        }
        else
        fo<<mean<<"\t\t\t\t";
        if(i%4==3)
        fo<<endl;
        i++;
    }
    fo<<"4.Missing value replaced by the median "<<endl;
    sort(a.begin(),a.end());
    int m=(a.size()+1)/2;
    float median=a[m];
    f6.open("covid.txt",ios::in);
    i=0;
    while(f6>>st)
    {
        if(st!="NA")
        {
        fo<<st<<"\t\t\t\t";
        }
        else
        fo<<median<<"\t\t\t\t";
        if(i%4==3)
        fo<<endl;
        i++;
    }
    return 0;
}