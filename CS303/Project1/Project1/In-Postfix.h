#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Class InPostfix evaluates and returns an expressions solution and Postfix string.
class InPostfix
{
public:
	//Function obtains what to evaluate, organizes it into stacks as it goes while keeping the expression in a postfix operation, returns solution and postfix string.
	int eval(string exp);

	//Function evaluates an operator when called.
	void math();

	//Function compares current operator with previous operator to determine whether it needs to push or use an operator.
	void compareOP();

	//Function displays error when called.
	void error(int error, int location);

private:
	//Variable integer that keeps track of where at in the order of the expression string.
	int numExp;

	//Variable integer for precedence of the current operator it is on or using.
	int currPrec;

	//Varibale integer used to toss an error value to call/pull error and stops the program.
	int tossError = 0;

	//Variable strigng of the current operator that is currently be looked at or used.
	string currOperator;

	//Variable string to keep track of the postfix order when using a number or operator.
	string Postfix = "";

	//Stack of precedence, element order in correspondance with the operator stack to know which operator to use first.
	stack<int> precedence;

	//Stack of the operators to use in order, element order in correspondance with precedence stack.
	stack<string> operators;

	//Stack of numbers to use when evalutating with an operator.
	stack<int> operands;
};
