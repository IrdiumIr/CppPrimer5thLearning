//Ex7.57  编写你自己的Account类。

//P269
#include <string>
using std::string;
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
    
private:
    string owner;
    double amount;
    static double interestRate;
    static constexpr int period = 30;
    static int initRate() { return period; }
};

double Account::interestRate = initRate();//静态成员在类外定义
constexpr int Account::period;