#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class cookie{
	public:
		//Initial object
		cookie();
		cookie(string p_log_path, string p_date);
		vector<string> most_active_cookie();
	private:
		unordered_map<string, int> m_map;
		int m_most_cookie_cnt = 0;
		string year;
		string month;
		string date;
		bool judgment_date(string p_date);
};
