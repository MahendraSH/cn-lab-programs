#include<bits/stdc++.h>
using namespace std;
char encrypt(char c , int n){
	int result;
	if(isupper(c))
	{
		result = (c-'A'+n)%26 +'A';
	}
	else if (islower(c)){
		result = (c-'a'+n)%26 +'a';
	}
	else {
		result =(c-'0'+n)%10+ '0';
	}
	return (char) result ;
}
		
char dec(char c , int n){
	int result;
	if(isupper(c))
	{
		result = (c-'A'+n +26)%26 +'A';
	}
	else if (islower(c)){
		result = (c-'a'+n +26)%26 +'a';
	}
	else {
		result =(c-'0'+n +10)%10+ '0';
	}
	return (char) result ;
}
int main (){
	string s;
	cout << " Enter the string to encrypt "<<endl;
	cin>>s;
	int n;
	cout << " Enter the adder "<<endl;
	cin>>n;
	
	string ctr="";
	for (int i=0;i<s.size();i++){
		ctr+=  encrypt(s[i],n);
	}
	cout<<"the encryted messge is "<<endl;
	cout<<ctr<<endl;
	cout<< " the decryted message is " <<endl;

        for (int i=0;i<s.size();i++){
		cout << dec(ctr[i],-n);
	}
	return 0;
}
