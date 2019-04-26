#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;
int main()
{
	time_t t = time(nullptr);
	cout << "UTC:       " << put_time(gmtime(&t), "%c %Z") << '\n';
	cout << "local:     " << put_time(localtime(&t), "%c %Z") << '\n';
}