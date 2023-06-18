#include<iostream>
#define BUCKET_SIZE 512
using namespace std;

void leakBkt(int genPkt, int op){
	if(genPkt > BUCKET_SIZE){
		cout<<"\nBucket overflow"	
	}else{
		while(genPkt > op){
			cout<<"\nbytes transferred: "<<op;
			genPkt -= op;
		}

		cout<<"\nlast bytes sent: "<<genPkt;
		cout<<"\nbucket transfer complete";
	}
}

int main(){
	int op, genPkt;

	cout<<"Enter output size: ";
	cin>>op;

	for(int i=0; i<5; i++){
		genPkt = rand()%1000;
		cout<<"\nGenrated packet: "<<genPkt;
		leakBkt(genPkt, op);
	}
}
