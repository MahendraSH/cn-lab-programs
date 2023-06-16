#include <bits/stdc++.h>
using namespace std;

string encrypt(string s, int n)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            result += ' ';
        }
        else if (isupper(s[i]))
        {
            result += char((s[i] + n - 'A') % 26 + 'A');
        }
        else if (islower(s[i]))
        {
            result += char((s[i] + n - 'a') % 26 + 'a');
        }
        else
        {
            result += char((s[i] + n - '0') % 10 + '0');
        }
    }
    return result;
}

string decryption(string s, int n)
{

    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            result += ' ';
        }
        else if (isupper(s[i]))
        {
            result += char((s[i] + n - 'A' + 26) % 26 + 'A');
        }
        else if (islower(s[i]))
        {
            result += char((s[i] + n - 'a' + 26) % 26 + 'a');
        }
        else
        {
            result += char((s[i] + n - '0' + 10) % 10 + '0');
        }
    }
    return result;
}
int main()
{
    string s;
    cout << "enter text : " << endl;
    getline(cin, s);
    cout << " enter the adder : " << endl;
    int n;

    cin >> n;
    n = n % 26;
    cout << " text : " << s << endl;
    cout << " adder : " << n << endl;
    cout << " encrypted text : " << encrypt(s, n) << endl;
    cout << " decrypted text : " << decryption(encrypt(s, n), -n) << endl;
}
