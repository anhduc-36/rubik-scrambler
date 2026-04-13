// Rubik scrambler

#include <iostream>
#include <random>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

const char moves[6] = { 'R', 'L', 'F', 'B', 'U', 'D' };
const char* modifier[3] = { "", "'", "2" };

mt19937 mt(random_device{}());

string generateScramble(int length)
{
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

	do 
	{
        cout << "Enter your scramble length: ";
        cin >> scrambleSize;
        if (scrambleSize <= 0) 
			cout << "Invalid length! Please try again.\n";
    } 
	while (scrambleSize <= 0);

    do 
	{
        cout << "Enter number of scrambles: ";
        cin >> scrambleCount;
        if (scrambleCount <= 0) 
			cout << "Invalid count! Please try again.\n";
    } 
	while (scrambleCount <= 0);
	
	cout << "Save to file? (Y/N): ";
	cin >> saveFile;
	
	bool saving = (tolower(saveFile) == 'y');
	if (saving)
    {
		ios_base::sync_with_stdio(false);
		cout.tie(NULL);
		
        string filename = "scramble.txt";
        cout << "Enter filename (e.g. scramble.txt): ";
        cin >> filename;

        if (!freopen(filename.c_str(), "w", stdout))
        {
            cerr << "Error opening file. Scrambles will only print to console.\n";
            saving = false;
        }
    }
	
	cout << "Your Scramble: \n";

	int lastMove = -1;
	for (int i = 0; i < scrambleCount; i++)
		cout << i + 1 << ". " << generateScramble(scrambleSize) << "\n";

	return 0;
}
