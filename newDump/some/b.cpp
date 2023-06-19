#include<bits/stdc++.h>
using namespace std;
int find_sum(int *a ,int n ) {
	int ans =0;
	for(int i =0;i <n;i++ ) {
		ans+=a[i];
	}
	cout << " the sum : " << ans << endl;
	return ans;
}
int sen_c(int *a,int n){
	return ~find_sum(a,n);
}
void rec_c(int *a,int n ,int sec ) {
	int ans = find_sum(a,n) + sec;
	int ck= ~ ans;
	if (ck ==0 ) {
		cout << " the message is correct " <<endl;
	}
	else {
		cout << " checksum error " <<endl;
	}
	return ;
}


int main (){
	int n;
	cout<< " Enter the message size " <<endl;
	cin >> n;
	int * a =new int [n];
	cout << " Enter the message :"<<endl;
	for (int i=0;i<n;i++) {
		cin >>a[i];
	}
	int sec = sen_c(a,n);
	cout <<" sec_c  " <<sec << endl;
	rec_c(a,n,sec);
	return 0;
}




