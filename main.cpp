#include "ExpressionConversion.h"
#include <string>
#include <iostream>

// TODO 1: get it working with numbers
// TODO 2: evaluate postfix
// TODO 3: evaluate prefix

// This is the main function that is used to showcase the expression conversion class.
// This function is mainly user input, then using expression conversion on the user input.
int main()
{
        char userChar = 0;
        do
        {
                std::string expression;
                std::string userAnswer;
                while (expression.empty())
                {
                        std::cout << "\nPlease enter an expression: ";
                        std::getline(std::cin, expression);
                }
                std::cout << "Infix: " << expression;
                while (userAnswer != "postfix" && userAnswer != "prefix")
                {
                        std::cout << "\n\nWould you like to convert the infix to postfix or prefix notation?";
                        std::cout << "\nEnter (postfix/prefix): ";
                        std::cin >> userAnswer;
                }
                std::string convertedNotation;
                if (userAnswer == "postfix")
                {
                        convertedNotation = ExpressionConversion::infixToPostfix(expression);
                        std::cout << "Postfix: " << convertedNotation;
                }
                else
                {
                        convertedNotation = ExpressionConversion::infixToPrefix(expression);
                        std::cout << "Prefix: " << convertedNotation;
                }
                userChar = 0;
                while (userChar != 'y' && userChar != 'n')
                {
                        std::cout << "\n\nWould you like to evaluate the " << userAnswer << " expression?";
                        std::cout << "\nEnter (y/n): ";
                        std::cin >> userChar;
                }
                if (userAnswer == "postfix")
                {
                        float answer = ExpressionConversion::evaluatePostfixExpresion(convertedNotation);
                        std::cout << "\nEvaluation from postfix: " << answer;
                }
                else
                {
                        float answer = ExpressionConversion::evaluatePrefixExpression(convertedNotation);
                        std::cout << "\nEvaluation from prefix: " << answer;
                }
                userChar = 0;
                while (userChar != 'y' && userChar != 'n')
                {
                        std::cout << "\n\nWould you like to try another expression? (if not, exit program)";
                        std::cout << "\nEnter (y/n): ";
                        std::cin >> userChar;
                }
        } while (userChar == 'y');

        return 0;
}


// this version of main was used in the testing of the expression conversion class
/*int main()
{
        std::string test = "1.1+2.2*2/7.993+(8.01-1.2*10^2.999)";
        std::string postfix = ExpressionConversion::infixToPostfix(test);
        float postEval = ExpressionConversion::evaluatePostfixExpresion(postfix);
        std::string prefix = ExpressionConversion::infixToPrefix(test);
        float preEval = ExpressionConversion::evaluatePrefixExpression(prefix);

        std::cout << "TESTING\n";
        std::cout << "infix: " << test << std::endl;
        std::cout << "prefix: " << prefix << std::endl;
        std::cout << "postfix: " << postfix << std::endl;
        std::cout << "evaluation from postfix: " << postEval << std::endl;
        std::cout << "evaluation from prefix: " << preEval << std::endl;

        return 0;
}*/