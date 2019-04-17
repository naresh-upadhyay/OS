#include<bits/stdc++.h>
using namespace std;
struct banker{
    int p;// no of processes
    int aaloc,baloc,caloc;//allocated resources
    int amaxn,bmaxn,cmaxn;//max no. of resources to be allocate
    int aremn,bremn,cremn;//remaining need of resources to allocate
    bool check=false;
};
typedef struct banker balgo;
int a1=0,b1=0,c1=0;
int processIdCheck(balgo b[],int n){
    for(int i=0;i<n;i++){
        if(a1 >=b[i].aremn && b1 >=b[i].bremn && c1 >=b[i].cremn && !b[i].check)
            return i;
    }
    return -1;
}

void fill(balgo b[],int n){
    for(int i=0;i<n;i++){
        cout <<" allocated resources of process "<<i<<" :-";
        b[i].p=i+1;
        cin >> b[i].aaloc>>b[i].baloc>>b[i].caloc;
        cout <<"max no. of resources to be allocate for process "<<i<<" :-";
        cin >>b[i].amaxn>>b[i].bmaxn>>b[i].cmaxn;
        b[i].aremn=b[i].amaxn-b[i].aaloc;
        b[i].bremn=b[i].bmaxn-b[i].baloc;
        b[i].cremn=b[i].cmaxn-b[i].caloc;
        a1+=b[i].aaloc;
        b1+=b[i].baloc;
        c1+=b[i].caloc;
    }
    int atotal=10,btotal=5,ctotal=7;
    a1=atotal-a1;
    b1=btotal-b1;
    c1=ctotal-c1;
}
void bankeralgo(balgo b[],int n){
    for(int i=0;i<n;i++){
        int id=processIdCheck(b,n);
            if(id!=-1){
                b[id].check=true;
                a1+=b[id].aaloc;
                b1+=b[id].baloc;
                c1+=b[id].caloc;
                cout<<"P"<<id+1<<"->";

            }else
            {
                cout<< "Deadlock\n";
                break;
            }
            
    }
}
int main(){
    int num;
    cout << "Enter number of processes :-";
    cin >> num;
    balgo processes[num];
    fill(processes,num);
    bankeralgo(processes,num);

}
