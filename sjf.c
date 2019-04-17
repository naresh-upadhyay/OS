#include<stdio.h>
#include<stdlib.h>
int min(int arr[],int siz){
    int small=arr[0],pos=0;
    for(int i=0;i<siz;i++){
        if(arr[i]<small){
            small=arr[i];
            pos=i;
        }
    }
    return pos;
}
int main(){
    int num;
    printf("Enter the no. of processes:-");
    scanf("%d",&num);
    int p[num],at[num],bt[num],ct[num],tat[num],wt[num];
    int at1[num],p1[num],bt1[num];
    for(int i=0;i<num;i++){
        printf("Enter the values of AT,BT :-");
        scanf(" %d,%d",&at[i],&bt[i]);
        p[i]=i+1;
        p1[i]=i+1;
        at1[i]=at[i];
        bt1[i]=bt[i];
    }
    for(int i=0;i<num;i++){
        int j=0;
        while(j<num){
            if(bt[i]<bt[j]){
                bt[i]^=bt[j];
                bt[j]^=bt[i];
                bt[i]^=bt[j];

                at[i]^=at[j];
                at[j]^=at[i];
                at[i]^=at[j];

                p[i]^=p[j];
                p[j]^=p[i];
                p[i]^=p[j];

            }
            j++;
        }
    }

    for(int i=0;i<num;i++){
        int j=0;
        while(j<num){
            if(at1[i]<at1[j]){
                at1[i]^=at1[j];
                at1[j]^=at1[i];
                at1[i]^=at1[j];

                p1[i]^=p1[j];
                p1[j]^=p1[i];
                p1[i]^=p1[j];

                bt1[i]^=bt1[j];
                bt1[j]^=bt1[i];
                bt1[i]^=bt1[j];


            }
            j++;
        }
    }
    int temp;
    for(int i=0;i<num;i++){
        int mp=min(at,num);
            ct[mp]=at[mp]+bt[mp];
            temp=ct[mp];
        if(i!=mp){
            ct[i]=bt[i]+temp;
        }
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(int i=0;i<num;i++){
        int j=0;
        while(j<num){
            if(p[i]<p[j]){
                bt[i]^=bt[j];
                bt[j]^=bt[i];
                bt[i]^=bt[j];

                at[i]^=at[j];
                at[j]^=at[i];
                at[i]^=at[j];

                p[i]^=p[j];
                p[j]^=p[i];
                p[i]^=p[j];

                ct[i]^=ct[j];
                ct[j]^=ct[i];
                ct[i]^=ct[j];
 
                tat[i]^=tat[j];
                tat[j]^=tat[i];
                tat[i]^=tat[j];
           }
            j++;
        }
    }
        for(int j=0;j<num;j++){
        printf("P%d %d  %d  %d  %d  %d\n",p[j],at[j],bt[j],ct[j],tat[j],wt[j]);
    }


}