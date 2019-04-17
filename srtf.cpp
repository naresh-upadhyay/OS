#include<bits/stdc++.h>
using namespace std;
int maxat(map<int, pair<int,int>> m){
    int sz=m.size(),maxx=0,t=1;
    for(auto it=m.cbegin();it!=m.cend();++it){
        if((it->second).first>maxx){
            maxx=(it->second).first;
            t=(it->first);
        }
    }
    return t;
}
int minat(map<int, pair<int,int>> m){
    int sz=m.size(),min=INT_MAX,t=1;
    for(auto it=m.cbegin();it!=m.cend();++it){
        if((it->second).first<min && (it->second).second!=0){
            min=(it->second).first;
            t=(it->first);
        }
    }
    return t;
}

int minbt(map<int, pair<int,int>> m){
    int min=INT_MAX,mat=INT_MAX,t=1;
    for(auto it=m.cbegin();it!=m.cend();++it){
        if((it->second).second<min && (it->second).second!=0){
            min=(it->second).second;
            t=(it->first);
        }
    }
    for(auto ite=m.cbegin();ite!=m.cend();++ite){
        if(mat>ite->second.first && (ite->second).second==min ){
            mat=ite->second.first;
            t=(ite->first);
        }
    }

    return t;
}
void func(map<int, pair<int,int>> &m,map<int, int> &ctm,int &time){
    int min;
    map<int, pair<int,int>> mp;
    for(auto it=m.cbegin();it!=m.cend();++it){
        if(it->second.first<=time){
            mp[it->first].first=(it->second).first;
            mp[it->first].second=(it->second).second;
        }
    }
    time++;
    m[minbt(mp)].second-=1;
    ctm[minbt(mp)]=time;
}


int main(){
    int num,at,bt;
    map<int,pair<int,int> > smp,out;
    map<int,int> ctmp;
    int time=0;
    cout<<"Enter the number of processes :-";
    cin>>num;
    for(int i=1;i<=num;i++){
        cout<<"P"<<i<<" at and bt:-";
        cin>>at>>bt;
        smp[i].first=at;
        smp[i].second=bt;
    }
    out=smp;
    int j=1,temp;
    time=smp[minat(smp)].first;
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
        if(time > smp[maxat(smp)].first){
            temp=smp[minbt(smp)].second;
            time+=temp;
            ctmp[minbt(smp)]=time;
            smp[minbt(smp)].second=0;
        }else if(time==smp[minat(smp)].first){
                time+=1;
                ctmp[minat(smp)]=time;
                smp[minat(smp)].second-=1;
        }else{
            if(time <=smp[maxat(smp)].first){
                func(smp,ctmp,time);
            }
        }

    }
    for(auto it=smp.cbegin();it!=smp.cend();++it){
        int at1=it->second.first,bt1=out[(it->first)].second;
        int ct=ctmp[(it->first)],tat=(ct-at1),wt=(tat-bt1);
        cout <<"P"<<it->first<<"\t"<<at1<<"\t"<<bt1<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<endl;
    }
}