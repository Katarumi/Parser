// File: ciowens15.cpp
// Carolyn Owens, Transylvania University
// Compiler Construction, Winter 2015

// Reads in a file character by character.
// All characters except for spaces,
// tabs, and comments are placed into
// output.txt. All outputted characters will be
// converted into lowercase. Strings will be
// outputted as-is with no editing. 

// Removing empty lines would best be done recursively;
// I should work on that for the next version.
// Also modularize into more functions.

// Old References (See V1 for details)

// http://stackoverflow.com/questions/18870002/how-to-read-a-space-character-from-a-text-file-in-c )
// http://stackoverflow.com/questions/13343991/c-why-cin-eof-read-last-char-twice
// to http://stackoverflow.com/questions/1662624/c-ifstream-open-problem-with-passing-a-string-for-text-file-name

// New References

// http://www.cplusplus.com/reference/istream/istream/get/
// For references on get.

#include <iostream>
#include <fstream>

using namespace std;
int parse(string filename);

int main (void)
{
	string filename;

	cout << "Enter input file name w/ extension: ";
	cin >> filename;
	parse(filename);
}

int parse (string filename)
{
	// Parse Decs //
	char temp;
	bool eolFlag = false;
	ofstream outputFile ("output.txt");
	ifstream inputFile(filename.c_str());

	if (inputFile.is_open())
	{
		while (inputFile.get(temp))
		{
			if (temp == '"')
			{
				outputFile << temp;
				temp = ' ';
				// Putting inputfile.eof() here prevents an infinite loop in the event
				// someone forgets an ending double quote. It won't provide good
				// output, but at least it doesn't explode.
				while (temp != '"')
				{
					inputFile.get(temp);
					outputFile << temp;
					if (!inputFile.eof())
					{
						cout << "Error: Mismatched double quote." << endl;
						outputFile.close();
						return 1;
					}
				}
			}
			else
			{
				if (temp == ' ' || temp == '	')
				{}
				else
				{
					if (temp == 'C')
					{
						inputFile.get(temp);
						if (temp == '*')
						{
							string comment;
							getline(inputFile,comment);
						}
						else
						{
							outputFile << 'c';
							temp = tolower(temp);
							outputFile << temp;
						}
					}
					else
					{
						if (temp == '\n')
						{
							if (eolFlag == true)
							{}
							else
							{
								outputFile << temp;
							}
							eolFlag = true;
						}
						else
						{
							eolFlag = false;
							temp = tolower(temp);
							outputFile << temp;
						}
					}
				}
			}
		}
		cout << "Done; output is in output.txt" << endl;
		outputFile.close();
		return 0;
	}
	else
	{
		cout << "Something went wrong loading your file." << endl;
		return 1;
	}
}
