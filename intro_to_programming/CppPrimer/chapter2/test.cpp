#include <iostream>

int main() {
	using namespace std;
	long double d =3.13;
	int a = d;
	int b(d);
	int c = {d};
	int f{d};	

	cout << a << " " << b << " " << c << " " << f;	
	return 0;
}
