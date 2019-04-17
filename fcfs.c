#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
void fcfsalgo(){
    int n,status;
    printf("Enter no. of processes :-");
    scanf(" %d",&n);
    int id[n];
    int arriv[n],bust[n];
    int ct[n],tat[n],wt[n];

    for(int i=0;i<n;i++){
        printf("Enter pid, arrival time, bust time %d:- ",n+1);
        scanf(" %d,%d,%d",&id[i],&arriv[i],&bust[i]);
    }
    for(int i=0;i<n;i++){
        int j=0;
        while(j<n){
            if(arriv[i]<arriv[j]){
                arriv[i]^=arriv[j];
                arriv[j]^=arriv[i];
                arriv[i]^=arriv[j];

                id[i]^=id[j];
                id[j]^=id[i];
                id[i]^=id[j];

                bust[i]^=bust[j];
                bust[j]^=bust[i];
                bust[i]^=bust[j];

            }
            j++;
        }
    }
    for(int j=0;j<n;j++){
        printf("P%d %d  %d  %d  %d  %d\n",id[j],arriv[j],bust[j],ct[j],tat[j],wt[j]);
    }

    for(int i=0;i<n;i++){
        if(i==0)
        ct[i]=arriv[i]+bust[i];
        else if(arriv[i]<ct[i-1]){
            ct[i]=bust[i]+ct[i-1];
        }else{
            ct[i]=arriv[i]+bust[i];
        }
        tat[i]=ct[i]-arriv[i];
        wt[i]=tat[i]-bust[i];
    }

    for(int i=0;i<n;i++){
        int j=0,temp;
        while(j<n){
            if(id[i]<id[j]){
                arriv[i]^=arriv[j];
                arriv[j]^=arriv[i];
                arriv[i]^=arriv[j];

                id[i]^=id[j];
                id[j]^=id[i];
                id[i]^=id[j];

                bust[i]^=bust[j];
                bust[j]^=bust[i];
                bust[i]^=bust[j];

            }
            j++;
        }
    }
    for(int j=0;j<n;j++){
        printf("P%d %d  %d  %d  %d  %d\n",id[j],arriv[j],bust[j],ct[j],tat[j],wt[j]);
    }

}
int main(){
    fcfsalgo();
}