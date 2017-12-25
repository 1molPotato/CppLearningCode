/*
编程题＃2： 魔兽世界之二：装备
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入

1
20
3 4 5 6 7
样例输出

Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors

这道题思路很简单，就是按照题目要求从Warrior类派生出几个子类实现各自的功能，直接在上一题的基础上扩充就好
但是自己的实现过程依旧很丑陋，为了能调用派生类的print函数，声明了5个派生类对象指针的数组，显得十分臃肿
而且在produce函数中，也是通过枚举的方式new出5种派生类的对象
总之重复代码很多，郭老师本来优雅的代码都被我改成什么鬼样了...
先po自己的吧，好歹在POJ上通过了(好吧其实是PE)
稍后去看看大神的代码，我先猜测一波用多态的概念应该可以优化代码
*/

#include <iostream>  
#include <cstdio>  
#include <string>  
#include <iomanip>
using namespace std;
const int  WARRIOR_NUM = 5;//共有5类武士
const int  WEAPON_NUM = 3;//共有3类武器
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
	int kindNo; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf  
	int no;//武士的编号
protected:
	Headquarter * pHeadquarter;//声明为保护成员，才能被派生类访问
public:
	enum WARRIOR {};//能否用枚举代替
	static string names[WARRIOR_NUM];//静态成员变量，储存各类武士的名称
	static string weapons[WEAPON_NUM];//静态成员变量，储存各类武器的名称
	static int initialLifeValue[WARRIOR_NUM];//静态成员变量，储存各类武士的初始生命值
	Warrior(Headquarter * p, int no_, int kindNo_);//构造函数
	void PrintResult(int nTime);
};
class Dragon;//事先声明类才可以在Headquarter类中使用
class Ninja;
class Iceman;
class Lion;
class Wolf;
class Headquarter
{
private:
	int totalLifeValue;
	bool stopped;//判断是否停止制造武士
	int totalWarriorNum;//当前司令部已经制造的武士总数
	int color;//红方司令部或者蓝方司令部
	int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个  
	int warriorNum[WARRIOR_NUM]; //当前司令部已经制造的每种武士的数目  
	//Warrior * pWarriors[1000];//指向Warrior对象的指针数组，使司令部和制造的武士之间产生了关联
	Dragon * pDragons[1000];
	Ninja * pNinjas[1000];
	Iceman * pIcemen[1000];
	Lion * pLions[1000];
	Wolf * pWolves[1000];
public:
	friend class Warrior;//声明Warrior类为Headquarter的友元，使得Warrior的成员函数可以访问Headquarter的私有成员
	friend class Dragon;//派生类仍需要声明为友元??
	friend class Lion;
	static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列  
	void Init(int color_, int lv);
	~Headquarter();//析构函数
	int Produce(int nTime);
	string GetColor();

};

/*
武士Warrior的派生类
*/
class Dragon :public Warrior {
private:
	int weaponNo;//武器编号
	float morale;//士气
public:
	Dragon(Headquarter * p, int no_, int kindNo_) :Warrior(p, no_, kindNo_) {
		weaponNo = no_ % 3;
		morale = (float)pHeadquarter->totalLifeValue / initialLifeValue[kindNo_];
	}
	void PrintResult(int nTime) {
		Warrior::PrintResult(nTime);//先调用基类的输出函数
		cout << "It has a " << weapons[weaponNo] << ", and it's morale is " 
			<< fixed << setprecision(2) << morale << endl;
	}
};
class Ninja :public Warrior {
private:
	int weapon1No;
	int weapon2No;//ninja有两件武器
public:
	Ninja(Headquarter * p, int no_, int kindNo_) :Warrior(p, no_, kindNo_) {
		weapon1No = no_ % 3;
		weapon2No = (no_ + 1) % 3;
	}
	void PrintResult(int nTime) {
		Warrior::PrintResult(nTime);//先调用基类的输出函数
		cout << "It has a " << weapons[weapon1No] << " and a " << weapons[weapon2No] << endl;
	}
};
class Iceman :public Warrior {
private:
	int weaponNo;//武器编号
public:
	Iceman(Headquarter * p, int no_, int kindNo_) :Warrior(p, no_, kindNo_) {
		weaponNo = no_ % 3;
	}
	void PrintResult(int nTime) {
		Warrior::PrintResult(nTime);//先调用基类的输出函数
		cout << "It has a " << weapons[weaponNo] << endl;
	}
};
class Lion :public Warrior {
private:
	int loyalty;//忠诚度
public:
	Lion(Headquarter * p, int no_, int kindNo_) :Warrior(p, no_, kindNo_) {
		loyalty = pHeadquarter->totalLifeValue;
	}
	void PrintResult(int nTime) {
		Warrior::PrintResult(nTime);//先调用基类的输出函数
		cout << "It's loyalty is " << loyalty << endl;
	}
};
class Wolf :public Warrior {
public:
	Wolf(Headquarter * p, int no_, int kindNo_) :Warrior(p, no_, kindNo_) {
		//Wolf类与基类完全相同
	}
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
	for(int i = 0; i < warriorNum[0]; i++)
		delete pDragons[i];//释放内存
	for(int i = 0; i < warriorNum[1]; i++)
		delete pNinjas[i];//释放内存
	for(int i = 0; i < warriorNum[2]; i++)
		delete pIcemen[i];//释放内存
	for(int i = 0; i < warriorNum[3]; i++)
		delete pLions[i];//释放内存
	for(int i = 0; i < warriorNum[4]; i++)
		delete pWolves[i];//释放内存
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
	} ;
	int kindNo = makingSeq[color][curMakingSeqIdx];//确定将要制造的武士种类
	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
	if(Warrior::initialLifeValue[kindNo] > totalLifeValue) {
		stopped = true;//若司令部生命元仍不够，则说明已无法制造任何武士
		cout << setw(3) << setfill('0') << nTime << ' ' << GetColor()
			<< " headquarter stops making warriors" << endl;//按格式打印终止生产信息
		return 0;
	}
	//制造武士
	totalLifeValue -= Warrior::initialLifeValue[kindNo];//司令部生命元相应减少
	if(0 == kindNo) {
		pDragons[warriorNum[kindNo]] = new Dragon(this, totalWarriorNum + 1, kindNo);//制造一个Dragon
		pDragons[warriorNum[kindNo]++]->PrintResult(nTime);
	}		
	else if(1 == kindNo){
		pNinjas[warriorNum[kindNo]] = new Ninja(this, totalWarriorNum + 1, kindNo);//制造一个Ninja
		pNinjas[warriorNum[kindNo]++]->PrintResult(nTime);
	}
	else if(2 == kindNo) {
		pIcemen[warriorNum[kindNo]] = new Iceman(this, totalWarriorNum + 1, kindNo);
		pIcemen[warriorNum[kindNo]++]->PrintResult(nTime);
	}
	else if(3 == kindNo) {
		pLions[warriorNum[kindNo]] = new Lion(this, totalWarriorNum + 1, kindNo);
		pLions[warriorNum[kindNo]++]->PrintResult(nTime);
	}
	else {
		pWolves[warriorNum[kindNo]] = new Wolf(this, totalWarriorNum + 1, kindNo);		
		pWolves[warriorNum[kindNo]++]->PrintResult(nTime);
	}
	//warriorNum[kindNo]++;//司令部中该类武士的数量增加1
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
string Warrior::weapons[WEAPON_NUM] = { "sword","bomb","arrow" };
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
		cout << "Case:" << k + 1 << endl;
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
