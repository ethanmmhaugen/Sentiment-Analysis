#include <iostream>
#include <algorithm>

#include "DSString.h"

using namespace std;

int main()
{ 
DSString test("hello");
cout << test <<endl;
DSString test2("world");
DSString test3 = test + test2;
cout << test3 <<endl;
return 0;
}
