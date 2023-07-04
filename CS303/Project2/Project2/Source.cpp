#include"MorseCodeTree.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main()
{
	MorseTree tree;
	cout << tree.decode(".... . ._.. ._.. ___") << endl;
	cout << tree.encode("abcxyz");
	cin.ignore();
}