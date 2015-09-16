//============================================================================
// Name        : DHCPgen
// Author      : NeedName
// Version     : 1.0.0
// Copyright   : GNU Public License
// Description : DHCPgen written in C++, generates up to 999 DHCP addresses
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>
#include <string>
using namespace std;

int main() {
	int DHCP123 = 0;

	char yn;
	string DHCP;
	string newDHCP;
	string fullDHCP;

	//begin
	cout << "DHCP PC IP Generator" << endl;
	cout << "====================" << endl;

	cout << "Enter the DHCP IP address (found in cmd IPconfig /all)" << endl;
	cin >> DHCP;

	cout << "is the DHCP group less than 1000? Y/N" << endl;
	int a = 0;

	//Establish How many DHCPs you need to generate
	while(a == 0){
		cin >> yn;
		if(yn == 'Y'){
			int b = 0;
			while(b < 100){
				DHCP123 = b;
				newDHCP = static_cast<ostringstream*>( &(ostringstream() << DHCP123) )->str();
				fullDHCP = DHCP + newDHCP;
				cout << fullDHCP << endl;
				b++;
				if(b == 100){
					return 0;
				}
			} a++;
		}
		if(yn == 'N'){
			int c = 0;
			while(c < 1000){
				DHCP123 = c;
				newDHCP = static_cast<ostringstream*>( &(ostringstream() << DHCP123) )->str();
				fullDHCP = DHCP + newDHCP;
				cout << fullDHCP << endl;
				c++;
			} a++;
		}
		else {
			cout << "Invalid character, Please type either Y or N" << endl;
		}
	}
	return 0;
}
