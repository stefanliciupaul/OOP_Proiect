#pragma once
using namespace std;
class ProjectExceptionDeleteFrom : exception
{

};

//DELETE FROM table_name WHERE column_name = value
class DeleteFrom {
	string tableName = ""; //Table name
	char** input = nullptr; //Matrix with all words in the input
	int nrWords = 0; //Number of words in the input, matrix

public:
	DeleteFrom(char** newInput, int newNrWords) {
		this->nrWords = newNrWords - 4;
		this->tableName = string(newInput[0]);
		this->input = new char* [this->nrWords];
		newNrWords = newNrWords - 2;
		for (int i = 2; i < newNrWords; i++) {
			this->input[i - 2] = new char[strlen(newInput[i] + 1)];
		}
		for (int i = 2; i < newNrWords; i++) {
			strcpy(this->input[i - 2], newInput[i]);
		}
		for (int i = 0; i < this->nrWords; i++) {
			cout << endl << this->input[i];
		}
	}

	void startDelete() {
		if (this->nrWords == 0 || this->nrWords == 2) {
			this->getInfo();
		}
		else {
			throw new ProjectExceptionDeleteFrom();
		}
	}

	void getInfo() {
		if (this->nrWords == 0) {
			cout << endl << "Deletes all information from table " << this->tableName;
		}
		else {
			cout << endl << "From table " << this->tableName << " all information is deleted where column " << this->input[0] << " = " << this->input[1];
		}
	}
};