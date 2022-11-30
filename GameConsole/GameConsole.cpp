#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <ctime>
using namespace std;

int HP = 30;
int power = 5;
int level;

char Player = 'P';
char Enemy = 'E';
char firstAidKit = 'A'; //аптечка
char buffs = 'B';

const int width = 25, height = 25; //ширина высота
const int WidthHeight = width * height;
int array[width][height];
int dir = 4;

const int border = 1, emptyField = 0, fieldEnemy = 2, fieldFirstAidKit = 3, fieldBuffs = 4;

int z, z1;
COORD c; //объект хранения координат

class Map {
private:
	int size;
	vector<vector<int>> map;
public:
	Map() {
		size = 25;
	}


	void initMap() {
		for (int i = 0; i < size; i++) {
			vector<int > temp;
			for (int j = 0; j < size; j++) {
				if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
					temp.push_back(1);
				else
					temp.push_back(0);

			}
			map.push_back(temp);
		}
	}

	void ShowMap() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (map[i][j] == border) {
					cout << '-';
				}
				else if (map[i][j] == emptyField) {
					cout << " ";
				}
				else if (map[i][j] == fieldEnemy) {
					cout << Enemy;
				}
				else if (map[i][j] == fieldFirstAidKit) {
					cout << firstAidKit;
				}
				else if (map[i][j] == fieldBuffs) {
					cout << buffs;
				}
			}
			cout << endl;
		}
	}

	void setEnemy(int numEnemy) {
		for (int i = 0; i < numEnemy; i++) {
			int x_Enemy;
			int y_Enemy;
			do {
				x_Enemy = rand() % (size - 2) + 1;
				y_Enemy = rand() % (size - 2) + 1;
				
			} while (map[x_Enemy][y_Enemy] == 2);
			map[x_Enemy][y_Enemy] = 2;

		}
	}

	void FirstAidKit(int numFirstAidKit)
	{
		int x_FirstAidKit, y_FirstAidKit;
		for (int i = 0; i < numFirstAidKit; i++) {
			do
			{
				x_FirstAidKit = rand() % (size - 2) + 1;
				y_FirstAidKit = rand() % (size - 2) + 1;
			} while (map[x_FirstAidKit][y_FirstAidKit] == 3);

			map[x_FirstAidKit][y_FirstAidKit] = 3;
		}

	}

	void Buff(int numBuffs)
	{
		int x_Buffs, y_Buffs;
		for (int i = 0; i < numBuffs; i++) {
			do
			{
				x_Buffs = rand() % (size - 2) + 1;
				y_Buffs = rand() % (size - 2) + 1;
			} while (map[x_Buffs][y_Buffs] == 4);

			map[x_Buffs][y_Buffs] = 4;
		}

	}

};


//void GenerateMap()
//{
//	int X_Enemy; // абсцисса врага
//	int Y_Enemy; //ордината врага
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // 
//	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // создание параметров на отображение курсора
//	SetConsoleCursorInfo(h, &cci); //связывание параметров и хендла
//	for (int y = 0; y < height; y++) // цикл на отрисовку рамки
//	{
//		for (int x = 0; x < width; x++)
//		{
//			char s;
//			if (x == 0 && y == 0) // в верхнем левом углу поля - символ соответствующего угла
//				s = 48;
//			else if (x == 0 && y == height - 1) // нижний левый угол
//				s = 48;
//			else if (y == 0 && x == width - 1) // верхний правый угол
//				s = 48;
//			else if (y == height - 1 && x == width - 1) // нижний правый угол
//				s = 48;
//			else if (y == 0 || y == height - 1) // верхняя и нижняя граница поля
//				s = 48;
//			else if (x == 0 || x == width - 1) // левая и правая граница поля
//				s = 48;
//			else s = ' '; // пустая область поля
//			putchar(s); // выводим символ
//		}
//		cout << endl;
//	}
//
//	int z = width / 2;
//	int z1 = height / 2;
//	array1[z + z1 * width] = 10;
//
//
//	
//	int sleep_time = 100; // переменная частоты кадров 
//
//
//
//};


void Key(int key, int a, int b) //передвижение по кнопкам
{
	switch (key)
	{
	case 101: dir = 0; break;
	case 102: dir = 2; break;
	case 100: dir = 1; break;
	case 103: dir = 3; break;
	}


}

void UpdateMap()
{


}

void Move(char direction)
{

}

void Fight()
{

}

void Healing()
{

}


void Save()
{

}


int main()
{
	setlocale(LC_ALL, "");
	cout << "Выберите уровень сложности: " << endl;
	cout << "1 - Легкий " << endl;
	cout << "2 - Средний " << endl;
	cout << "3 - Сложный " << endl;
	cin >> level;
	switch (level) 
	{
	case 1: cout << "          Персонаж               Враг" << endl;
		cout << "Здоровье:  30 XP                 15XP" << endl;
		cout << "Cила:      5 XP                  5XP" << endl;
		break;
	case 2:
		cout << "          Персонаж               Враг" << endl;
		cout << "Здоровье:  20 XP                 15XP" << endl;
		cout << "Cила:      5 XP                  5XP" << endl;
		break;
	case 3:
		cout << "          Персонаж               Враг" << endl;
		cout << "Здоровье:  20 XP                 20XP" << endl;
		cout << "Cила:      5 XP                  5XP" << endl;
		break;
	}
	
	Map map;
	map.initMap();
	map.setEnemy(10);
	srand(time(0));
	map.FirstAidKit(5);
	map.Buff(3);
	map.ShowMap();

}