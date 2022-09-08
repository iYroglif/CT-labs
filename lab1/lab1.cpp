#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Planets {
private:
	int Number;
	string Name;
	long int Diameter;
	int Satellites;
	bool Life;
public:
	int getNumber() {
		return Number;
	};
	string getName() {
		return Name;
	};
	long int getDiameter() {
		return Diameter;
	};
	int getSatellites() {
		return Satellites;
	};
	bool getLife() {
		return Life;
	};
	void setNumber(int newNumber) {
		Number = newNumber;
	};
	void setName(string newName) {
		Name = newName;
	};
	short setDiameter(long int newDiameter) {
		if (newDiameter < 1) {
			return 1;
		}
		else {
			Diameter = newDiameter;
			return 0;
		}
	};
	short setSatellites(int newSatellites) {
		if (newSatellites < 0) {
			return 1;
		}
		else {
			Satellites = newSatellites;
			return 0;
		}
	};
	short setLife(int newLife) {
		if (newLife != 0 && newLife != 1) {
			return 1;
		}
		else {
			Life = bool(newLife);
			return 0;
		}
	};
	void inputName(Planets *solarSystem, int num) {
		string newName, temp;
		int i;
		short res;
		num--;
		do {
			cout << "������� ��� �������: ";
			cin >> newName;
			res = 0;
			for (i = 0; i < num; i++) {
				temp = solarSystem[i].getName();
				if (newName == temp) {
					cout << "��� ������� �� ������ ��������� � �������. ";
					res = 1;
					break;
				}
			}
		} while (res != 0);
		setName(newName);
	};
	void inputDiameter() {
		int res;
		long int newDiameter;
		do {
			cout << "������� ������� �������: ";
			cin >> newDiameter;
			res = setDiameter(newDiameter);
			if (res != 0) {
				cout << "��������� ������������ ������ (������� ������ ���� ������ 0). ";
			}
		} while (res != 0);
	};
	void inputSatellites() {
		int res;
		int newSatellites;
		do {
			cout << "������� ���������� ��������� �������: ";
			cin >> newSatellites;
			res = setSatellites(newSatellites);
			if (res != 0) {
				cout << "��������� ������������ ������ (���������� �� ������ ���� �������������). ";
			}
		} while (res != 0);
	};
	void inputLife() {
		int res, newLife;
		do {
			cout << "�� ������� ���� �����? (1 - ����, 0 - ���): ";
			cin >> newLife;
			res = setLife(newLife);
			if (res != 0) {
				cout << "��������� ������������ ������. ";
			}
		} while (res != 0);
	};
	void inputInfoPlanet(Planets *arr, int num) {
		cout << "��������� ���������� � ������� ����� " << num << ":" << endl;
		setNumber(num);
		inputName(arr, num);
		inputDiameter();
		inputSatellites();
		inputLife();
		cout << endl;
	};
	void changeName(Planets *solarSystem, int numPlanets) {
		string newName, temp;
		int i;
		short res;
		do {
			cout << "������� ����� ��� �������: ";
			cin >> newName;
			res = 0;
			for (i = 0; i < getNumber() - 1; i++) {
				temp = solarSystem[i].getName();
				if (newName == temp) {
					cout << "��� ������� �� ������ ��������� � �������. ";
					res = 1;
					break;
				}
			}
			if (res == 0) {
				for (i++; i < numPlanets; i++) {
					temp = solarSystem[i].getName();
					if (newName == temp) {
						cout << "��� ������� �� ������ ��������� � �������. ";
						res = 1;
						break;
					}
				}
			}
		} while (res != 0);
		setName(newName);
		cout << endl;
	}

	void infoPlanet() {
		cout << "������� ����� " << getNumber() << ":" << endl;
		cout << "���: " << getName() << endl;
		cout << "�������: " << getDiameter() << endl;
		cout << "���������� ���������: " << getSatellites() << endl;
		cout << "������� �����: " << boolalpha << getLife() << endl << endl;
	}

};

