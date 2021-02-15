//
// Created by steven on 29/12/2020.
//

#include <string>
#include "Stack.h"
#include <cctype>

#ifndef INFIXPOSTFIXPREFIX_EXPRESSIONCONVERSION_H
#define INFIXPOSTFIXPREFIX_EXPRESSIONCONVERSION_H

// Expression conversion class does not need instantiation
// as methods are static.
// Expression conversation is an intermediary API that uses
// LinkedList class to convert expressions.
class ExpressionConversion
{
private:
        // These static private methods are helpers for the public
        // methods defined in this class.
        static int precedence(const char& x);
        static bool isOperand(const char& x);
        static std::string reverse(const std::string& inputString);
        static float requestAlgebraValue(const char& x);
        static std::string infixToPostfix(const std::string& expression, bool infix);

public:
        // Main methods used for converting infix notation to post/prefix.
        static std::string infixToPostfix(const std::string& expression);
        static std::string infixToPrefix(const std::string& expression);
        static float evaluatePostfixExpresion(const std::string& expresion);
        static float evaluatePrefixExpression(const std::string& expression);
};


#endif //INFIXPOSTFIXPREFIX_EXPRESSIONCONVERSION_H
