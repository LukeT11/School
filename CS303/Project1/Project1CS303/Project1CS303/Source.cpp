//Luke Talcott
//CS303 Project1
//#5 Infix-Postfix Algorithm

using namespace std;
#include<string>
#include "In-Postfix.h"
#include<iostream>

//Type an expression into the variable 'equation' and it calls In-Postfix to evaluate the expression; it returns the solution and postfix string.
int main()
{
	string equation = "5*(2+3*4)+6";
	InPostfix expression;
	int soln = expression.eval(equation);

	system("pause");
	return 0;
}