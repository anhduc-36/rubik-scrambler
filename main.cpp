// Rubik scrambler

#include <iostream>
#include <random>
#include <string>

using namespace std;

const char moves[6] = { 'R', 'L', 'F', 'B', 'U', 'D' };
const char* modifier[3] = { "", "'", "2" };

string generateScramble(int length)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> movesdist(0, 5);
	uniform_int_distribution<int> modifdist(0, 2);
	string scramble;
	int lastMove = -1;
	for (int i = 0; i < length; i++)
	{
		int currentMove;
		// Prevent the same face from moving twice in a row
		do
		{
			currentMove = movesdist(mt);
		} 
		while (currentMove == lastMove);
		scramble += moves[currentMove];
		scramble += modifier[modifdist(mt)];
		scramble += " ";
		lastMove = currentMove;
	}
	return scramble;
}

int main()
{
	int scrambleSize = 20;
	int scrambleCount = 1;

start:
	cout << "Enter your scramble length: ";
	cin >> scrambleSize;
	if (scrambleSize <= 0)
	{
		cout << "Invalid scramble length! Please try again.\n";
		goto start;
	}
	cout << "Enter number of scramble: ";
	cin >> scrambleCount;
	if (scrambleCount <= 0)
	{
		cout << "Invalid scramble count! Please try again.\n";
		goto start;
	}

	cout << "Your Scramble: \n";

	int lastMove = -1;
	for (int i = 0; i < scrambleCount; i++)
	{
		cout << i + 1 << ". " << generateScramble(scrambleSize) << "\n";
	}

	return 0;
}
