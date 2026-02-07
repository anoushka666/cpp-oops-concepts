#include <iostream>
#include <string>
using namespace std;
class A{
	mutable int a;
public:
	A(){
		cout<<"A's default constructor called\n";
	}
	A(const A& a){
		cout<<"A's copy Constructor called\n";
	}
};
class B{
	A obj;
public:
	B(){
		cout<<"B's Constructor called\n";
	}
};
int main(int argc, char const *argv[])
{
	B b1;
	B b2;
}
