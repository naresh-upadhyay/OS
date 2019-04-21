#include<bits/stdc++.h>
using namespace std;
struct process{
    int p,at,bt,ct,tat,wt;
    bool flag=false;
};
typedef struct process pro;
int minat(pro p[],int n){
    int min=INT_MAX,pos=0;
    for(int i=0 ;i<n;i++){
        if(min>p[i].at && p[i].flag==false){
            min=p[i].at;
            pos=i;
        }
    }
    return pos;
}

void rral(pro p[],int n,int tq){
    int i,time=0,temp,qb;
    queue<pro> q;
    q.push(p[minat(p,n)]);
    time=p[minat(p,n)].at;
    p[minat(p,n)].ct=time;
    p[minat(p,n)].tat=p[minat(p,n)].ct-p[minat(p,n)].at;
    p[minat(p,n)].flag=true;
    while(!q.empty()){
        qb=q.front().bt;
        if(qb>tq){
            time+=tq;
            q.front().bt-=tq;
            while(p[minat(p,n)].flag==false && time>=p[minat(p,n)].at){
                q.push(p[minat(p,n)]);
                p[minat(p,n)].flag=true;
            }
            q.push(q.front());
            q.front().flag=true;
        }else{
            time+=q.front().bt;
            q.front().bt=0;
        }
        i=q.front().p-1;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        q.pop();
    }
}
int comp(pro p1,pro p2){
    return p1.p<p2.p;
}
int main(){
    int n,tq;
    cout << "Number of processes and tq :-";
    cin >> n >> tq;
    pro p[n];
    for(int i=0;i<n;i++){
        cout <<"Process "<<i+1<<" at,bt :-";
        cin >> p[i].at >>p[i].bt;
        p[i].p=i+1;
    }
    rral(p,n,tq);
    cout << "p"<<"\t"<<"at" << "\t"<<"bt"<<"\t"<<"ct"<<"\t"<<"tat"<<"\t"<<"wt"<<endl;
    for(int i=0;i<n;i++){
        cout << p[i].p<<"\t"<<p[i].at << "\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }

}