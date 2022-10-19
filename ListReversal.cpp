#include <bits/stdc++.h>
using namespace std;
 
int main()
{     
    // Creating a list
    list<int> myList;
 
    // Adding elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
 
    // Initial list:
    cout << "Initial List: ";
    for (auto itr = myList.begin(); itr != myList.end(); itr++)
        cout << *itr << " ";
 
    // Reversing the list
    myList.reverse();
 
    // List after reversing the order of elements
    cout << "\n\nList after reversing: ";
    for (auto itr = myList.begin(); itr != myList.end(); itr++)
        cout << *itr << " ";
 
    return 0;
}
