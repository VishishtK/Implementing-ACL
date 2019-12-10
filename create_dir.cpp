#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>

using namespace std;

int main()
{
	string input;
	getline(cin,input);
	mkdir(input.c_str(),0777);
	return 0;
}