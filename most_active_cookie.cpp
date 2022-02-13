#include <iostream>
#include "cookie.h"
#include <string.h>

int main(int argc, char *argv[]){	
	//check parameters
	if(argc != 4 || strcmp(argv[2], "-d") != 0){
		cout<<"Invalid arguments!\n";
		cout<<"Please use the following format: \"./most_active_cookie [path of log file] -d [yyyy-mm-dd]\"\n";
		return 0;
	}
	
	//create cookie object
	cookie cookie_log1(argv[1], argv[3]);
	
	//print most active cookies
	vector<string> cookies = cookie_log1.most_active_cookie();
	for(int i=0; i<cookies.size(); i++) cout<<cookies[i]<<"\n";
}
