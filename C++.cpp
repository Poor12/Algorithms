/*
	int a, b, c;
	a = (b = 4) + (c = 6);
	cout << a; 10
	*/

	//栈就是那些由编译器在需要的时候分配不需要的时候自动清除的存储区，通常为局部变量、函数参数
	//堆就是new分配出来的内存块

	//构造函数可以设置默认的参数，构造函数在定义类对象时自动执行，构造函数可以是内联函数，在类内定义的函数，编译器一般视作内联
	//构造可以被重载，析构不可以被重载

	/*
	int w = 1, x = 2, y = 3, z = 4;
	cout << (w > x ? w : y < z ? y : z);//右操作符
	*/

	/*
	class cbase
	{
	public:
		cbase() {
			cout << "constructing cbase class" << endl;//1
		}
		~cbase() {
			cout << "destructing cbase class" << endl;//4
		}
	};
	class csun :public cbase
	{
	public:
		csun() {
			cout << "constructing csun class" << endl;//2
		}
		~csun() {
			cout << "destructing csun class" << endl;//3
		}
	};
	csun obj;
	*/

	//c++不能重载的运算符就是?: , . , :: , sizeof , .*
	
	/*
	int *p = (int *)malloc(sizeof(int));
	读入数据时的语句：scanf("%d",p) //scanf本身要求读入的就是指针类型
	*/

	//关于赋值运算符=重载的叙述
	//赋值运算符只能作为类的成员函数重载，默认的赋值运算符实现了浅层赋值功能，重载的赋值运算函数有一个本类对象作为形参，复制构造和赋值构造可以同时存在
	
	//swap
	/*
	//success
	int a = 5, b = 6;
	int *c = &a, *d = &b;
	swap(c, d);
	cout << *c << *d;
	void swap(int *a, int *b)
	{
		int t;
		t = *a;
		*a = *b;
		*b = t;
	}
	//failure
	int a = 5, b = 6;
	int *c = &a, *d = &b;
	swap(c, d);
	cout << *c << *d;
	void swap(int *a, int *b)
	{
		int *t;
		t = a;
		a = b;
		b = t;
	}
	//success
	int a = 5, b = 6;
	swap(a, b);
	cout << a << b;
	void swap(int &a, int &b)
	{
		int t;
		t = a;
		a = b;
		b = t;
	}
	*/

	/*
	int *pint = 0;//p指向0x00
	pint += 6;//int占4个字节，加6偏移24个字节，0x18
	cout << pint << endl;
	*/

	//静态外部变量只在本文件内可用
	
	//变量的地址是常量，变量的指针是变量，所以一个变量的地址不等于该变量的指针
	//指针不可以用整数赋值

	/*
	int add(int *x, int *y, int *z)
	{
		*x += *x;
		*y += *x;
		*z += *y;
		return *z;
	}
	x,y,z指向同一区域时为8
	x,y指向同一区域时为5
	y,z指向同一区域时为6
	x,y,z指向不同区域时为4
	*/
	
	/*
		void getmemory(char *p)
		{
			p=(char *)malloc(100);
		}
		void test(void)
		{
			char *str=null;
			getmemory(str);//str仍为null
			strcpy(str,"hello world");
			printf(str);
		}
	*/
	
	/*
		int fun(int n)
		{
			if(n==5)
				return 2;
			else
				return 2*fun(n+1);
		}
		fun(2) 16
	*/

	//int *fun(int a){函数体语句；}，fun是指针函数，返回值为一个整型指针

	//计算机工作时，内存储器用来存储程序和数据
	
	/*
	class cparent {
		public:virtual void intro()
		{
			printf("i am a parent,");
			hobby();
		}
		virtual void hobby()
		{
			printf("i like football");
		}
	};
	class cchild :public cparent
	{
		public:virtual void intro()
		{
			printf("i am a child,");
			hobby();
		}
		virtual void hobby()
		{
			printf("i like basketball");
		}
	};
	cchild *pchild = new cchild();
	cparent *parent = (cparent *)pchild;//父类指向子类，调用子类的方法
	parent->intro();

	虚函数：基类中声明为virtual并在一个或多个派生类中被重新定义的成员函数
	纯虚函数：基类中没有实现体的虚函数。有纯虚函数的基类称为虚基类
	独酌逸醉--c++虚函数及虚函数表解析
	*/

	/*
	class a
	{
	public:
		virtual void test()
		{
			printf("a test\n");
		}
	};
	class b:public a
	{
	public:
		void func()
		{
			test();
		}
		virtual void test()
		{
			printf("b test\n");
		}
	};
	class c :public b
	{
	public:
		virtual void test()
		{
			printf("c test\n");
		}
	};
	c cc;
	((b*)(&cc))->func();//多态
	((b)cc).func();//不是多态，强制转换
	*/

	/*
	int m = 1, n = 2;
	--m&&n++;//&&左式为假停止
	++m || n++;//||左式为真停止
	cout << m << n;
	*/

	/*
	int i = -1;
	unsigned j = 1;//化成unsigned比较
	if (j > i)
		printf("(j>i)成立");
	else
		printf("(j>i)不成立");
	if (i < j)
	{
		printf("(i<j)成立");
	}
	else
		printf("(i<j)不成立");
	*/

	//派生类
	//从基类接受成员，调整从基类接受的成员，在声明派生类时增加成员，在声明派生类时要定义自己的构造函数

	//构成c语言的基本单位是函数

	//c++中容器是一种标准类模板

	//默认参数可以出现在函数声明中，也可以出现在函数定义中，但是同一个作用域对同一个参数只能指定一个默认参数，给形参添加默认参数必须保证该参数的右侧都必须有默认值

	//c语言16位排序：char(1)<int(2)<long int(4)<=float(4)<double(8)
	//

	/*
	const char *s = "abcdefg";
	s += 2;
	fprintf(stderr, "%d\n", s);//c的地址
	fprintf(stderr, "%d\n", *s);//c的值，ascii码
	*/

	//纯虚函数是一种特殊的虚函数，抽象类是指具有纯虚函数的类，抽象类只能作为基类，其纯虚函数的实现由派生类给出
	//一个基类如果有纯虚函数，派生类没有重写该函数，仍然为纯虚函数，派生类仍然为抽象类
	
	/*
	int y, a;
	y = (a = 3, 6 * 5);//逗号表示式，所有表示式都会运行，结果为最后一个表达式的值
	cout << y << a;
	*/
	
	/*
	typedef struct st
	{
		long a;
		int b;
		char c[2];
	}b;
	b和struct st为结构体类型，c++可以st a，c语言不可以
	*/
	
	/*
	char format[]="%d%c";
	printf(format,sizeof(format)," abcdef"[2]+1);//sizeof,包括\0，strlen不包括\0
	*/

	/*
	char str[] = "ab\012\\n";// \012就是\n(八进制10),\\表示一个斜杠
	printf("%d", strlen(str));
	printf("%s", str);
	*/

	/*
	char str[4][12]={"aaa","bbbb","ccccc","dddddd"};
	int i;
	//char *strp[4];//char的指针数组，指针指向的是char *
	//char **strp=new char*[4];
	char **strp = (char **)malloc(sizeof(char *)*4);
	for (i = 0;i < 4;++i)
	{
		strp[i] = str[i];
	}
	cout << *(strp+1)<<str[1]<<strp[1];//strp是第一个字符数组的地址
	cout << "\n" << **strp;
	*/

	/*
	地址引用：a可以，是数组首地址，a++不可以，a是不可修改的值，&a不可以
	int a[5] = { 1,2,3,4,5 };
	int *p = a;
	*/

	//变量类型，auto自动变量类型推导，register建议编译器将该变量放入cpu，static静态变量，extern常用于多文件需要使用同一变量
	//register int a[1000]存储速率>>int a[1000]

	//c++可以嵌套调用，不可以嵌套声明

	/*
		char str[]="hello";
		char *str="hello";
		#define str "hello"
		cout<<str;
		//都可行
	*/

	/*
		c++语言不允许在重载运算符时改变运算符的操作个数、操作优先级、操作结合性
	*/
	
	/*
	struct s
	{
		int n;
		char c[10];
	}*p;
	struct s a[3] = { {3,"abc"},{5,"def"},{7,"ghi"} };
	p = a;
	printf("%d,", (*p).n);
	printf("%d\n", (++p)->n);
	printf("%d\n", (a + 1)->n);
	printf("%d\n", p++->n);//++优先级大于->
	*/

	//static变量又叫静态成员变量，它不需要创建对象就已经在内存中存在
	//创建实例对象的时候，内存中会为每一个实例对象的每一个非静态成员变量开辟一段内存空间，用来存储这个对象所有的非静态成员变量值
	//static变量是所有对象共有，其中一个对象将它值改变，其他对象得到的就是改变后的值
	//实例对象为对象私有，某一个对象将其值改变，不影响其他对象

	//sizeof(数组指针) 数组长度*指针范围，sizeof（指针） 指针范围
	//void *p2 = malloc(10);
	//cout << sizeof(p2); 4 32位机器

	//c++中class和struct除了默认权限，其他无差别

	//运算符 算术>关系>逻辑

	/*
	int i = 11;
	//int const *p = &i;指针内容常量
	//const int *p = &i;
	int *const p = &i;//指针常量
	*p = 12;
	*/

	/*
	char c;
	int v0 = 0, v1 = 0, v2 = 0;
	do {
		switch (c = getchar())
		{
		case 'a':case 'A':case 'e':case 'E':case 'i':case 'I':case 'o':case 'O':case 'u':case 'U':v1 += 1;
		default:v0 += 1;v2 += 1;
		}
	} while (c != '\n');
	printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2); 12 4 12 没有break
	*/
	
	//友元类型不是访问控制类型

	//int (*p)[6] 指向具有6个元素的一维数组的指针

	//c++常量可分为6种，整型常量、实型常量、字符串常量、字符常量、符号常量、逻辑型常量

	//a *pa=new a[10];delete []pa; 构造函数和析构函数共执行了10次

	//位运算的对象只能是整型或字符型数据，右移运算，整数高位补0，负数高位补1

	/*
	enum week
	{
		sun,mon=4,tue,wed,thu,fri,sat
	}w;
	枚举默认从0开始，往后逐个加1，赋值后从赋值的数开始加1
	*/

	//类定义中包含数据成员和函数成员的声明

	//类成员的缺省访问是private

	/*
	int a[] = { 1,2,3 };
	cout << a[1 > 2];
	访问a[0]
	*/

	/*
	int n = 10, m = 4;
	double d1 = (double)(m / n); 0
	double d2 = (double)m / n; 0.4
	cout << d1 << " " << d2;
	*/
	
	/*
	string s = "flower" + 4;右移四位
	//string ss = "flower" - "flow";无意义(+)
	cout << s;
	*/

	/*
	int a[4][4] = { {1,2,3,4},{5,6,7,8},{11,12,13,14},{15,16,17,18} };
	int i = 0, j = 0, s = 0;
	while (i++ < 4)
	{
		if (i == 2 || i == 4)
			continue;
		j = 0;
		do {
			s += a[i][j];
			j++;
		} while (j < 4);
	}
	printf("%d\n", s);
	*/

	//c语言允许函数值类型缺省定义，该函数的隐含类型为int，c++不允许

	/*
	char c[2][5] = { "6938","8254" }, *p[2];
	int i, j, s = 0;
	for (i = 0;i < 2;++i)
		p[i] = c[i];
	for (i = 0;i < 2;++i)
		for (j = 0;p[i][j] > 0;j += 2)
			s = 10 * s + p[i][j] - '0';
	printf("%d\n", s);
	*/

	//在函数内定义变量称为局部变量，在函数外定义变量称为全局变量
	//动态区 生存周期：函数调用开始到结束 赋初值：程序运行后每次函数调用时重新赋初值；调用结束后释放内存 函数内称为局部变量 形参表内称为形参变量 函数表内可见，函数外不可见
	//静态区 生存周期：exe开始到结束 赋初值：一次性赋初值，运行后不再赋初值，运行时保留最后一次调用 函数外缺省变量（*exe可见） 函数外static变量（仅在本c可见，extern无效） 函数内static内部变量（函数内可见，函数外不可见）
	
	/*
	class packet {
		int size;
		void data[0];
	};
	柔性数组，减少内存碎片化，维护数据包空间的连续性
	*/

	/*
	int fun(int a)
	{
		int b = 0;
		static int c = 3;
		a = (b++,c++);
		return a;
	}
	int a = 2, i, k;
	for (i = 0;i < 2;++i)
	{
		k = fun(a++);
	}
	printf("%d\n", k);
	*/
	/*
	int func(unsigned int v)
	{
		v ^= v >> 16;
		v ^= v >> 8;
		v ^= v >> 4;
		v &= 0xf;
		return (0x6996 >> v) & 1;
	}
	int funb(int n)
	{
		unsigned int t=1 << n;
		int val = 0;
		for (int i = 0;i < t;++i)
		{
			val += func(i);
		}
		return val;
	}	
	cout<<funb(10);  512
	*/

	/*
	struct link {
		char data;
		(struct) link *next;//c++可以省略，c不可以
	}node;
	*/

	/*
	struct a
	{
		int a;//4
		short b;//4+2=6，对齐为8
		int c;//8+4=12
		char d;//12+1=13，补齐为16
	};
	struct b
	{
		int a;//4
		short b;//4+2=6
		char c;//6+1=7，对齐为8
		int d;//8+4=12
	};
	cout << sizeof(a) << " " << sizeof(b);
	32位系统，编译选项为4字节对齐，对齐原则：每一成员需对齐为后一成员类型的倍数，补齐原则：最终大小补齐为成员类型最大的倍数
	*/

	//函数输入参数，始终用const限制所有指向只读输入参数的指针与引用，优先按const的引用取得其他用户定义类型的输入，如果函数需要修改其参数副本，可以考虑通过值传递替代引用传递

	/*
	float x = 213.82631;
	printf("%6d", (int)x);6表示宽度，x本身大于宽度无影响，否则填空格
	*/

	/*
	struct p
	{
		char name[9];
		int age;
	};
	p cla[10] = { "john",1,"mary",2 };
	cout << cla[1].name[0];
	*/

	/*
	int a[3][4] = { 1,2,3,4,5,5 };
	cout << *(a[2] + 1);
	cout << *(*(a + 1) + 1); //5
	cout << *(*(a + 1)) + 1; //6
	*/

	/*
	int a[5] = { 1,2,3,4,5 };
	int *ptr = (int *)(&a + 1);//&a表示整个数组的地址
	printf("%d,%d", *(a + 1), *(ptr-1));//2，5
	*/

	/*
	int a = 5;
	++(a++);	a++返回5，++只能作用于变量
	*/

	//浅拷贝：只复制指向对象的指针而不复制引用对象本身
	//深拷贝：复制引用对象本身
	//浅拷贝两个指针指向同一块内存，深拷贝指向不同内存

	//派生类对象对它的基类成员中，公有继承的公有成员是可以访问的

	/*
	int a[3][] = { 1,2,3 };
	int aa[][3] = { 1,2,3 };行数可以省略，列数不可以省略
	*/

	//fseek(fp,位移量，起始点）

	/*
	int m = 0256, n = 256;//八进制以0开头，%o输出八进制，%o输出带o八进制，256转八进制为400
	printf("%o,%#o,%o", m, m, n);
	*/

	//return后面表达式值得类型与函数类型不一致时，需要强制类型转换

	/*
	class a
	{
		a()
		{
			printf("a()");
		}
	public:
		static a &get()
		{
			static a aa;//静态局部变量初始化，调用构造
			return aa;
		}
	};
	a::get();//静态方法不需要对象就可以调用
	*/

	/*
		class myclass
	{
	public:
		myclass(int i = 0)
		{
			cout << i;
		}
		myclass(const myclass &x)
		{
			cout << "..";
		}
		myclass &operator=(const myclass &x)
		{
			cout << "////";
			return *this;
		}
		~myclass()
		{
			cout << "www";
		}
	};
	myclass obj1(1), obj2(2);
	myclass obj3 = obj1;//拷贝构造函数
	//myclass obj3;obj3=obj1 调用重载函数
	return 0;
	*/

	//运算符优先级 单目（！，++，-，类型，*，&，sizeof，右结合）>算术>移位>比较（等于和不等于较小）>按位与>异或>或>逻辑>三目（右结合）>赋值（右结合）>逗号

	//数组作为传递参数的形式传递到函数后自动退化为指针，在函数内进行sizeof只能拿到指针占用空间的大小，并不是数据元素的大小

	/*
	void fun(char *s)
	{
		char a[10];
		strcpy(a, "string");//目的，源
		s = a;
		printf("%s\n", s);
	}
	char p[] = "program";
	fun(p);//改变非指针变量需要指针，改变指针需要二级指针
	printf("%s\n", p);
	*/
	
	/*
	int a[][4] = { 0,0 };
	cout << a[0][1] << " " << a[1][1];//二维数组得不到0
	int a[10] = { 0 };
	cout << a[7];//一维数组可以得到0
	*/
	
	/*
	enum weekday{sun,mon}aaa;
	enum { sun, mon }aa;
	枚举定义
	*/

	/*
	int a = 3336;
	printf("|%-08d|", a);占8个空格，左对齐
	*/

	/*
	void incre()
	{
		static int x=1;
		x*=x+1;
		printf("%d",x);
	}
	int x=3;
	void main()
	{
		int i;
		for(i=1;i<x;++i)
			incre();
	}
	*/

	//未定义行为 C语言标准未作规定的行为
	//常见情况：1.变量即是左边结果，又是右边操作数 2.使用越界数组也是c的一个未定义行为 3.允许一个指针的读写 4.使用未初始化的变量
	//int i=0;i=(i++);

	/*
	int a = 5, b = 4, c = 3, d;
	d = (a > b > c);
	cout << d;0
	*/

	//1.234e0.4不合法，e右边需要是整数，可带符号

	/*
	int a = 5, b = -5;
	printf("%d %d", a % (-4), b % (-4));//模运算与被除数符号相同
	*/

	//const方法不能修改类中成员变量

	//const int *d;int *const e;int const *f const;

	//func((e1,e2),(e3,e4,e5))有两个实参
	
	/*
	int f()
	{
		static int i = 0;//静态变量不会消亡
		int s = 1;
		s += i;i++;
		return s;
	}
	int i, a = 0;
	for (i = 0;i < 5;++i)
		a += f();
	printf("%d\n", a);
	*/

	/*
	class a {//大小为1
	};
	class b {//8
		char ch;
		int x;
	};
	class c {//只有函数只需要知道函数的地址即可 为1
	public:
		int print(void) {}
	};
	class d {//虚函数需要为该类型生成虚函数表，多一个指针 4
	public:
		virtual void print(void) {}
	};
	cout << sizeof(c);
	*/

	//派生类向基类转换隐式，基类向派生类转换显式

	/*
	int k = 12;
	char ch = 'a';
	printf("%x,%o", ch, ch, k); %x 16进制 k会被省略
	printf("k=%%d\n", k);  %%输出百分号
	*/

	//a=a+b=b++ a+b不是可修改的左值，错误

	//scanf("%6.2f", &a); 浮点数不能有精度，浮点数和整数不能混用

	//malloc(申请地址单元数)
	//calloc(元素个数，单位元素长度）
	//realloc(原地址指针，新申请的地址长度）

	//实参可以是任何类型，形参不能是表达式

	//char hc = '\xff';
	//char ch='\';  no

	/*
	enum a {
		a
	}b;
	b=(enum a)5; 整型显式转换至枚举，枚举隐式转换到转型
	*/

	/*
	fopen("foo.txt","r")
	r 只读，文件必须存在
	r+ 读写，文件头开始写，保留原文件中没有被覆盖的内容，必须存在
	rb+ 读写，二进制
	rt+ 读写，文件
	w 打开只写文件，存在清空文件，不存在创建
	w+ 可读写，其他同w
	a+ 附加方式打开，可读写
	wb，wb+，ab+
	*/

	/*
	char a = 101; char的范围-128-127，超过范围变成-128
	int sum = 200;
	a += 27;sum += a;
	printf("%d\n", sum);
	*/

	/*
	char fun(char *);
	char s[] = "one", a[5] = { 0 }, (*f1)(char *) = fun, ch;
	//函数指针调用 f1(s)也可以(*f1)(s)，但不可以是*f1(s)
	*/

	//0表示stdin，1表示stdout，2表示stderr
	//printf(),等于fprintf(stdout,***);
	//stderr是没有缓冲的，立即输出，stdout默认是行缓冲，遇到\n才向外输出

	//char s[10];s="12344"; 常量指针不能被改变
	//char t[]="123",*s=t;
	//char s[];strcpy(s,"absdf");

	//scanf遇到空格、制表符、回车时会结束输入，且弃置空格

	//文件打开
	//FILE *fp=fopen("test","r");
	/*
		if((fp=fopen())==null)
			return;
	*/
	//文件关闭
	//int n=fclose(fp); 0表示正常
	//读取字符
	//ch=fgetc(fp);
	/*
		ch=fgetc(fp);
		while(ch!=EOF)
		{
			ch=fgetc(fp);
		}
	*/
	//写一个字符
	//fputc(ch,fp);
	//fputs(str,fp);  写字符串
	//fprintf(fp,format,arg_list) 写格式化数据
	//以二进制形式读取文件数据
	//int fread(void *buffer,unsigned sife,unsigned count,file *fp)
	//buffer将读入数据存放在存储区的首地址，sife指一个数据块的大小，count指读入多少个数据块
	//以二进制形式写数据到文件
	//int fwrite(void *buffer,unsigned sife,unsigned count,FILE *fp)
	/*
	#include <stdio.h>
	#define SIZE 4
	struct worker
	{ int number;
		char name[20];
		int age;
	};
	void main()
	{
		struct worker wk;
		int n;
		FILE *in,*out;
		if((in=fopen("file1.txt","rb"))==NULL)
		{
			printf("The file %s can not be opened.\n","file1.txt");
			return;
		}
		if((out=fopen("file2.txt","wb"))==NULL)
		{
			printf("The file %s can not be opened.\n","file2.txt");
			return;
		}	
		while(fread(&wk,sizeof(struct worker),1,in)==1)
			fwrite(&wk,sizeof(struct worker),1,out);
		fclose(in);
		fclose(out);
	}
	*/
	//二进制读一个整数
	//int getw(FILE *fp)
	//文件状态检查
	/*
		while(!feof(in))
		{
		}
	*/
	//定位
	//long ftell() 返回偏移量
	//void rewind(file *fp) 回到开头
	//int fseek(file *fp,long offset,int base);SEEK_SET
	
	//memset(void *dest,int c,size_t count);  dest前面count个字符赋为c
	//赋一个字节
	//int s[100];
	//memset(s, 0, sizeof(s));
	//memset(s，255，sizeof(s));
	//char *strrev(char *string); 字符顺序颠倒
	//char *_strupr(char *string); char *_strlwr(char *string);大小写转换
	//char *strchr(const char *string, int c);查找字符
	//char s[] = "adsdad";
	//cout << strchr(s, '\0') - s;
	//char *strstr(const char *string, const char *strSearch); 查找字串
	//char *strcpy(char *strDestination, const char *strSource); 复制包括null，不能处理重复的情况
	//char *strcat(char *strDestination, const char *strSource); 将字串复制到目的串后面
	//int strcmp(const char *string1, const char *string2);
	//返回值 < 0, 表示string1小于string2;
	//返回值为0, 表示string1等于string2;
	//返回值 > 0, 表示string1大于string2.
	//int argc,char **argv
	//argc是参数个数，第一个是exe的目录，argv存放着字符串