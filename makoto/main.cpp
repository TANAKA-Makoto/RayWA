#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	time_t now = std::time(nullptr);
	struct tm* localNow = std::localtime(&now);
	printf("%2d\n", localNow->tm_hour);
	return 0;
}