#include<bits/stdc++.h>
using namespace std;
struct pcb{
    int p,at,bt,ct,tat;
};
typedef struct pcb process;

bool comp(process p1,process p2){
    return p1.at<p2.at;
}
bool pcomp(process p1,process p2){
    return p1.p<p2.p;
}
bool check(process p1,deque<process> q1){
    for(auto it=q1.begin();it!=q1.end();it++){
        if(it->p == p1.p || p1.bt==0)
            return false;
    }
    return true;
}
int main(){
    int num,tq,time=0;
    deque<process> q;
    cout <<" Enter the number of processes and time quanta:-";
    cin >> num >> tq;
    process pro[num],pr1,pro2[num];
    for (int i=0 ; i < num ; i++ ){
        pro[i].p=i+1;
        cout << "Enter the vlaues of at and bt for process "<< pro[i].p <<" :-";
        cin >> pro[i].at >>pro[i].bt;
        pro2[i].p=pro[i].p;
        pro2[i].bt=pro[i].bt;
        pro2[i].at=pro[i].at;
    }
    sort(pro,pro+num,comp);
    q.push_back(pro[0]);
    time=pro[0].at;
    int pos=0;
    for(int k=0;k<100;k++){
        pr1=q.front();
            if(pr1.bt>=tq){
                time+=tq;
                pr1.bt-=tq;
                pr1.ct=time;
                pr1.tat=time-pr1.at;
                for(int i=0;i<num;i++){
                    if(time>=pro[i].at && check(pro[i],q)  ){
                        q.push_back(pro[i]);
                        cout<<pro[i].p<<"->";
                    }
                }
                q.pop_front();
                if(pr1.bt!=0){
                    cout<<pr1.p<<"->"<<endl;
                    q.push_back(pr1);                    
                }

            }else if(pr1.bt!=0){
                time+=pr1.bt;
                pr1.bt=0;
                pr1.ct=time;
                pr1.tat=time-pr1.at;

                for(int i=0;i<num;i++){
                    if(time>=pro[i].at && check(pro[i],q)  ){
                        cout<<pro[i].p<<"->"<<endl;
                        q.push_back(pro[i]);
                    }
                }
                q.pop_front();
                
            }
            int x=0;
            for(int j=0;j<num;j++){
                if(pro[j].bt!=0)
                 x++;
            }
            if(x==0)
                break;
    }
    sort(pro,pro+num,pcomp);
    sort(pro2,pro2+num,pcomp);
    for(int i=0;i<num;i++){
        cout << pro[i].p<<"\t"<<pro[i].at<<"\t"<<pro2[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].tat<<endl;
    }
}