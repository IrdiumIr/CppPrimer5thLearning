//练习项目：基本的几何管理程序
//  1. 定义矩形、三角形等若干基本几何类型
//  2. 定义单独的打印类，来计算并输出各个几何体的周长、面积
//  3. 部分几何体类的实现需要考虑到多种构造的情况，例如某些参数缺省时如何构造

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;
using std::endl;

class Print;

//圆类
class Circle 
{
	friend class Print;

public:
    Circle() = default;
    //Circle(double r) : radius(r) {	}
	//与使用默认圆心的Circle类容易造成匹配冲突
	Circle(double r, double posX = 0.0, double posY = 0.0) : radius(r), circleCenterX(posX), circleCenterY(posY) {	}

	//Circle(double r) : Circle(r, 0.0, 0.0) {	}//使用委托构造，注释因为防止与非默认构造函数冲突

	void setR(double r){
		radius = r;
	}

	double getR(){
		return radius;
	}

	void setCircleCenter(double posX, double posY){
		circleCenterX = posX;
		circleCenterY = posY;
	}

	double getCirclePosX(){
		return circleCenterX;
	}
	double getCirclePosY(){
		return circleCenterY;
	}
	//判断成立条件
	bool isCircle(){
		return (radius > 0);
	}
	double getGirth() const {
		return radius * 2 * M_PI;
	}
	// double getGirth() {circleGirth = radius * 2 * M_PI; return circleGirth;}

	double getArea(){
		circleArea = radius * radius * M_PI;
		return circleArea;
	}

private:
	double radius = 1.0;//半径
	double circleCenterX = 0.0;//圆心坐标(x,y)
	double circleCenterY = 0.0;
	double circleGirth = 0.0;//周长
	double circleArea = 99;//for test
};

//矩形类
class Rectangle
{
	friend class Print;

public:
    Rectangle() = default;
    //Rectangle(double LeftUppX, double LeftUppY, double RightDownX, double RightDownY) : x1(LeftUppX), y1(LeftUppY), x2(RightDownX), y2(RightDownY) {	}
	Rectangle(double LeftUppX, double LeftUppY, double RightDownX, double RightDownY, double posX = 0.0, double posY = 0.0) : x1(LeftUppX), y1(LeftUppY), x2(RightDownX), y2(RightDownY), RecCenterX(posX), RecCenterY(posY) {	}
	
	void setRectangle(double LeftUppX, double LeftUppY, double RightDownX, double RightDownY)
	{
		x1 = LeftUppX;
		y1 = LeftUppY;
		x2 = RightDownX;
		y2 = RightDownY;
	}
	//判断成立条件
	bool isRec(){
		return ((a * b) > 0);
	}

	double getRecGirth(){
		RecGirth = 2 * (a + b);
		return RecGirth;
	}
    
    double getRecArea(){
		RecArea = a * b;
		return RecArea;
	}
	
private:
	double x1 = 0.0, y1 = 0.0, x2 = 1.0, y2 = 1.0;//对角线两点
	double a = fabs(x1 - x2);
	double b = fabs(y1 - y2);
	double RecCenterX = 0.0;
	double RecCenterY = 0.0;
	double RecGirth = 0.0; //周长
	double RecArea = 0.0;//面积
};

//三角形类
class Triangle
{
	friend class Print;

public:
    Triangle() = default;
    Triangle(double x, double y, double z, double Ox = 0.0, double Oy = 0.0) : a(x), b(y), c(z), posX(Ox), posY(Oy) {	}

    void setTriangle(double x, double y, double z){
		a = x;
		b = y;
		c = z;
	}
	//判断成立条件
	bool isTri(){
		return ((a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a));
	}

	double getTriGirth(){
		TriGirth = a + b + c;
		return TriGirth;
	}
    
    double getTriArea(){
		double p = (a + b + c) / 2;
		TriArea = sqrt(p * (p - a) * (p - b) * (p - c));
		return TriArea;
	}

private:
	double a = 1.0, b = 1.0, c = 1.0;
	double posX = 0.0;//固定点O
	double posY = 0.0;
	double TriGirth = 0.0; //周长
	double TriArea = 0.0;//面积
};

class Print
{
	//不用const Type&因为可能对图形类修改
public:
	// void printGirth(Circle& cir) const{std::cout << "The girth of this circle is : " << cir.getGirth() << std::endl;}
	// void printGirth(Rectangle& rec) {std::cout << "The girth of this rectangle is : " << rec.getRecGirth() << std::endl;}
	// void printGirth(Triangle& tri) {std::cout << "The girth of this triangle is : " << tri.getTriGirth() << std::endl;}
	// void printArea(Circle& cir) {std::cout << "The area of this circle is : " << cir.getArea() << std::endl;}
	// void printArea(Rectangle& rec) {std::cout << "The area of this rectangle is : " << rec.getRecArea() << std::endl;}
	// void printArea(Triangle& tri) {std::cout << "The area of this triangle is : " << tri.getTriArea() << std::endl;}
public:
	void printArea(Circle &cir, std::ostream &os) {
		std::cout << "Area of this circle is : ";
		do_printArea(cir, os);
	}
private:
	void do_printArea(Circle &cir, std::ostream &os) { os << cir.circleArea; }
};

int main()
{
	Circle cir;
	Rectangle rec;
	Triangle tri;
	Print p1;
	// if(cir.isCircle()&&rec.isRec()&&tri.isTri())
	// {
	// 	p1.printGirth(cir);
	// 	p1.printGirth(rec);
	// 	p1.printGirth(tri);
	// 	p1.printArea(cir);
	// 	p1.printArea(rec);
	// 	p1.printArea(tri);
	// }

	p1.printArea(cir, cout);
}

// 1.Print作为友元类，是否需要有严格的先后定义声明顺序（友元函数需要有）
// 2.单独定义了print类，但是print类似乎不需要有数据成员，这样的函数直接作为接口函数也可以？单独定义类的原因是？
// 3.两种get的方式，不把周长和面积作为数据成员有优劣吗
// 4.带参数的默认构造函数和使用类内初始值的区别？	Circle(double r=1, double posX=0, double posY=0){radius=r;circleX=posX;circleY=posY;}
// 5.所有类的成员函数是否有必要定义为const
// 6.P248介绍的公共代码使用私有功能函数 详细解答