#include<bits/stdc++.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;
sem_t mutx;
sem_t wrt ;
int readcount=0;
string ident="Naresh upadhay";
void* writer(void *arg){
    sem_wait(&wrt);
    sem_wait(&mutx);
    string s;
    cout << "write :-";
    cin >>s;
    ident=ident+" "+ s;
    cout<<ident<<endl;
    sleep(4);
    //cout << "writer exit critical section\n";
    sem_post(&mutx);
    sem_post(&wrt);
}
void* reader(void *b){
    sem_wait(&mutx);
        readcount++;
        //cout<<"Reader in critical section \n";        
        if(readcount==1){
            sem_wait(&wrt);
        }
    sem_post(&mutx);
        cout <<ident<<endl;
        sleep(4);

    sem_wait(&mutx);
        readcount--;
        //cout<<"Reader exit critical section \n";        
        if(readcount==0){
            sem_post(&wrt);
        }
    sem_post(&mutx);
}
int main(){
    int num;
    sem_init(&mutx,1,1);
    sem_init(&wrt,1,1);
    cout << "Enter the number of reader / writer thread ";
    cin >> num;
    pthread_t wrthred[num];
    for (int i=0;i<num;i+=2){
        pthread_create(&wrthred[i],NULL,writer,NULL);
        pthread_create(&wrthred[i+1],NULL ,reader,NULL);
    }
    for (int j=0;j<num;j++){
        pthread_join(wrthred[j],NULL);
    }
    pthread_exit(NULL);
}