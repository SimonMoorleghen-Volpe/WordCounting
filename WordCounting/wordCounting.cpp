#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	char fileName[50];
	char temp[5];
	ifstream file;
	cout << "Which file do you want read?\n";
	cin.getline(fileName, 50);
	cout << "How many indexes do you wish to know?\n";
	cin.getline(temp, 5);
	int wantedCount = stoi(temp);
	file.open(fileName);

	cout << "\n\n\n";


	//Check to ensure that the file
	//has been opened and is thus there.
	if (!file.is_open()) {
		exit(EXIT_FAILURE);
	}

	//create the vectors that will
	//be used to track which words have been used
	// and how many times they have appeared.
	string word;
	vector<string> wordArray;
	vector<int> countArray;

	//the various variables used in the following while loop
	int currentCount = 0;
	vector<string>::iterator index;
	int foundIndex = 0;

	//while loop to go through the file from beginning to end.
	while (file.good()) {
		file >> word;

		//check if the new word is already known, if so, increment its count,
		// if not, add it and give it a count of 1
		index = find(wordArray.begin(), wordArray.end(), word);
		if (index == wordArray.end()) {
			wordArray.push_back(word);
			countArray.push_back(1);
			currentCount += 1;
		}
		else {
			foundIndex = distance(wordArray.begin(), index);
			countArray[foundIndex] += 1;
		}
	}
    

	//Check to ensure that the number of words wanted shown
	// is less than the number of words known. If not, change it to only show
	// the number known.
	int shownCount = 0;
	vector<int>::iterator countIndex;
	int countTemp;

	if (wantedCount > currentCount) {
		wantedCount = currentCount;
	}

	//while loop to go through the word counts and find the largest, and return it
	while (shownCount < wantedCount) {
		countIndex = max_element(countArray.begin(), countArray.end());
		countTemp = distance(countArray.begin(), countIndex);
		cout << shownCount+1 << ": " << wordArray[countTemp] << " " << * countIndex << "\n";
		*countIndex = 0;
		shownCount += 1;
	}
	

	cout << "\nend";

}