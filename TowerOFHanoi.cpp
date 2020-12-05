#include <iostream>

using namespace std;

char checkForOther(char other, char start, char last) {
	if ((start == 'A' && last == 'B') || (start == 'B' && last == 'A'))
		other = 'C';
	else if ((start == 'B' && last == 'C') || (start == 'C' && last == 'B'))
		other = 'A';
	else
		other = 'B';
	return other;
}

void tgen(int n, char* i, char* f) {
	char from_rod = i[0];
	char to_rod = f[0];
	if (n == 0)
		cout << "No Disk present";
	else if (n == 1) {
		cout << "Move from " << from_rod << " to " << to_rod << endl;
		return;
	}
	else {
		char other = ' ';
		other = checkForOther(other, from_rod, to_rod);
		char *newStart = new char[n-1];
		for (int j = 1; j < n; j++)
			newStart[j - 1] = i[j];
		char *newLast = new char[n - 1];
		for (int j = 1; j < n; j++)
			newLast[j - 1] = f[j];
		char *aux = new char[n - 1];
		for (int j = 1; j < n; j++)
			aux[j - 1] = other;
		if (from_rod != to_rod) {

			tgen(n - 1, newStart, aux);

			cout << "Move from " << from_rod << " to " << to_rod << endl;
			tgen(n - 1, aux, newLast);
		}
		else {
			tgen(n - 1, newStart, newLast);
		}
	}
}

int main() {
	char* from; 
	char* to;
	int n;  
	cout << "Total number of disks: ";
	cin >> n;   
	cout << endl;
	from = new char[n]; 
	to = new char[n];
	cout << "Tower from: "<<endl;
	for (int i = 0; i < n; i++) {
		cin >> from[i];    
	}
	cout << "Tower to  : "<<endl; 
	for (int j = 0; j < n; j++) {
		cin >> to[j];
	}
	tgen(n, from, to);
	return 0;
}