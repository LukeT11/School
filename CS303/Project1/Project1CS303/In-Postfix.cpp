#include "In-Postfix.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;

///Function obtains what to evaluate, organizes it into stacks as it goes while keeping the expression in a postfix operation, returns solution and postfix string.
int InPostfix::eval(string exp)
{
	int openedPar = 0; //Variable keeps track to make sure there is proper opened/closed parentheses all the way through.
	string check = "";
	int i = 0;
	numExp = 0;
	for (numExp = 0; numExp < exp.size(); numExp++) //Runs through entire expression string in order.
	{
		char op = exp[numExp];
		currOperator = "";
		currPrec = 0;

		//Acknowledges and ignores spaces.
		if (op == ' ')
		{
			continue;
		}

		//Checks char opens parenthesis
		else if (op == '(')
		{
			//Adds it to operator stack, keeps track of number parenthesis that are open.
			currOperator += op;
			operators.push(currOperator);
			precedence.push(0);
			currOperator = "";
			openedPar += 1;
		}
		//Checks char of closing a parentheses.
		else if (op == ')')
		{
				//Runs through, pops off and evaluates the operators off the stack until it reaches the opening of the parentheses and then stops.
				do
				{
					//If operator stack empty, then you can't be closing parentheses.
					if (operators.empty())
					{
						error(2, numExp);
						return -2;
					}

					//If the next operator in the stack immediatly opens correspondingly, no need to evaluate inside it.
					else if (operators.top() == "(")
					{
						break;
					}


					//Evaluates whats inside the parentheses properly.
					else
					{
						currOperator = operators.top();
						math();

						if (operators.empty())
						{
							error(2, numExp);
							return -2;
						}
						else
						{
							check = operators.top();
						}
					}
					//Stops evaluating inside parenthesis once open parenthses is met.
				} while (check != "(");
			operators.pop();
			precedence.pop();
			currOperator = "";
			openedPar -= 1;
		}

		//Checks if the char is a digit. If so, check how long/number of char the number is through the expression string and pushes it to the operand stack.
		else if (isdigit(op))
		{
			string num = "";
			num += op;
			int i = 1;
			while (isdigit(exp[numExp + i]) && (numExp + i) < exp.size())
			{
				num += exp[numExp + i];
				numExp++;

			}

			Postfix += (" " + num);
			int x = 0;
			x = stoi(num);
			operands.push(x);
		}

		//char is either a match with a valid operator or not a valid char in the expression at all.
		else
		{
			//Checks if the char is addition or an increment.
			if (op == '+')
			{
				if (exp[numExp + 1] == '+')
				{
					numExp++;
					currOperator = "++";
					currPrec = 9;
				}

				else
				{
					currOperator = "+";
					currPrec = 6;
				}
			}
			//Checks if the char is a subtraction, negative sign to another number, or and decrement.
			else if (op == '-')
			{
				if (exp[numExp + 1] == '-')
				{
					numExp++;
					currOperator = "--";
					currPrec = 9;
				}

				//If negative to another number, matches is with it and the size, adds it the operand stack.
				else if (operands.empty() || exp[numExp - 1] == '>' || exp[numExp - 1] == '<' || exp[numExp - 1] == '=' || exp[numExp - 1] == '*' || exp[numExp - 1] == '/' || exp[numExp - 1] == '%' || exp[numExp - 1] == '!' || exp[numExp - 1] == '&' || exp[numExp - 1] == '^' || exp[numExp - 1] == '|' || exp[numExp - 1] == '+' || exp[numExp - 1] == '-')
				{
					string num = ("-");
					int i = 1;
					while (isdigit(exp[numExp + i]) && numExp + i < exp.size())
					{
						num += (exp[numExp + i]);
						numExp++;

					}

					Postfix += (" " + num);
					int x = 0;
					x = stoi(num);
					operands.push(x);
				}

				else
				{
					currOperator = "-";
					currPrec = 6;
				}
			}

			//Checks if char is multiplication.
			else if (op == '*')
			{
				currOperator = "*";
				currPrec = 7;
			}
			//Checks if char is division.
			else if (op == '/')
			{
				currOperator = "/";
				currPrec = 7;
			}
			//Checks if char is module.
			else if (op == '%')
			{
				currOperator = "%";
				currPrec = 7;
			}
			//Checks if char is not or not equal to.
			else if (op == '!')
			{
				if (exp[numExp + 1] == '=')
				{
					numExp++;
					currOperator = "!=";
					currPrec = 4;
				}

				else
				{
					currOperator = "!";
					currPrec = 8;
				}
			}
			//Checks if char is greater than or greater than/equal to.
			else if (op == '>')
			{
				if (exp[numExp + 1] == '=')
				{
					numExp++;
					currOperator = ">=";
					currPrec = 5;
				}

				else
				{
					currOperator = ">";
					currPrec = 5;
				}
			}
			//Checks if char is less than or less than/equal to.
			else if (op == '<')
			{
				if (exp[numExp + 1] == '=')
				{
					numExp++;
					currOperator = "<=";
					currPrec = 5;
				}

				else
				{
					currOperator = "<";
					currPrec = 5;
				}
			}
			//Checks if char is the power of.
			else if (op == '^')
			{
				currOperator = "^";
				currPrec = 8;
			}
			//Checks if char is and.
			else if (op == '&')
			{
				if (exp[numExp + 1] == '&')
				{
					numExp++;
					currOperator = "&&";
					currPrec = 2;
				}
			}
			//Checks if char is or.
			else if (op == '|')
			{
				if (exp[numExp + 1] == '|')
				{
					numExp++;
					currOperator = "||";
					currPrec = 1;
				}
			}
			//Checks if char is equal to.
			else if (op == '=')
			{
				if (exp[numExp + 1] == '=')
				{
					numExp++;
					currOperator = "==";
					currPrec = 4;
				}
			}
			//Anything else is not a valid char.
			else
			{
			error(1, numExp);
			return -1;
			}
		}

		//If not an operator, runs to next char in the expression string. Else, compares the current operator to the previous to determine what to do with it.
		if (currOperator == "")
		{
			continue;
		}
		//Compares current operator to the stack of operators.
		else
		{
			compareOP();
		}

	}
	
	//Once the end of the expression string is reached, runs through remaing operators and operands in the stacks and it evaluates them. Unless there is an error.
	for (numExp = operators.size(); numExp > 0; numExp--)
	{
		if (tossError == 0)
		{
			currOperator = operators.top();
			math();
		}
		else
		{
			break;
		}
	}
	//If still open or closed parenthesis in the operator stack, not valid expression to evaluate.
	if (openedPar != 0) 
	{
		error(2, numExp);
		return -2;
	}
	//Throws error.
	else if (tossError == -3)
	{
		return -3;
	}
	//Throws error.
	else if (tossError == -5)
	{
		return -5;
	}
	//If more numbers and no more operators, not valid expression to evaluate.
	else if (operands.size() > 1)
	{
		error(4, numExp);
		return -4;
	}
	//Outputs the solution to the expression and the postfix order.
	else
	{
		cout << "Solution: " << operands.top() << " Postfix:" << Postfix << endl;
		return operands.top();
	}
}

