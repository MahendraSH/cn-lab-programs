#include<bits/stdc++.h>
using namespace std;
int find_sum(int * a, int n ) {
	int ans =0;
	for(int i=0;i<n;i++ ) {
		ans += a[i];
	}
	cout<< " sum " << ans<<endl;
	return ans;
}
int c_sender(int* a ,int n ) {
	int ans = ~find_sum(a,n);
	return ans;
}
void c_reciver(int * a, int n ,int sec) {
	int ans= find_sum(a,n) + sec;
	int checksum = ~ans ;
	if ( checksum == 0 ) {
		cout << " correct message " << endl;
	}
	else {
		cout << " checksum error " <<endl;
	}
	return;
}
int main (){
	int n;
	cout << " Entter the size of message " << endl;
	cin>>n;

	int * a= new int [n ];
	cout<< "Enter the message numebrs " <<endl;
	for (int i=0;i <n;i++) 
		cin >>a[i];
	int sender = c_sender(a,n);
	c_reciver(a,n,sender);
	return 0;
}