void sortDiameter(Planets *, int);
void sortSatellites(Planets *, int);
void sortName(Planets *, int);
void sortLife(Planets *, int);
int searchPlanet(Planets *, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	int numPlanets, i, tar, j, curnum;
	string newName2, stemp;
	Planets *solarSystem = NULL;
	short res;
	cout << "������� ���������� ������: ";
	cin >> numPlanets;
	cout << endl;
	solarSystem = new Planets[numPlanets];
	for (i = 0; i < numPlanets; i++) {
		solarSystem[i].inputInfoPlanet(solarSystem, i + 1);
	}
	for (i = 0; i < numPlanets; i++) {
		solarSystem[i].infoPlanet();
	}
	do {
		cout << endl << "������� ����� �������.\n1 - ������� ���������� � ���� ��������\n2 - �������� ����� �������\n3 - �������� ��� �������\n4 - �������� ������� �������\n5 - �������� ���������� ��������� �������\n6 - �������� ������� ����� �������\n7 - ���������� ������ �� �����\n8 - ���������� ������ �� ��������\n9 - ���������� ������ �� ���������� ���������\n10 - ���������� ������ �� ������� �����\n11 - �������� ����� �������\n12 - ������� �������\n0 - ����� �� ���������." << endl;
		cin >> tar;
		cout << endl;
		switch (tar) {
		case 1: {
			for (i = 0; i < numPlanets; i++) {
				solarSystem[i].infoPlanet();
			}
			break;
		}
		case 2: {
			i = searchPlanet(solarSystem, numPlanets);
			do {
				res = 0;
				cout << "������� ����� ����� ���� �������: " << endl;
				cin >> curnum;
				if (curnum > 0 && curnum <= numPlanets) {
					i--;
					solarSystem[i].setNumber(curnum);
					curnum--;
					if (i < curnum) {
						for (i; i < curnum; i++) {
							swap(solarSystem[i], solarSystem[i + 1]);
							solarSystem[i].setNumber(i + 1);
						}
					}
					else {
						for (i; i > curnum; i--) {
							swap(solarSystem[i], solarSystem[i - 1]);
							solarSystem[i].setNumber(i + 1);
						}
					}
					res = 1;
				}
				else {
					cout << "��������� ������������ ������ (����� ������� ������ ���� � ������� �� 1 �� " << numPlanets << "). ���������� ������." << endl;
				}
			} while (res != 1);
			cout << "������� ������ �������." << endl;
			break;
		}

		case 3: {
			i = searchPlanet(solarSystem, numPlanets);
			solarSystem[i - 1].changeName(solarSystem, numPlanets);
			cout << "��� ������� ��������." << endl;
			break;
		}
		case 4: {
			i = searchPlanet(solarSystem, numPlanets);
			solarSystem[i - 1].inputDiameter();
			cout << "������� ������� �������." << endl;
			break;
		}
		case 5: {
			i = searchPlanet(solarSystem, numPlanets);
			solarSystem[i - 1].inputSatellites();
			cout << "���������� ��������� ������� ��������." << endl;
			break;
		}
		case 6: {
			i = searchPlanet(solarSystem, numPlanets);
			solarSystem[i - 1].inputLife();
			cout << "������� ����� �� ������� ��������." << endl;
			break;
		}
		case 7: {
			sortName(solarSystem, numPlanets);
			break;
		}
		case 8: {
			sortDiameter(solarSystem, numPlanets);
			break;
		}
		case 9: {
			sortSatellites(solarSystem, numPlanets);
			break;
		}
		case 10: {
			sortLife(solarSystem, numPlanets);
			break;
		}
				 /*case 10: {
					 do {
						 cout << "������� ������ ������: ";
						 cin >> i;
						 cin >> j;
						 if ((i > 0 && i <= numPlanets) && (j > 0 && j <= numPlanets)) {
							 solarSystem[i - 1].setNumber(j);
							 solarSystem[j - 1].setNumber(i);
							 swap(solarSystem[i - 1], solarSystem[j - 1]);
							 cout << "������ ������ ��������." << endl;
						 }
						 else {
							 cout << "��������� ������������ ������. ";
						 }
					 } while (i < 0 || i > numPlanets || j < 0 || j > numPlanets);
					 break;
				 } */
		case 11: {
			do {
				cout << "������� ����� ����� ������� (����� ������ " << numPlanets << "): " << endl;
				cin >> i;
				Planets *temp = new Planets[numPlanets + 1];
				if (i > 0 && i <= numPlanets + 1) {
					numPlanets++;
					for (j = 0; j < i - 1; j++) {
						temp[j] = solarSystem[j];
					}
					for (j = i - 1; j < numPlanets - 1; j++) {
						solarSystem[j].setNumber(j + 2);
						temp[j + 1] = solarSystem[j];
					}
					cout << "��������� ���������� � ����� �������: " << endl;
					temp[i - 1].setNumber(i);
					do {
						cout << "������� ��� �������: ";
						cin >> newName2;
						res = 0;
						for (j = 0; j < numPlanets - 1; j++) {
							stemp = solarSystem[j].getName();
							if (newName2 == stemp) {
								cout << "��� ������� �� ������ ��������� � �������. ";
								res = 1;
								break;
							}
						}
					} while (res != 0);
					temp[i - 1].setName(newName2);
					temp[i - 1].inputDiameter();
					temp[i - 1].inputSatellites();
					temp[i - 1].inputLife();
					cout << endl;
					delete[]solarSystem;
					solarSystem = temp;
					temp = NULL;
					cout << "����� ������� �������." << endl;
				}
				else {
					cout << "��������� ������������ ������. ";
				}
			} while (i <= 0 || i > numPlanets + 1);
			break;
		}
		case 12: {
			i = searchPlanet(solarSystem, numPlanets);
			for (j = i - 1; j < numPlanets - 1; j++) {
				swap(solarSystem[j], solarSystem[j + 1]);
				solarSystem[j].setNumber(j + 1);
			}
			numPlanets--;
			cout << "������� �������." << endl;
			break;
		}

		case 0: break;

		default: {
			cout << "��������� ������������ ������." << endl;
		}

		}
	} while (tar != 0);
	return 0;
}

