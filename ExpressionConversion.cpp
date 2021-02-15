//
// Created by steven on 29/12/2020.
//

#include "ExpressionConversion.h"
#include <cmath>
#include <iostream>

// Returns if possible a numerical answer to the postfix notation.
// If there are algebra letters in the expression the expression
// The user is prompted for the value of each letter
// Algorithm:
//      If the character is an operand, push it to the stack.
//      If the character is an operator, pop from the stack twice and evaluate the expression.
//      Repeat until each character in the expression has been checked.
float ExpressionConversion::evaluatePostfixExpresion(const std::string &expresion)
{
        auto* stack = new Stack<float>();
        std::string temp;
        for (char character : expresion)
        {
                if (character == ' ')
                {
                        if (!temp.empty())
                        {
                                stack->push(std::stof(temp));
                                temp.clear();
                        }
                }
                else
                {
                        if (std::isalpha(character))
                        {
                                stack->push(requestAlgebraValue(character));
                        }
                        else if (isOperand(character))
                        {
                                temp += character;
                        }
                        else
                        {
                                float valueOne = stack->pop();
                                float valueTwo = stack->pop();
                                switch (character)
                                {
                                        case '+':
                                                stack->push(valueTwo + valueOne);
                                                break;
                                        case '-':
                                                stack->push(valueTwo - valueOne);
                                                break;
                                        case '*':
                                                stack->push(valueTwo * valueOne);
                                                break;
                                        case '/':
                                                stack->push(valueTwo / valueOne);
                                                break;
                                        case '^':
                                                stack->push(std::pow(valueTwo, valueOne));
                                                break;
                                        default:
                                                break;
                                }
                        }
                }
        }
        return stack->pop();
}


// Returns an integer value representing the precedence of the operator
// in relation to BODMAS.
int ExpressionConversion::precedence(const char& x)
{
        switch (x)
        {
                default:
                        return -1;
                case '+':
                case '-':
                        return 1;
                case '*':
                case '/':
                        return 2;
                case '^':
                        return 3;
        }
}

// Returns true if the character is an operand, false if not.
bool ExpressionConversion::isOperand(const char& x)
{
        if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x == '.' || std::isdigit(x))
                return true;
        return false;
}

// Returns a reversed version of the string parameter sent to
// the function. All brackets will be reversed eg:
// '(' becomes ')'.
std::string ExpressionConversion::reverse(const std::string& inputString)
{
        // Initialize the ADT stack object.
        auto* stack = new Stack<char>(inputString.length());

        // Append each letter of the input string
        // into the ADT stack.
        // Reversing the brackets.
        //for (auto letter : inputString)
        for (char i : inputString)
        {
                if      (i == '(') stack->push(')');
                else if (i == ')') stack->push('(');
                else stack->push(i);
        }

        // Pop every letter from the stack
        // creating a reversed string.
        std::string outputString;
        for (int i = 0; i < inputString.length(); ++i)
                if (!stack->isEmpty())
                        outputString += stack->pop();

        // Clean up
        delete(stack);

        // Return the reversed string.
        return outputString;
}

std::string ExpressionConversion::infixToPostfix(const std::string& expression)
{
        // Create a stack with a capacity of the length of the expression,
        int expressionLength = expression.length();
        auto* stack = new Stack<char>(expressionLength);

        // Create the string used to store the output,
        // later will be outputted to called.
        std::string postfix;
        for (int i = 0; i < expression.length(); ++i)
        {
                if (expression[i] != ' ')
                {
                        // If the character is an operand,
                        // Loop through the expression and calculate the length of it.
                        // eg. 2.045 or 143 -> string.
                        // Then add it to the output string.
                        if (isOperand(expression[i]))
                        {
                                std::string temp;
                                do
                                {
                                        temp += expression[i];
                                        ++i;
                                } while (isOperand(expression[i]));
                                --i;
                                temp += ' ';
                                postfix += temp;
                        }

                        // If the character is an open bracket,
                        // push it to the stack
                        else if (expression[i] == '(')
                                stack->push(expression[i]);

                        // If the character is a close bracket,
                        // pop from the stack to the output
                        // string until the open bracket is found.
                        else if (expression[i] == ')')
                        {
                                while (!stack->isEmpty() && stack->peek() != '(')
                                {
                                        postfix += stack->pop();
                                        postfix += ' ';
                                }
                                if (!stack->isEmpty() && stack->peek() == '(')
                                        stack->pop();
                        }

                        // If character is an operator,
                        // check its precedence against the top
                        // if lower, pop from the stack to the postfix
                        // lastly push the character to the stack.
                        else
                        {
                                while (!stack->isEmpty() && precedence(expression[i]) <= precedence(stack->peek()))
                                {
                                        postfix += stack->pop();
                                        postfix += ' ';
                                }
                                stack->push(expression[i]);
                        }
                }
        }

        // Pop from stack to postfix
        while (!stack->isEmpty())
        {
                postfix += stack->pop();
                postfix += ' ';
        }

        // Clean up
        delete(stack);

        // Return the postfix to caller
        return postfix;
}

