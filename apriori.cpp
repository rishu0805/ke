#include<bits/stdc++.h>
using namespace std;

void subset(string ip,string op,vector<string>& vec)
{
    if(ip.length()==0)
    {
        vec.push_back(op);
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    subset(ip,op1,vec);
    subset(ip,op2,vec);
}
int main()
{
    fstream fo,fin;
    fin.open("data.txt",ios::in);
    fo.open("output.txt",ios::out);
    vector<string> v;
    string s;
    while(getline(fin,s))
    v.push_back(s);
    // vector<string> v{"ACD","BCE","ABCE","BE"};
    int minsup=2;
    unordered_map<string,int> m;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            string str="";
            str+=v[i][j];
            
            if(str==",")
            continue;
            m[str]++;
            
        }
       
    }
    fo<<"Items and their frequency:"<<endl;
    for(auto x:m)
    {
        fo<<x.first<<" "<<x.second;
        fo<<endl;
    }
    
    int j=0;
    vector<string> selected;
    for(auto x:m)
    {
        if(x.second>=minsup)
        {
            selected.push_back(x.first);
        }
    }
    fo<<"Selected Items are:"<<endl;
    for(int i=0;i<selected.size();i++)
    {
        fo<<selected[i];
    }
    fo<<endl;
    vector<string> pairs;
    int z=2;
    for(int i=0;i<selected.size();i++)
    {
        for(int j=i+1;j<selected.size();j++)
        {
            string st=selected[i]+selected[j];
            pairs.push_back(st);
        }
    }
    fo<<"New pairs formed:"<<endl;
    for(int i=0;i<pairs.size();i++)
    {
       fo<<pairs[i]<<", ";
        
    }
    fo<<endl;
    int cnt=1;
    m.clear();
    selected.clear();
    while(pairs[0].size()>=cnt)
    {
        for(int i=0;i<pairs.size();i++)
        {
            bool check=true;
            
            for(int j=0;j<v.size();j++)
            {
                string s2="";
                 string s1="";
                 string s3="";
                s2+=v[j];
                
                for(int k=0;k<pairs[i].size();k++)
                {
                   s1="";
                    
                    s1+=pairs[i][k];
                    s3+=s1;
                    if (s2.find(s1) == string::npos)
                    {
                    check=false;
                    break;
                    }
                    else
                    check=true;
                    
                }
                
                if(check==true)
            {
                
                m[s3]++;
            }
            }
            
        }
     fo<<"Items and their frequency:"<<endl;
    for(auto x:m)
    {
        fo<<x.first<<" "<<x.second;
        fo<<endl;
    }
      unordered_set<string> us;
     for(auto x:m)
        {
            if(x.second>=minsup)
            {   
                selected.push_back(x.first);
            }
        }
        for(int i=0;i<selected.size();i++)
        {
            for(int j=0;j<selected[i].size();j++)
            {
                
                string sttr="";
                sttr+=selected[i][j]; 
                us.insert(sttr);
            }
        }
        fo<<"Selected Items are:"<<endl;
        for(auto i=us.begin();i!=us.end();i++)
        {
            fo<<(*i);
        }
        fo<<endl;
        string strg="";
        for(auto i=us.begin();i!=us.end();i++)
        {
            
            strg+=(*i);
        }
        pairs.clear();
        vector<string>c;
        
        subset(strg,"",c);
    
        // for(int i=0;i<c.size();i++)
        // {
        //     cout<<c[i]<<" ";
        // }
        //  cout<<endl;
         for(int i=0;i<c.size();i++)
         {
             if(c[i].size()==cnt+z)
             {
                 pairs.push_back(c[i]);
             }
         }
         if(pairs.size()==1)
         {
             fo<<"most frequent items are :"<<pairs[0];
             return 0;
         }
         fo<<"New pairs formed:"<<endl;
        for(int i=0;i<pairs.size();i++)
        {
            fo<<pairs[i]<<", ";
        
        }
         fo<<endl;
        
        cnt++;
        m.clear();
        selected.clear();
        us.clear();
        c.clear();
        z--;
    }
    return 0;
} 
