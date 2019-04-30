#include <iostream>
#include <stdio.h>
#include <ctime>
//#include <time.h>
using namespace std;
struct tm reiwaZero;
struct tm *localNow;
struct tm *raiwaNow;
int main(int argc, char const *argv[])
{
	/* code */
	::reiwaZero.tm_sec   = 59;
	::reiwaZero.tm_min   = 59;
	::reiwaZero.tm_hour  = 23;
	::reiwaZero.tm_mday  = 30;
	::reiwaZero.tm_mon   = 4;
	::reiwaZero.tm_year  = 2019;
	::reiwaZero.tm_isdst = 0;
	time_t reiwa = std::mktime(&::reiwaZero);
	time_t now = std::time(nullptr);
	struct tm *pnow = localtime(&now);
	pnow->tm_year = pnow->tm_year + 1900;
	pnow->tm_mon = pnow->tm_mon + 1;
	now = std::mktime(pnow);
	double remain = difftime(now, reiwa) + 1;
	::localNow = std::localtime(&now);
	::raiwaNow = std::localtime(&now);
	::raiwaNow->tm_year = ::raiwaNow->tm_year - 2018;
	//printf("%2d/%2d/%2d/%2d:%2d:%2d\n", ::localNow->tm_year,::localNow->tm_mon,::localNow->tm_mday,::localNow->tm_hour, ::localNow->tm_min, ::localNow->tm_sec);
	//printf("%2d/%2d/%2d/%2d:%2d:%2d\n", ::reiwaZero.tm_year,::reiwaZero.tm_mon,::reiwaZero.tm_mday,::reiwaZero.tm_hour, ::reiwaZero.tm_min, ::reiwaZero.tm_sec);
	//printf("%2lf\n",remain/60);
	if (remain < 0)
	{
		remain = remain * -1;
		int hour = remain / 3600;
		int min = remain / 60;
		int day = hour /24;
		int d_hour = hour - day * 24;
		int d_min = min - day * 24 * 60 - hour * 60;
		int d_sec = remain - day * 24 * 60 * 60 - hour * 60 * 60 - min * 60;

		printf("のこり%3d日%2d:%2d:%2d\n",day,d_hour,d_min,d_sec);
	}else{
		//令和構造体を作って、time構造体を入れると令和換算して格納されるようにするといいよね。。。
		if (::raiwaNow->tm_year == 1)
		{
			printf("令和元年%2d月%2d日%2d:%2d:%2dです。\n", ::raiwaNow->tm_mon,::raiwaNow->tm_mday,::raiwaNow->tm_hour,::raiwaNow->tm_min,::raiwaNow->tm_sec);
		}else{
			printf("令和%2d年%2d月%2d日%2d:%2d:%2dです。\n", ::raiwaNow->tm_year, ::raiwaNow->tm_mon,::raiwaNow->tm_mday,::raiwaNow->tm_hour,::raiwaNow->tm_min,::raiwaNow->tm_sec);
		}
	}
	return 0;
}