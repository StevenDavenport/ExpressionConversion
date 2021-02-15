cmake_minimum_required(VERSION 3.17)
project(InfixPostfixPrefix)

set(CMAKE_CXX_STANDARD 14)

add_executable(InfixPostfixPrefix main.cpp ExpressionConversion.cpp ExpressionConversion.h Node.h Stack.h)