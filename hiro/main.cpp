#include <iostream>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
int main()
{
	time_t now = time(NULL);

	time_t reiwa = time(NULL);
	struct tm *preiwa = localtime(&reiwa);
	preiwa->tm_year = 2019 - 1900;
	preiwa->tm_mon = 4;
	preiwa->tm_mday = 1;
	preiwa->tm_hour = 0;
	preiwa->tm_min = 0;
	preiwa->tm_sec = 0;
	reiwa = _mktime32(preiwa);

	int diff, h, m, s;
	while (true) {
		now = time(NULL);
		diff = reiwa - now;
		h = 0;
		m = 0;
		s = 0;

		while (diff >= 3600) {
			diff -= 3600;
			h++;
		}
		while (diff >= 60) {
			diff -= 60;
			m++;
		}
		s = diff;
		printf("—ß˜a‚Ü‚Å‚ ‚Æ%dŠÔ%d•ª%d•bI\n", h, m, s);
		Sleep(1000);
	}

	return 0;