// File: ciowens15.cpp
// Carolyn Owens, Transylvania University
// Compiler Construction, Winter 2015

// Reads in a file.
// Takes each character from the file
// and places it into a new output file, unless
// it is a space or a tab. Spaces / tabs are removed.

// Spaces are removed because space is being used as a delimiter by istream
// objects.
// http://stackoverflow.com/questions/18870002/how-to-read-a-space-character-from-a-text-file-in-c )


// Thanks to http://stackoverflow.com/questions/13343991/c-why-cin-eof-read-last-char-twice
// for solving an annoying problem where the last character
// of the text file would be outputted twice.

// Thanks to http://stackoverflow.com/questions/1662624/c-ifstream-open-problem-with-passing-a-string-for-text-file-name
// for solving a problem with passing a string in to ifstream.open().

#include <iostream>
#include <fstream>

using namespace std;

int main (void)
{
	// Declarations //
	// ifstream declaration farther down
	string filename;
	char temp;
	bool eofReturn = false;
	ofstream outputFile ("output.txt");
	///

	cout << "Enter input file name w/ extension: ";
	cin >> filename;

	ifstream inputFile(filename.c_str());
	if (inputFile.is_open())
	{
		while ( inputFile >> temp )
		{
			if (temp == '\n' || temp == '\r')
			{
				cout << "New line" << endl;
			}
			outputFile << temp;
		}
		cout << "Done; output is in output.txt" << endl;
		return 0;
	}
	else
	{
		cout << "Something went wrong loading your file." << endl;
		return 1;
	}
}
