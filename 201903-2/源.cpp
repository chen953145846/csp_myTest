#include <iostream>
//#include<ctime>
#include<vector>
#include<string>

typedef long int_64;

using namespace std;

bool cheak(int_64* num, char* mark);

int main() {
	int_64* num = new long[4];
	char* mark = new char[3];
	int_64 number;
	vector<bool> result;
	string str;
	//clock_t startTime, endTime;
	cin >> number;
	//startTime = clock();
	for (int_64 i = 0; i != number; i++) {
		//rewind(stdin);
		result.push_back(false);
		cin >> str;
		num[0] = str[0] - '0';
		for (int h = 1; h != 7; h++) {
			if (h % 2 == 0) {
				num[h / 2] = str[h] - '0';
			}
			else {
				mark[(h - 1) / 2] = str[h];
			}
		}
		int temp = 3;
		int_64 resultNum = 0;
		for (int h = 0; h != temp; h++) {
			if (mark[h] == 'x' || mark[h] == '/') {
				if (mark[h] == 'x') {
					num[h] *= num[h + 1];
				}
				else {
					num[h] /= num[h + 1];
				}
				for (int j = h; j != temp - 1; j++) {
					mark[j] = mark[j + 1];
					num[j + 1] = num[j + 2];
				}
				mark[temp-1] = -1;
				num[temp] = 0;
				temp--;
				h--;
			}
			//cout << num[0] << mark[0]
			//	<< num[1] << mark[1]
			//	<< num[2] << mark[2]
			//	<< num[3] << endl;
		}
		resultNum = num[0];
		for (int i = 0; i < temp; i++) {
			if (mark[i] == '+') {
				resultNum += num[i + 1];
			}
			else {
				resultNum -= num[i + 1];
			}
		}
		if (resultNum == 24) {
			result[i] = true;
		}
		else {
			result[i] = false;
		}
	}
	for (int_64 i = 0; i != number; i++) {
		if (result[i] == true) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	//endTime = clock();//¼ÆÊ±½áÊø
	//cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}