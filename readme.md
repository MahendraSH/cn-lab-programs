# cn lab programs

## Q1

```md
1. Write a program to implement the following Error Detection
   Techniques
   a. Single Parity Check
   b. Cyclic R
```

## Q1a.cpp

```md
Simple Parity Check
Simple-bit parity is a simple error detection method that involves adding an extra bit to a data transmission. It works as:

- 1 is added to the block if it contains an odd number of 1’s, and
- 0 is added if it contains an even number of 1’s

This scheme makes the total number of 1’s even, that is why it is called even parity checking.
```

```cpp
//  Simple Parity Check

#include <bits/stdc++.h>
using namespace std;

int findParity(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count++;
        }
    }

    return count % 2 == 0;
}
int main()
{
    int n;
    cout << " Enter the number of bits" << endl;
    cin >> n;
    cout << " Enter the bits of message  from   sender   side  with space  " << endl;
    int *b = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << " Enter the  parity  1 for even or 0 for odd  " << endl;
    int parity;
    cin >> parity;

    int snderSideParity = findParity(b, n);
    cout << " the message send my sender is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    if (snderSideParity != parity)
    {

        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }

    cout << " Enter the bits of message  from reciver  side  with space  " << endl;
    int *a = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    if (parity == findParity(a, (n + 1)))
    {
        cout << " the message is correct" << endl;
        cout << " the message is : ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << findParity(a, (n + 1)) << endl;
        string err = parity ? "even  " : "odd";
        cout << " the message is incorrect" << endl;
        cout << " the  parity" << err << " error " << endl;
    }
}

```

### output :

```md
 Enter the number of bits
5
 Enter the bits of message  from   sender   side  with space
1 0 0 0 1
 Enter the  parity  1 for even or 0 for odd
0
 the message send my sender is
1 0 0 0 1 1
 Enter the bits of message  from reciver  side  with space
1 0 0 0 1 1
 the message is correct
 the message is : 1 0 0 0 1
```

---

## Q1b.cpp

```cpp

```

---

## Q1c.cpp

```cpp

```

---
