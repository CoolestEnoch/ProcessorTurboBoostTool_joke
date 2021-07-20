#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <cstring>
using namespace std;

//=====注意：本程序需要管理员权限运行=====

//这里写你的电脑型号
string device_info = "Dell G5 15 5500";
//这里写你当前的CPU信息，只需要改动引号内的文本即可
//Example：
//string raw_info = R"+*("AMD Ryzen 5 3600X")+*";
string raw_info = R"+*("Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz")+*";


void startPic(int tt_len, int waitTime)
{
	//int tt_len = 87;
	float pct = 0.0;
	cout << '[';
	for (int i = 1; i < tt_len + 1; i++)
	{
		pct = 100 * (float(i) / tt_len);
		if (i != 1)
		{
			for (int j = i; j <= tt_len + 1; j++)
			{
				cout << '\b';
			}
		}
		cout << '=';
		for (int j = i; j < tt_len + 1; j++)
		{
			cout << ' ';
		}
		cout << "\b]";
		printf("%3.1f%%", pct);
		if (pct < 10)
		{
			cout << "\b\b\b\b";
		}
		else if (pct >= 10 and pct < 100)
		{
			cout << "\b\b\b\b\b";
		}
		Sleep(waitTime);
	}
	cout << "\n";
}

void mainPic() {
	cout << "欢迎使用处理器超频工具 for " << device_info << endl;
	cout << "\t\t\t\t\t\tPowered by Enoch Lin" << endl;
	cout << "==============================================" << endl;
	cout << "请输入数字以执行操作：" << endl;
	cout << "1.启用超频" << endl;
	cout << "2.禁用超频" << endl;
	cout << "" << endl;
	cout << "3.关闭程序" << endl;
	cout << "==============================================" << endl;
}

int main() {
	cout << "欢迎使用处理器超频工具 for " << device_info << endl;
	cout << "\t\t\t\t\t\tPowered by Enoch Lin" << endl;
	startPic(86, 10);
	system("cls");

	int i = 0;
	int status = 0;
	string path = "";
	string exec = "";
	//string raw_info = R"+*("Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz")+*";
	string new_info = R"+*("MediaTek MT6735 @ 10.9GHz")+*";
	while (1) {
		mainPic();

		cin >> i;
		while (i < 1 or i > 3){
			system("cls");
			cout << "非法输入！" << endl;
			mainPic();
			cin >> i;
		}

		switch (i) {
		case (1):
			path = "\"HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\"";
			exec = "reg add " + path + " /v ProcessorNameString /t REG_SZ /d " + new_info + " /f";
			status = system(exec.data());
			break;
		case (2):
			path = "\"HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\"";
			exec = "reg add " + path + " /v ProcessorNameString /t REG_SZ /d " + raw_info + " /f";
			status = system(exec.data());
			break;
		case (3):
			return 0; break;
		}
		if (status != 0) {
			cout << "需要管理员权限" << endl;
		}
		system("pause");
		system("cls");
	}


	return 0;
}
