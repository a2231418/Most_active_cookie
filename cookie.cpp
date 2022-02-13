#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <assert.h>
#include "date_check.h"
#include "cookie.h"
using namespace std;
cookie::cookie(string p_log_path, string p_date){
			ifstream fp(p_log_path);
			
			//Check if the file exists
			if(!fp) {
				cout<<"Can not find "<<p_log_path;
				throw std::runtime_error("Can not find "+p_log_path);
			}

			//Check if the date is legal
			if(!judgment_date(p_date)){
				throw std::runtime_error("Date is illegal");
			}
			
			//Parse log file and write to hashmap
			string line;
			getline(fp, line);
			bool have_found = 0;
			while(getline(fp, line)){
				istringstream templine(line);
				string log, cookie, date;
				
				//Split the cookie from the log
				getline( templine, log,',');
				cookie = log.c_str();
				
				//Split the date from the log
				getline( templine, log,'T');
				date = log.c_str();
				
				if(date == p_date){
					have_found = 1;
					if(m_map.find(cookie) == m_map.end()) m_map[cookie] = 1;
					else m_map[cookie]++;
					m_most_cookie_cnt = m_map[cookie] > m_most_cookie_cnt ? m_map[cookie] : m_most_cookie_cnt;
				}
				else if(have_found == 1 && date!= p_date) break;
			}
}

bool cookie::judgment_date(string p_date){
			istringstream templine(p_date);
			getline(templine, year, '-'); 
			getline(templine, month, '-');
			getline(templine, date, '-');
			if(year.size()!=4 || month.size()!=2 || date.size()!=2 ) {
				throw std::runtime_error("Date format is illegal [yyyy-mm-dd]");
			}
			return IsLegal(stoi(year), stoi(month), stoi(date));
}

vector<string> cookie::most_active_cookie(){
			if(m_most_cookie_cnt == 0) cout<<"No active cookies at specified date.\n";
			vector<string> cookies;
			for(auto cookie: m_map){
				if(cookie.second == m_most_cookie_cnt) cookies.push_back(cookie.first);//cout << cookie.first << "\n";
			}
			return cookies;
}
/*
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
	cookie_log1.most_active_cookie();
}*/
