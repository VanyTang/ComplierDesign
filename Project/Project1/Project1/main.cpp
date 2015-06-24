#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(){
	map<string, string> label;
	char a;

	label.insert(map<string, string>::value_type("label1", "label232"));

	map<string,string>::iterator l_it = label.find("label1");
	if (l_it == label.end()){
		cout << "no such value" << endl;
		return 1;
	}
	cout << l_it->second << endl; 
	cin >> a;

	return 0;
}