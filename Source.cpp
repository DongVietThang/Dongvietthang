#include<iostream>
#include<ctime>
#include<conio.h>
#include<windows.h>


using namespace std;

int i, j, a=10, b=20, c=10, d=10, score;

void giaodien()
{
	//giao dien
	system("cls");
	char khung[20][40];
	for (int i = 0; i < 40; i++)
	{
		khung[0][i] = '=';
		khung[19][i] = '=';
	}
	for (int i = 1; i < 19; i++)
	{
		khung[i][0] = '|';
		khung[i][39] = '|';
	}


	//con ran
	khung[a][b] = 'o';
	char conran = khung[a][b];


	//thuc an
	khung[c][d] = '+';
	char thucan = khung[c][d];



	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 40; i++)
		{
			cout << khung[j][i];
		}
		cout << endl;
	}	

	cout << " diem cua ban: " << score;
}

void move()
{
	_kbhit();
	switch (_getch())
		{
		case 'a':
			b--;
			break;
		case 's':
			a++;
			break;
		case 'd':
			b++;
			break;
		case 'w':
			a--;
			break;
		}
}


//quy luat choi
boolean anmoi()
{
	if (a == j && b == i)
		return true;
	else
		return false;
}

boolean logic()
{
	if (a == 0 || a == 19 || b == 0 || b == 39)
	{
		cout << "\nban da thua va dat dc: "<< score;
		return true;
	}
	else return false;
}
int main()
{
	while (!logic())
	{
			
			if (a == c && b == d)
			{
				srand(time(0));
				c = rand() % 18 + 1;
				d = rand() % 38 + 1;
				score += 10;
			}
			else
			{
				giaodien();
				move();
			}
	}
	system("pause");
	return 0;
}