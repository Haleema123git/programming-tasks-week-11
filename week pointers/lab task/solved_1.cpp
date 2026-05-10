#include <iostream>
using namespace std;

main()
{
    int arr [5] = {8,5,8,7,5};
    int *ptr = arr;
    for(int i = 0; i < 5; i++)
    {
        cout << "element" << i << ":" << *(ptr + i) << endl;
    } 
    return 0;
}