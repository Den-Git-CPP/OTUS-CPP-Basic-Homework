#pragma once

#include <string>
#include "astnode.hpp"

class Div :public ASTNode{
public:
	Div() = delete;
	Div(std::string& Div_root) = delete;
	Div(ASTNode* lhs, ASTNode* rhs) :ASTNode("/", lhs, rhs){};
	Div(const Div& other)=delete;				
	Div& operator=(const Div& other)=delete;	
	~Div() override;								
};

