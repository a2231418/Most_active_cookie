#include <assert.h>
#include "cookie.h"
#include <iostream>
#include <string.h>
using namespace std;

void TESTCookie1(){
	cookie test1("cookie_log.csv", "2018-12-07");
	vector<string> cookie1 = test1.most_active_cookie();
	assert(strcmp(cookie1[0].c_str(), "4sMM2LxV07bPJzwf") == 0);
}

void TESTCookie2(){
	cookie test1("cookie_log.csv", "2018-12-08");
	vector<string> cookie1 = test1.most_active_cookie();
	assert(strcmp(cookie1[0].c_str(), "fbcn5UAVanZf6UtG") == 0);
	assert(strcmp(cookie1[1].c_str(), "4sMM2LxV07bPJzwf") == 0);
	assert(strcmp(cookie1[2].c_str(), "SAZuXPGUrfbcn5UA") == 0);
}

void TESTCookie3(){
	cookie test1("cookie_log.csv", "2018-12-09");
	vector<string> cookie1 = test1.most_active_cookie();
	assert(strcmp(cookie1[0].c_str(), "AtY0laUfhglK3lC7") == 0);
}

int main()
{
	TESTCookie1();
	TESTCookie2();
	TESTCookie3();
	cout<<"Test Successful!\n";
}
