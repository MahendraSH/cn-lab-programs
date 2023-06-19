#include<bits/stdc++.h>
using namespace std;
string enc(string s,int n );
string dec(string s,int n );

string enc(string s,int n){
	string r="";
	for(auto i : s){
		if(i == ' ' ){
			r+=i;
		}
		else if( isupper(i)) {
			r+=char( (i-'A'+n)%26 +'A');
		}
		else if(islower(i)){
			r+=char((i-'a'+n)%26+'a');
		}
		else {
			r+=char( (i-'0'+n)%10+'0');
		}

	}
	return r;
}

string dec(string s,int n){
	string r="";
	for(auto i : s){
		if(i == ' ' ){
			r+=i;
		}
		else if( isupper(i)) {
			r+=char( (i-'A'+n+26)%26 +'A');
		}
		else if(islower(i)){
			r+=char( (i-'a'+n+26)%26+'a');
		}
		else {
			r+=char( (i-'0'+n+10)%10+'0');
		}

	}
	return r;
}

int main (){
	string s;
	cout << " Enter the message " << endl;
	getline(cin,s);
	cout<< "Enter the adder " << endl;
	int n;
	cin >>n;
	string ctr= enc(s,n);
	cout << " The enc mess = " << ctr<< endl;
	cout << " dec mess = "<< dec(ctr,-n) <<endl;
	return 0;
}


