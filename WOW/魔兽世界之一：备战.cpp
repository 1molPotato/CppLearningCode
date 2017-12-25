/*
编程题＃4：魔兽世界之一：备战
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入

1
20
3 4 5 6 7
样例输出

Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors

还是不能熟练地处理类之间的关系，自己写到一半就进行不下去了，最后贴上郭老师的源码，骗自己认真读懂代码也算自己会吧...
*/

#include <iostream>  
#include <cstdio>  
#include <string>  
#include <iomanip>
using namespace std;
const int  WARRIOR_NUM = 5;//共有5类武士
/*
string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
*/

/*
类成员的声明
*/

class Headquarter;//需要先对Headquarter类进行声明，Warroir类中才可以使用
class Warrior
{
private:
	Headquarter * pHeadquarter;//此指针关联该武士所属的司令部
	int kindNo; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf  
	int no;//表示该武士是司令部所制造所有武士的第几个
public:
	enum WARRIOR{};//能否用枚举代替
	static string names[WARRIOR_NUM];//静态成员变量，储存各类武士的名称
	static int initialLifeValue[WARRIOR_NUM];//静态成员变量，储存各类武士的初始生命值
	Warrior(Headquarter * p, int no_, int kindNo_);//构造函数
	void PrintResult(int nTime);
};

class Headquarter
{
private:
	int totalLifeValue;
	bool stopped;//判断是否停止制造武士
	int totalWarriorNum;//当前司令部已经制造的武士总数
	int color;//红方司令部或者蓝方司令部
	int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个  
	int warriorNum[WARRIOR_NUM]; //当前司令部已经制造的每种武士的数目  
	Warrior * pWarriors[1000];//指向Warrior对象的指针数组，使司令部和制造的武士之间产生了关联
public:
	friend class Warrior;//声明Warrior类为Headquarter的友元，使得Warrior的成员函数可以访问Headquarter的私有成员
	static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列  
	void Init(int color_, int lv);
	~Headquarter();//析构函数
	int Produce(int nTime);
	string GetColor();

};

/*
Warrior类成员的定义
*/
Warrior::Warrior(Headquarter *p, int no_, int kindNo_) {
	//Constructor
	no = no_;
	kindNo = kindNo_;
	pHeadquarter = p;
}

void Warrior::PrintResult(int nTime) {
	//print birth info of this warrior
	cout << setw(3) << setfill('0') << nTime << ' ' << pHeadquarter->GetColor()
		<< ' ' << names[kindNo] << ' ' << nTime + 1 << " born with strength "
		<< initialLifeValue[kindNo] << "," << pHeadquarter->warriorNum[kindNo]
		<< ' ' << names[kindNo] << " in " << pHeadquarter->GetColor()
		<< " headquarter" << endl;
}

/*
Headquarter类成员的定义
*/
void Headquarter::Init(int color_, int lv) {
	//初始化司令部的属性：红方or蓝方、初始生命元、武士总数等
	color = color_;
	totalLifeValue = lv;
	totalWarriorNum = 0;
	stopped = false;
	curMakingSeqIdx = 0;
	for(int i = 0; i < WARRIOR_NUM; i++)
		warriorNum[i] = 0;
}

Headquarter::~Headquarter() {
	for(int i = 0; i < totalWarriorNum; i++)
		delete pWarriors[i];//释放内存
}

int Headquarter::Produce(int nTime) {
	if(stopped)
		return 0;//司令部已无法制造任何武士，直接返回0
	int searchingTimes = 0;//搜索司令部能够制造的武士的次数
	while(Warrior::initialLifeValue[makingSeq[color][curMakingSeqIdx]] > totalLifeValue
		&& searchingTimes < WARRIOR_NUM) {
		//搜索小于武士种类数量且司令部生命元不足以制造该类武士时，便继续循环搜索
		curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;//使curMakingSeqIdx在0到WARRIOR_NUM反复循环，斯国一！
		searchingTimes++;//每循环一次表示搜索次数增加一次，遍历完WARRIOR_NUM种武士即终止循环
	}
	int kindNo = makingSeq[color][curMakingSeqIdx];//确定将要制造的武士种类
	if(Warrior::initialLifeValue[kindNo] > totalLifeValue) {
		stopped = true;//若司令部生命元仍不够，则说明已无法制造任何武士
		cout << setw(3) << setfill('0') << nTime << ' ' << GetColor()
			<< " headquarter stops making warriors" << endl;//按格式打印终止生产信息
		return 0;
	}
	//制造武士
	totalLifeValue -= Warrior::initialLifeValue[kindNo];//司令部生命元相应减少
	pWarriors[totalWarriorNum] = new Warrior(this, totalWarriorNum + 1, kindNo);//制造一个新的武士
	warriorNum[kindNo]++;//司令部中该类武士的数量增加1
	pWarriors[totalWarriorNum]->PrintResult(nTime);
	totalWarriorNum++;
	return 1;
}

string Headquarter::GetColor() {
	//返回对应颜色的字符串
	return 0 == color?"red":"blue";
}

/*
类静态成员变量的初始化
*/
string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
int Warrior::initialLifeValue[WARRIOR_NUM];//无该句则无法编译，为何？
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } }; //两个司令部武士的制作顺序序列

int main()
{
	int case_num;//测试组数
	cin >> case_num;
	Headquarter redHead, blueHead;
	for(int k = 0; k < case_num; k++) {
		//第k组数据
		int M;//司令部生命元
		cin >> M;
		for(int j = 0; j < WARRIOR_NUM; j++) {
			cin >> Warrior::initialLifeValue[j];//初始化武士的生命值
		}
		//初始化两司令部
		redHead.Init(0, M);
		blueHead.Init(1, M);
		int nTime = 0;
		while(true) {
			int tmp1 = redHead.Produce(nTime);
			int tmp2 = blueHead.Produce(nTime);
			if(0 == tmp1 && 0 == tmp2)
				break;//循环终止条件：两司令部的Produce方法均返回0时
			nTime++;
		}

	}

	return 0;
}