//Function evaluates an operator when called. Pushes the remaining solution number onto the top of operand stack, removes operator/Precedence off the stack.
void InPostfix::math()
{
	//cout << operands.top() << endl;
	//cout << operators.top() << endl;
	int number = operands.top();
	operands.pop();
	//cout << operands.top() << endl;
	//If there is at least one more number on the stack, it can use these operators and evaluate.
	if (operands.size() != 0)
	{
		if (currOperator == "*")
		{
			number = (operands.top() * number);
			operands.pop();
		}

		else if (currOperator == "/")
		{
			if (number == 0)
			{
				error(5, numExp);
			}

			else
			{
				number = (operands.top() / number);
				operands.pop();
			}
		}

		else if (currOperator == "+")
		{
			number = (operands.top() + number);
			operands.pop();
		}

		else if (currOperator == "-")
		{
			number = (operands.top() - number);
			operands.pop();
		}

		else if (currOperator == "%")
		{
			number = (operands.top() % number);
			operands.pop();
		}

		else if (currOperator == "^")
		{
			number = pow(operands.top(), number);
			operands.pop();
		}

		else if (currOperator == "++")
		{
			number++;
		}

		else if (currOperator == "--")
		{
			number--;
		}

		else if (currOperator == "!")
		{
			number = !number;
		}

		else if (currOperator == "!=")
		{
			number = (operands.top() != number);
			operands.pop();
		}

		else if (currOperator == "<")
		{
			number = (operands.top() < number);
			operands.pop();
		}

		else if (currOperator == ">")
		{
			number = (operands.top() > number);
			operands.pop();
		}

		else if (currOperator == "<=")
		{
			number = (operands.top() <= number);
			operands.pop();
		}

		else if (currOperator == ">=")
		{
			number = (operands.top() >= number);
			operands.pop();
		}

		else if (currOperator == "==")
		{
			number = (operands.top() == number);
			operands.pop();
		}

		else if (currOperator == "&&")
		{
			number = (operands.top() && number);
			operands.pop();
		}

		else if (currOperator == "||")
		{
			number = (operands.top() || number);
			operands.pop();
		}
	}

	//If numbers left on the stack are zero, then it can only use these operators and evaluate.
	else
	{
		if (currOperator == "++")
		{
			number++;
		}

		else if (currOperator == "--")
		{
			number--;
		}

		else if (currOperator == "!")
		{
			number = !number;
		}
		//Any operands left, not these above, with no numbers cannot be used, therefore to many operators or too litle numbers.
		else
		{
			error(3, numExp);
		}

	}
	Postfix += (" " + currOperator);
	operands.push(number);
	operators.pop();
	precedence.pop();
}

//Function compares current operator with previous operator to determine whether it needs to push or use an operator.
void InPostfix::compareOP()
{
	//Operators stack empty, automatically pushes the operator onto the stack.
	if (operators.empty())
	{
		operators.push(currOperator);
		precedence.push(currPrec);
	}
	//If precedence of current operator is less or equal to the one on the stack, use the one on the stack, and then compare the current one again to the next one on top of the stack.
	else if (currPrec <= precedence.top())
	{
		string pivotOperator = currOperator;
		int pivotPrec = currPrec;
		currOperator = operators.top();
		currPrec = precedence.top();
		math();
		currOperator = pivotOperator;
		currPrec = pivotPrec;
		compareOP();
	}
	//If current operator has a greater precedence than the one on top of the stack, then push it onto the stack.
	else
	{
	operators.push(currOperator);
	precedence.push(currPrec);
	}
}
//Function displays error when called.
void InPostfix::error(int error, int element)
{
	switch (error)
	{
	//Error invalid char.
	case 1: cout << "Error. Invalid operator or number at element " << element << " in the expression." << endl;
			break;
	//Error with parentheses.
	case 2: cout << "Error. Parenthesis in the expression aren't used correctly." << endl;
			break;
	//Error too many operators/numbers.
	case 3: cout << "Error. Too many operators or not enough numbers." << endl;
			tossError = -3;
			break;
	//Error too little operators/numbers
	case 4: cout << "Error. Too little operators or too many numbers." << endl;
			break;
	//Error cannot divide by 0.
	case 5: cout << "Error. Cannot divide number by 0." << endl;
			tossError = -5;
			break;
	}
}