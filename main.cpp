// =================================================================
//
// File: main.cpp
// Author: José Ricardo Rosales Castañeda - A01709449
// Date: 09/09/2022
//
// =================================================================
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// =================================================================
// Read lines from the input files
//
// @param filename, input file.
// @return a vector with the lines of the file.
// @complexity: O(n), where n is the number of lines in the file.
// =================================================================
vector<string> readLines(string filename){
	vector<string> lines;
	ifstream file(filename);
	string line;
	while (getline(file, line)){
		lines.push_back(line);
	}
	return lines;
}

// =================================================================
// Split a string into a vector of strings
//
// @param line, string to split.
// @return a vector with the splited words of the string.
// @complexity: O(n), where n is the number of words in the string.
// =================================================================
vector<string> split(string line){
	vector<string> words;
	string word;
	for (int i = 0; i < line.length(); i++){
		if (line[i] == ' '){
			words.push_back(word);
			word = "";
		}
		else{
			word += line[i];
		}
	}
	words.push_back(word);
	return words;
}

// =================================================================
// Filter the lines that contain the searched key word using find().
//
// @param lines, vector of strings.
// @param word, searched key word.
// @return a vector with the lines that contain the key word.
// @complexity: O(n), where n is the number of lines in the vector.
// =================================================================
vector<string> filter(vector<string> lines, string word){
	vector<string> filteredLines;
	for (string line : lines) {
		if (line.find(word) != string::npos) {
			filteredLines.push_back(line);
		}
	}
	return filteredLines;
}

// =================================================================
// Sort register by date uising sort().
//
// @param lines, vector of strings.
// @return a vector with the lines sorted by date.
// @complexity: O(n log n), where n is the number of lines in the 
// vector.
// =================================================================
vector<string> sortLines(vector<string> lines){
	sort(lines.begin(), lines.end(), [](string a, string b) {
		vector<string> aSplit;
		vector<string> bSplit;
		string delimiter = "-";
		size_t pos = 0;
		string token;
		while ((pos = a.find(delimiter)) != string::npos) {
			token = a.substr(0, pos);
			aSplit.push_back(token);
			a.erase(0, pos + delimiter.length());
		}
		aSplit.push_back(a);
		while ((pos = b.find(delimiter)) != string::npos) {
			token = b.substr(0, pos);
			bSplit.push_back(token);
			b.erase(0, pos + delimiter.length());
		}
		bSplit.push_back(b);
		return pair<string, string>(aSplit[1], aSplit[0]) < 
		pair<string, string>(bSplit[1], bSplit[0]);
	});
	return lines;
}

// =================================================================
// Keep only last column of each line using split().
//
// @param lines, vector of strings.
// @return a vector with the last column of each line.
// @complexity: O(n), where n is the number of lines in the vector.
// =================================================================
vector<string> keepLastColumn(vector<string> lines){
	vector<string> lastColumn;
	for (string line : lines) {
		vector<string> words = split(line);
		lastColumn.push_back(words[words.size() - 1]);
	}
	return lastColumn;
}

// =================================================================
// Month
//
// @param vector of strings, lines.
// @complexity: O(n), where n is the number of lines in the vector.
// =================================================================
void month(vector<string> filteredLines, ofstream& output, string month, string date){
	vector<string> aux, M, R, lastColumnM, lastColumnR;

	output << month << endl;
	aux = filter(filteredLines, date);
	M = filter(aux, " M ");
	R = filter(aux, " R ");
	lastColumnM = keepLastColumn(M);
	lastColumnR = keepLastColumn(R);
	if(M.size() > 0){
		output << "M " << M.size() << ": "; 
		for (string line : lastColumnM){
			output << line << " ";
		}
		output << endl;
	}
	if(R.size() > 0){
		output << "R " << R.size() << ": ";
		for (string line : lastColumnR){
			output << line << " ";
		}
	}
	output << endl;
}


int main(int argc, char* argv[]) {
	string delimiter = " ", token, firstLine;
	vector<string> lines, firstLineSplit, filteredLines, jan, feb, mar, 
	apr, may, jun, jul, aug, sep, oct, nov, dec, M, R, lastColumnM, lastColumnR;
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	// error handling
	if (argc != 3) {
		cout << "Usage: " << " <input file> <output file>" << endl;
		return -1;
	}else if (!input) {
		cout << "Error: Could not open input file " << argv[1] << endl;
		return -1;
	}else if (!output) {
		cout << "Error: Could not open output file " << argv[2] << endl;
		return -1;
	}

	// read input and store it in a vector
	lines = readLines(argv[1]);

	// get first line and split it
	firstLine = lines[0];
	firstLineSplit = split(firstLine);

	// filter lines and store them in a vector
	filteredLines = filter(lines, firstLineSplit[1]);
	filteredLines.erase(filteredLines.begin());

	// sort lines by date
	filteredLines = sortLines(filteredLines);

	month(filteredLines, output, "jan", "-01-");
	month(filteredLines, output, "feb", "-02-");
	month(filteredLines, output, "mar", "-03-");
	month(filteredLines, output, "apr", "-04-");
	month(filteredLines, output, "may", "-05-");
	month(filteredLines, output, "jun", "-06-");
	month(filteredLines, output, "jul", "-07-");
	month(filteredLines, output, "aug", "-08-");
	month(filteredLines, output, "sep", "-09-");
	month(filteredLines, output, "oct", "-10-");
	month(filteredLines, output, "nov", "-11-");
	month(filteredLines, output, "dec", "-12-");

	input.close();
	output.close();

	return 0;
}
