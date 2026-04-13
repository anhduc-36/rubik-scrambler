// Rubik scrambler

#include <iostream>
#include <random>
#include <string>

using namespace std;

const char moves[6] = {'R', 'L', 'F', 'B', 'U', 'D'};
const char* modifier[3] = {"", "'", "2"};

int main()
{
    int sz = 20;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> movesdist(0,5);
    uniform_int_distribution<int> modifdist(0,2);

	start:
	cout << "Enter your scramble length: ";
	cin >> sz;
	if (sz <= 0)
	{
		cout << "Invalid scramble! Please try again.\n";
		goto start;
	}
	
	cout << "Your Scramble: ";
    
	int lastMove = -1;
    for (int i = 0; i < sz; i++)
    {
        int currentMove;

        // Prevent the same face from moving twice in a row
        do
        {
            currentMove = movesdist(mt);
        }
        while (currentMove == lastMove);
        cout << moves[currentMove] << modifier[modifdist(mt)] << " ";
        lastMove = currentMove;
    }
    return 0;
}
