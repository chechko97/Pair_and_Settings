#include <iostream>
#include "settings.hpp"

using namespace std;

int main()
{
	Pair<int> pair("key", 50);
	cout << pair.getKey() << " " << pair.getValue() << endl;
	cout << endl;

	Settings<int> settings;
	settings.set("key", 26);
	settings.set("key1", 16);
	settings.set("key2", 16);
	settings.set("key3", 16);
	settings.set("key4", 16);
	settings.set("key5", 16);

	int a = 5, b = 0;
	settings.get("key", a);
	cout << a << endl;
	cout << endl;
	settings.get("key1", b);
	cout << b << endl;
	cout << endl;
	
	cout << settings.count() << endl;

	system("pause");
	return 0;
}