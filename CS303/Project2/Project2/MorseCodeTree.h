#pragma once
#include<iostream>
#include<fstream> //So we can use txt
#include<string>
using namespace std;

struct node {
	//Each node will either go left or right
	char data;
	node* left; //left is .
	node* right;//right is _
	virtual ~node() {}
	node() //Default Node Values, so the left and right node automatically gets created
	{
		left = NULL;
		right = NULL;
		data = NULL;
	}

};

class MorseTree {
public:
	MorseTree() {
		ifstream fin; //We're passing in the morse code .txt file
		fin.open("morse.txt");

		char letter; // This is the letter
		string code; // This is the character

		root = new node; // Declare the root just in case
		//NOTE: root does not have any values, just points towards left and right

		while (fin.good()) // This puts every letter into the tree
		{
			fin >> letter; // This passes only the first character of each line (letter)
			fin >> code; //This passes in everything else in the line (the code);
			insert(letter, code);
		}
		fin.close();
	};

	//Returns only one letter
	char getletter(string x)
	{
		node* temp = root;
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '.')
			{
				temp = temp->left;
			}
			else if (x[i] == '_')
			{
				temp = temp->right;
			}
		}
		//If there's an error. 
		if (temp->data == NULL)
		{
			cout << "ERROR: Wrong Morse Code Inserted";
			return 0;
		}
		return temp->data;
	};

	//Decodes the String
	string decode(string code)
	{
		string x;
		string message;
		for (int i = 0; i < code.size(); i++)
		{
			if (code[i] != ' ')
			{
				x = x + code[i];
			}
			else
			{
				message = message + getletter(x);
				x = "";
			}
		}
		if (x != "")
		{
			message = message + getletter(x);
		}

		return message;
	};

	//This converts a word to morse code
	//NOTE: Assumes that the code is only lower case letters
	string encode(string code)
	{
		string x = "";
		char letter;
		for (int i = 0; i < code.size(); i++)
		{
			x = x + encodeWord(code[i]);
		}
		return x;

	};
	string encodeWord(char letter)
	{
		ifstream fin; //We're passing in the morse code .txt file
		fin.open("morse.txt");

		char comp; // This is the letter
		string code; // This is morse code
						 //NOTE: root does not have any values, just points towards left and right
		if (letter == ' ')
		{
			return " ";
		}

		while (fin.good())
		{
			fin >> comp; // This passes only the first character of each line (letter)
			fin >> code; //This passes in everything else in the line (the code);
			if (letter == comp)
			{
				fin.close();
				return (code + " ");
			}
		}

		fin.close();
		return "ERROR: Use only lower case letters";

	}


private:
	void insert(char letter, string code)
	{
		//First we start at the root
		node* temp = root;

		//Then we go through the code one item at a time
		for (int i = 0; i < code.size(); i++)
		{
			//If it's a . we go left
			if (code[i] == '.')
			{
				//We'll have to create the left node first if it does not exists
				if (temp->left == NULL)
				{
					temp->left = new node;
				}
				temp = temp->left;
			}
			//If it's _ we go right
			else if (code[i] == '_')
			{
				//Have to create right node first if it does not exists
				if (temp->right == NULL)
				{
					temp->right = new node;
				}
				temp = temp->right;
			}
		}

		temp->data = letter;
	};
	node *root;
};