#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	// Variables
	char board [10] = {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	int playerx = 2;
	char playericon = 1;

	while (true)
	{
		if (kbhit()) {
			char input = getch();
			if (input == 'a')
			{
				playerx--;
			}
			else if (input == 'd')
			{
				playerx++;
			}
		}
		system("cls");
		int i = 0;
		while(i<10)
		{
			if(i == playerx)
			{
				cout << playericon;
			}
			else
			{
				cout << board [i];
			}
			i++;
		}
		cout << "\n";
		// Frame rate limiter
		Sleep(50);
	}
}
