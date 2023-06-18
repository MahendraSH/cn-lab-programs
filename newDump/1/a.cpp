#include<bits/stdc++.h>
using namespace std;
int find_par(int*a,int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]==1) 
			count++;
	}
	return count%2;
}
int main (){
	int n;
	cout << "Enter the size of bits " <<endl;
	cin >>n;
	int *a = new int [n+1];
	cout << "Enter the bits " <<endl;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cout <<"Enter the parity 1 for odd and 0 for even " <<endl;
	int par;
	cin>> par;
	int sender = find_par(a,n);
	if(sender !=par){
		a[n] =1;
	}
	else {
		a[n]=0;
	}
	cout << "Enter the sender sends the message " <<endl;
	for(int i=0;i<=n;i++){
		cout <<a[i]<< " ";
	}
	int *b = new int[n+1];
	cout << "Enter the reciver side message that is got " <<endl;
	for(int i=0;i<=n;i++){
		cin >>b[i];
	}
	cout<< endl;
	int reciver = find_par(a,n+1);
	if(reciver!=par){
		cout <<" the message is worng "<<endl;
	}
	else {
	        cout << " the message is coorect " <<endl;
		for(int i=0;i<n;i++){
			cout<<b[i] << " " ;
		}
	}
	
		cout<<endl;
		cout<<endl;


	

return 0;
}

