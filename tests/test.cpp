#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

char *p, *q;

p = new int ;
q = p;
cout << *q << endl;
delete p;
cout << *q << endl;
p = NULL;
cout << *q << endl;



}
