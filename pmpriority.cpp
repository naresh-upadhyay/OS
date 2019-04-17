// non premtive
#include<bits/stdc++.h>
using namespace std;
struct pcb{
    int p,at,bt,prit,ct,tat;
};
bool comp(pcb p1,pcb p2){
    return p1.prit<p2.prit;
}
bool comp1(pcb p1,pcb p2){
    return p1.p<p2.p;
}
int minat(pcb p[],int n){
    int min=INT_MAX;
    for(int i=0 ;i<n;i++){
        if(min>p[i].at){
            min=p[i].at;
        }
    }
    return min;
}
int main(){
    typedef struct pcb process;
    int num,tq,time=0,trav=0;
    cout <<" Enter the number of processes:-";
    cin >> num;
    process pro[num],pro1[num];
    //0 is high priority
    for (int i=0 ; i < num ; i++ ){
        pro[i].p=i+1;
        cout << "Enter the vlaues of at ,bt, priority for process "<< pro[i].p <<" :-";
        cin >> pro[i].at >>pro[i].bt>>pro[i].prit;
    }
    copy(pro,pro+num,pro1);
    sort(pro,pro+num,comp);
    time=minat(pro,num);
    for(int trav=0;trav<num;trav++){
        if(pro[trav].bt!=0 && pro[trav].at<=time){
            time+=pro[trav].bt;
            pro[trav].bt=0;
            pro[trav].ct=time;
            pro[trav].tat=pro[trav].ct-pro[trav].at;
            trav=-1;
        }
        int c=0;
        for(process x : pro){
            if(x.bt!=0)
                c++;
        }
        if(c==0)
            break;
    }
    sort(pro,pro+num,comp1);
    for(int i=0;i<num;i++){
        cout<<"P"<<pro[i].p<<" \t"<<pro[i].at<<"\t "<<pro1[i].bt<<" \t"<<pro[i].prit<<" \t"<<pro[i].ct<<" \t"<<pro[i].tat<<endl;
    }

}