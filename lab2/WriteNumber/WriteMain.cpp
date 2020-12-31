/*
  This is a little test file. You don't needt to use it unless you wish to
  test the functions in WriteNumber.
*/

using namespace std;
#include "WriteNumber.h"

int main(int argc, char *argv[])
{
    WriteNumber wn("file.dat");  // call the constructor.
    wn.writeString("a number ");
    wn.writeInt(33);
    wn.writeInt(-4);
    wn.writeDouble(44.5);
    wn.close();
    return 0; // normal exit
}
