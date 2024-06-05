#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include<random>
#include<Windows.h>

bool PROFESSIONAL;//是否有专业人员
int FRIENDLYX, FRIENDLYY;//友军小队坐标

using namespace std;
double random1();
struct target
{
	short type;
	int position_x,position_y;
	bool is_friend;
};
struct artillery_hit
{
	double deathrate1[3];
	double deathrate2[3];
	double deathrate3[3];
	double max_range;
	int position_x, position_y;
};
vector<target> list;
void add_target(short type, int position_x, int position_y, bool is_friend)
{
	target temp;
	temp.type = type;
	temp.position_x = position_x;
	temp.position_y = position_y;
	temp.is_friend = is_friend;
	list.push_back(temp);
}
double range(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void friendly_fire(){}
void enemy_hit(int x,int y){}
bool hit(artillery_hit hit, target tgt) {
	if (range(hit.position_x, hit.position_y, tgt.position_x, tgt.position_y) > hit.max_range)
	{
		return 0;
	}
	double d = range(hit.position_x, hit.position_y, tgt.position_x, tgt.position_y);
	double maxd = hit.max_range;
	bool hitten = 0;
	double r[3];
	double* rate=r;
	if (tgt.type == 1) {
		double* rate = hit.deathrate1;
	}
	else if (tgt.type == 2) {
		double* rate = hit.deathrate2;
	}
	else {
		double* rate = hit.deathrate3;
	}
	if (d / maxd < 0.2) {
		if (random1() < rate[0])

		{
			hitten = 1;
		}
	}
	else if (d / maxd < 0.5) {
		if (random1() < rate[1])
		{
			hitten = 1;
		}
	}
	else
	{
		if (random1() < rate[2])
		{
			hitten = 1;
		}
	}
	if (hitten) {
		if (tgt.is_friend) {
			friendly_fire();
		}
		else {
			enemy_hit(tgt.position_x,tgt.position_y);
		}
		return 1;
	}
	return 0;
}
void friendly_fire() {
	if (PROFESSIONAL) {
		cout << "Friendly fire!" << endl;
	}
	else {
		float d = random1();
		if (d < 0.3) {
			cout << "friendly fire! cease fire!" << endl;
		}
		else if (d < 0.6) {
			cout << "what are you doing? stop shooting at us!*********" << endl;
		}
		else {
			cout << "Friendly fire!Noooooooo!!!!" << endl;
		}
	}
}
void enemy_hit(int x, int y) {
	if (!PROFESSIONAL) {
		float d = random1();
		if (d < 0.3) {
			cout << "Yes!Good HIt!" << endl;
		}
		else if (d < 0.7) {
			cout << "That take him down!" << endl;
		}
		else {
			cout << "well done!" << endl;
		}
	}
	else{
		cout << "enemy hit at  " ;
		cout << x << ", ";
		cout << y << endl;
		cout << "enemy knocked out" << endl;
	}
}
class weapon {
public:
	string name;
	double deathrate1[3];
	double deathrate2[3];
	double deathrate3[3];
	double max_range;
	weapon(string name, double deathrate1[3], double deathrate2[3], double deathrate3[3], double max_range) {
		this->name = name;
		for (int i = 0; i < 3; i++) {
			this->deathrate1[i] = deathrate1[i];
			this->deathrate2[i] = deathrate2[i];
			this->deathrate3[i] = deathrate3[i];
		}
		this->max_range = max_range;
	}
};
vector <weapon> weapon_list;
void add_weapon(string name, double deathrate1[3], double deathrate2[3], double deathrate3[3], double max_range) {
	weapon temp(name, deathrate1, deathrate2, deathrate3, max_range);
	weapon_list.push_back(temp);
}
double random1(){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dis(0, 1);
	return dis(gen);
}
int main() {
	cout << "Welcome to the artillery simulator!" << endl;
	//
	//
	//
	cout << "loading complete!" << endl;
	string mode;
	string hard;
	int ha;
	cout << "Please enter the mode of the game" << endl;
	while (true) {
		cin >> mode;
		if (mode == "random") {
			goto random;
		}
		if (mode == "select level") {
			goto level;
		}
	}
random:
	cout << "Please enter the hardness of the game" << endl;
	while (true) {
		cin >> hard;
		if (hard == "easy") {
			ha = 1;
		}
		if (hard == "normal") {
			ha = 2;
		}
		if (hard == "hard") {
			ha = 3;
		}
	}//继续调用project1生成关卡
	goto final;
level:
	cout << "Please enter the name of the level file" << endl;
	//读入关卡文件
final:
	//读入武器包
	//检测玩家输入内容并调用函数判断命中以及结束条件
	while (true) {
		Sleep(100);

	}
}
