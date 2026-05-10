#include <iostream>
using namespace std;

main()
{
    int y = 20;
    int &ref = y;

    cout << "orignal value of y:" << y << endl;
    ref = 30;
    cout << " modifief value of y:" << y << endl;
    
    return 0;

}