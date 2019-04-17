//round robin 
#include<bits/stdc++.h>
using namespace std;
void func(map<int, pair<int,int>> &m,map<int, int> &ctm,int tq,int &time){
    int min;
    map<int, pair<int,int>> mp;
    for(auto it=m.cbegin();it!=m.cend();++it){
        if(it->second.first<=time){
            mp[it->first].first=(it->second).first;
            mp[it->first].second=(it->second).second;
        }
    }
    time++;
}


int main(){
    int num,tq,at,bt;
    map<int,pair<int,int> > smp,out;
    map<int,int> ctmp;
    int pro[100];
    int time=0;
    cout<<"Enter the number of processes and time quanta :-";
    cin>>num>>tq;
    for(int i=1;i<=num;i++){
        cout<<"P"<<i<<" at and bt:-";
        cin>>at>>bt;
        smp[i].first=at;
        smp[i].second=bt;
    }
    while(1){
        int n=0;
        for(auto it=smp.cbegin();it!=smp.cend();++it){
            int p=it->second.second;
            if(p!=0){
                n=p;
            }
        }
        if(n==0)
            break;
        

    }
    for(auto it=smp.cbegin();it!=smp.cend();++it){
        int at1=it->second.first,bt1=out[(it->first)].second;
        int ct=ctmp[(it->first)],tat=(ct-at1),wt=(tat-bt1);
        cout <<"P"<<it->first<<"\t"<<at1<<"\t"<<bt1<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<endl;
    }
}