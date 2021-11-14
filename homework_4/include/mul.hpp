#pragma once

#include <string>
#include "astnode.hpp"

class Mul :public ASTNode{
public:
	Mul() = delete;
	Mul(std::string& mul_root)=delete;
	Mul(ASTNode* lhs, ASTNode* rhs)	:ASTNode("*", lhs, rhs){};
	Mul(const Mul& other)=delete;
	Mul& operator=(const Mul& other)=delete;
	~Mul()override;
};

