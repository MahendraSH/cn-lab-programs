#include<iostream>
using namespace std;

int sender(int arr[], int size){
	int sum=0, checksum;

	for(int i=0; i<size; i++){
		sum += arr[i];
	}

	cout<<"\nSum is: "<<sum;

	checksum = ~sum;

	cout<<"\nChecksum: "<<checksum;

	return checksum;
}

void receive(int arr[], int size, int send){
	int sum=0, checksum;

	for(int i=0; i<size; i++){
		sum += arr[i];
	}

	cout<<"\nSum is: "<<sum;

	sum += send;
	checksum = ~sum;
	
	cout<<"\nChecksum: "<<checksum;

	if(checksum == 0){
		cout<<"\nMessage received correctly";
	}else{
		cout<<"\nerror message received";
	}

}

int main(){

	int size;

	cout<<"Enter size of message: ";
	cin>>size;

	int msg[size];

	cout<<"\nEnter message: ";

	for(int i=0; i<size; i++){
		cin>>msg[i];
	}

	int send = sender(msg, size);
	receive(msg, size, send);

	return 0;
}