std::string ExpressionConversion::infixToPostfix(const std::string& expression, bool prefix)
{
        // Create a stack with a capacity of the length of the expression,
        int expressionLength = expression.length();
        auto* stack = new Stack<char>(expressionLength);

        // Create the string used to store the output,
        // later will be outputted to called.
        std::string postfix;
        for (int i = 0; i < expression.length(); ++i)
        {
                if (expression[i] != ' ')
                {
                        // If the character is an operand,
                        // Loop through the expression and calculate the length of it.
                        // eg. 2.045 or 143 -> string.
                        // Then add it to the output string.
                        if (isOperand(expression[i]))
                        {
                                std::string temp;
                                do
                                {
                                        temp += expression[i];
                                        ++i;
                                } while (isOperand(expression[i]));
                                --i;
                                temp += ' ';
                                postfix += temp;
                        }

                                // If the character is an open bracket,
                                // push it to the stack
                        else if (expression[i] == '(')
                                stack->push(expression[i]);

                                // If the character is a close bracket,
                                // pop from the stack to the output
                                // string until the open bracket is found.
                        else if (expression[i] == ')')
                        {
                                while (!stack->isEmpty() && stack->peek() != '(')
                                {
                                        postfix += stack->pop();
                                        postfix += ' ';
                                }
                                if (!stack->isEmpty() && stack->peek() == '(')
                                        stack->pop();
                        }

                                // If character is an operator,
                                // check its precedence against the top
                                // if lower, pop from the stack to the postfix
                                // lastly push the character to the stack.
                        else
                        {
                                while (!stack->isEmpty() && precedence(expression[i]) < precedence(stack->peek()))
                                {
                                        postfix += stack->pop();
                                        postfix += ' ';
                                }
                                stack->push(expression[i]);
                        }
                }
        }

        // Pop from stack to postfix
        while (!stack->isEmpty())
        {
                postfix += stack->pop();
                postfix += ' ';
        }

        // Clean up
        delete(stack);

        // Return the postfix to caller
        return postfix;
}

// Converts an infix expression to prefix.
std::string ExpressionConversion::infixToPrefix(const std::string& expression)
{
        // Reverse the infix expression
        // Calculate the postfix version of the reversed infix expression
        // Reverse the postfix, creating the result.
        // Prefix of the original infix expression.
        return reverse(infixToPostfix(reverse(expression), true));
}

// helper method for evaluating posfix expression.
// requests the value of an algebra character from the user.
// returns the float value to caller.
float ExpressionConversion::requestAlgebraValue(const char &x)
{
        std::string userResponce;
        bool flag;
        do
        {
                flag = true;
                std::cout << "\nEnter a value for " << x << ": ";
                std::cin >> userResponce;
                for (char c : userResponce)
                {
                        if (!std::isdigit(c) && c != '.')
                        {
                                flag = false;
                                break;
                        }
                }
        } while (userResponce.empty() || !flag);
        return std::stof(userResponce);
}

// Returns if possible a numerical answer to the postfix notation.
// If there are algebra letters in the expression the expression
// The user is prompted for the value of each letter
// Algorithm:
//      If the character is an operand, push it to the stack.
//      If the character is an operator, pop from the stack twice and evaluate the expression.
//      Repeat until each character in the expression has been checked.
float ExpressionConversion::evaluatePrefixExpression(const std::string &expression)
{
        auto* stack = new Stack<float>();
        std::string temp;
        for (int i = (int)expression.length()-1; i >= 0; --i)
        {
                if (expression[i] == ' ')
                {
                        if (!temp.empty())
                        {
                                temp = reverse(temp);
                                stack->push(std::stof(temp));
                                temp.clear();
                        }
                }
                else
                {
                        if (std::isalpha(expression[i]))
                        {
                                stack->push(requestAlgebraValue(expression[i]));
                        }
                        else if (isOperand(expression[i]))
                        {
                                temp += expression[i];
                        }
                        else
                        {
                                float valueOne = stack->pop();
                                float valueTwo = stack->pop();
                                switch (expression[i])
                                {
                                        case '+':
                                                stack->push(valueOne + valueTwo);
                                                break;
                                        case '-':
                                                stack->push(valueOne - valueTwo);
                                                break;
                                        case '*':
                                                stack->push(valueOne * valueTwo);
                                                break;
                                        case '/':
                                                stack->push(valueOne / valueTwo);
                                                break;
                                        case '^':
                                                stack->push(std::pow(valueOne, valueTwo));
                                                break;
                                        default:
                                                break;
                                }
                        }
                }
        }
        return stack->pop();
}