void sortDiameter(Planets *arr, int nm) {
	int ij;
	unsigned int *temp = new unsigned int[nm];
	for (int k = 0; k < nm; k++) {
		temp[k] = k;
	}
	cout << "���������� �� ��������" << endl;
	for (int i = 0; i < nm - 1; i++) {
		ij = i;
		for (int j = i + 1; j < nm; j++) {
			if (arr[temp[j]].getDiameter() > arr[temp[ij]].getDiameter()) {
				ij = j;
			}
			else {
				if (arr[temp[j]].getDiameter() == arr[temp[ij]].getDiameter()) {
					if (arr[temp[j]].getNumber() < arr[temp[ij]].getNumber()) {
						ij = j;
					}
				}
			}
		}
		if (ij != i) {
			swap(temp[i], temp[ij]);
		}
		arr[temp[i]].infoPlanet();
	}
	arr[temp[nm - 1]].infoPlanet();
	delete[]temp;
	temp = NULL;
}

void sortSatellites(Planets *arr, int nm) {
	int ij;
	unsigned int *temp = new unsigned int[nm];
	for (int k = 0; k < nm; k++) {
		temp[k] = k;
	}
	cout << "���������� �� ���������" << endl;
	for (int i = 0; i < nm - 1; i++) {
		ij = i;
		for (int j = i + 1; j < nm; j++) {
			if (arr[temp[j]].getSatellites() > arr[temp[ij]].getSatellites()) {
				ij = j;
			}
			else {
				if (arr[temp[j]].getSatellites() == arr[temp[ij]].getSatellites()) {
					if (arr[temp[j]].getNumber() < arr[temp[ij]].getNumber()) {
						ij = j;
					}
				}
			}
		}
		if (ij != i) {
			swap(temp[i], temp[ij]);
		}
		arr[temp[i]].infoPlanet();
	}
	arr[temp[nm - 1]].infoPlanet();
	delete[]temp;
	temp = NULL;
}

void sortName(Planets *arr, int nm) {
	short res;
	int ij;
	unsigned int *temp = new unsigned int[nm];
	for (int k = 0; k < nm; k++) {
		temp[k] = k;
	}
	cout << "���������� �� �����" << endl;
	for (int i = 0; i < nm - 1; i++) {
		ij = i;
		for (int j = i + 1; j < nm; j++) {
			res = strcoll(arr[temp[j]].getName().c_str(), arr[temp[ij]].getName().c_str());
			if (res == -1) {
				ij = j;
			}
		}
		if (ij != i) {
			swap(temp[i], temp[ij]);
		}
		arr[temp[i]].infoPlanet();
	}
	arr[temp[nm - 1]].infoPlanet();
	delete[]temp;
	temp = NULL;
}

void sortLife(Planets *arr, int nm) {
	int ij;
	unsigned int *temp = new unsigned int[nm];
	for (int k = 0; k < nm; k++) {
		temp[k] = k;
	}
	cout << "���������� �� ������� �����" << endl;
	for (int i = 0; i < nm - 1; i++) {
		ij = i;
		for (int j = i + 1; j < nm; j++) {
			if (arr[temp[j]].getLife() > arr[temp[ij]].getLife()) {
				ij = j;
			}
			else {
				if (arr[temp[j]].getLife() == arr[temp[ij]].getLife()) {
					if (arr[temp[j]].getNumber() < arr[temp[ij]].getNumber()) {
						ij = j;
					}
				}
			}
		}
		if (ij != i) {
			swap(temp[i], temp[ij]);
		}
		arr[temp[i]].infoPlanet();
	}
	arr[temp[nm - 1]].infoPlanet();
	delete[]temp;
	temp = NULL;
}

int searchPlanet(Planets *arr, int numPlanets) {
	string Name;
	short res = 0;
	int i;
	do {
		cout << "������� ��� ������ �������: ";
		cin >> Name;
		for (i = 0; i < numPlanets; i++) {
			if (arr[i].getName() == Name) {
				res = 1;
				break;
			}
		}
		if (res != 1) {
			cout << "������� � ����� ������ �� �������. ���������� ������." << endl;
		}
	} while (res != 1);
	return i + 1;
}

/*
8
Mercury
4879
0
0
Venus
12103
0
0
Earth
12742
1
1
Mars
6780
2
0
Jupiter
139822
79
0
Saturn
116464
62
0
Uranus
50724
27
0
Neptune
49244
14
0

*/