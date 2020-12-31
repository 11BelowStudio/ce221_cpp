
#include <iostream>
using namespace std;

main(int argc, char *argv[])
{
    cout << "Hello,";
    if (argc == 1)
    {
        cout << " world";
    }
    else
    {
        for (int i = 1; i<argc; i++)
        {
            cout << ' ' << argv[i];
        }
    }
    cout << endl;
}
