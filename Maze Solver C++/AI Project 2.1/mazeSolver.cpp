#include <concrt.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const char Wall = '#';
const char Free = ' ';
const char Mark = '*';

// To print the maze
void printMaze(char **maze, int MazeHeight, int MazeWidth)
{
	for (int i = 0; i < MazeHeight; i++)
	{
		for (int j = 0; j < MazeWidth; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

// recursive algorithm to solve the maze, updating as it goes
bool Solve(char **maze, int X, int Y, int endingPointX, int endingPointY, int MazeWidth, int MazeHeight)
{
	// make the move. if it's wrong, it will backtrack later.
	maze[Y][X] = Mark;

	printMaze(maze, MazeHeight, MazeWidth);
	cout << "===================================================" << endl;

	// sleep for progressive updates... this amount of time is fine for smaller mazes but you might wanna make it smaller for larger ones.
	Concurrency::wait(250);
	// Check if we have reached our goal.
	if (maze[endingPointY][endingPointX] == Mark)
	{
		return true;
	}

	// Recursively search for our goal.
	if (X > 0 && maze[Y][X - 1] == Free && Solve(maze, X - 1, Y, endingPointX, endingPointY, MazeWidth, MazeHeight))
	{
		return true;
	}
	if (X < MazeWidth && maze[Y][X + 1] == Free && Solve(maze, X + 1, Y, endingPointX, endingPointY, MazeWidth, MazeHeight))
	{
		return true;
	}
	if (Y > 0 && maze[Y - 1][X] == Free && Solve(maze, X, Y - 1, endingPointX, endingPointY, MazeWidth, MazeHeight))
	{
		return true;
	}
	if (Y < MazeHeight && maze[Y + 1][X] == Free && Solve(maze, X, Y + 1, endingPointX, endingPointY, MazeWidth, MazeHeight))
	{
		return true;
	}

	// Otherwise we need to backtrack and find another solution.
	maze[Y][X] = Free;

	printMaze(maze, MazeHeight, MazeWidth);
	cout << "===================================================" << endl;

	// sleep for progressive updates...
	Concurrency::wait(250);

	return false;
}

int main() {
	cout << "Hi there, heard you couldn't solve a maze. Imma do it for you..." << endl;
	// ask user for maze file, use ifstream for input
	cout << "Enter the maze file you want to solve: ";
	string filename;
	cin >> filename;

	ifstream filein;
	filein.open(filename);
	string line;
	string dims;

	if (filein.is_open())
	{
		while (getline(filein, line))
		{
			dims = line;
			filein.close();
		}
	}
	else
		cout << "Could not locate file." << endl;
	
	// use vector to split string by spaces, getting the separate dimensions of the maze
	vector<string> result;
	istringstream iss(dims);
	for (string dims; iss >> dims; )
		result.push_back(dims);
	
	const int MazeHeight = stoi(result[0]);
	const int MazeWidth = stoi(result[1]);

	cout << "Dimensions: " << MazeHeight << " " << MazeWidth << endl;

	// now input the rest of the maze into a string
	ifstream mazein;
	mazein.open(filename);
	string line2;
	string stringMaze;
	if (mazein.is_open())
	{
		// ignore first line, we already have that info
		getline(mazein, line2);
		while (getline(mazein, line2))
		{
			stringMaze += line2;
		}
		filein.close();
		cin.get();
	}

	// now form a 2d char array from that string, since we need that format for our algorithm to work correctly
	char **maze = new char*[MazeHeight];
	for (int i = 0; i < MazeHeight; i++)
		maze[i] = new char[MazeWidth];

	int count = 0;
	for (int i = 0; i < MazeHeight; i++)
	{
		for (int j = 0; j < MazeWidth; j++)
		{
			maze[i][j] = stringMaze[count];
			count++;
		}
	}

	// The printed maze
	printMaze(maze, MazeHeight, MazeWidth);

	// get the starting and ending points of the maze
	int startingPointX = 0; // starting point always on left hand side
	int startingPointY;
	int endingPointX = MazeWidth-1; // always on right hand side
	int endingPointY;
	for (int i = 0; i < MazeHeight; i++)
	{
		if (maze[i][0] == Free)
		{
			startingPointY = i;
		}
		if (maze[i][MazeWidth-1] == Free)
		{
			endingPointY = i;
		}
	}
	cout << "Starting point: (" << startingPointY << ", 0)" << endl;
	cout << "Ending point: (" << endingPointY << ", " << endingPointX << ")" << endl;
	cout << "Ending point: " << maze[endingPointY][endingPointX] << ":)" << endl;

	if (Solve(maze, startingPointX, startingPointY, endingPointX, endingPointY, MazeWidth, MazeHeight))
	{
		printMaze(maze, MazeHeight, MazeWidth);
		cout << "Solved!" << endl;
	}
	else
	{
		cout << "I was unable to solve your maze :(" << endl;
	}
	cin.get();
	return 0;
}