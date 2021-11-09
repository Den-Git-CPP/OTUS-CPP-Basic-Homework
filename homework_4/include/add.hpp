#pragma once

#include <string>
#include "astnode.hpp"

class Add :public ASTNode
{
public:
	Add() = delete;
	Add(std::string& Add_root) = delete;
	Add(ASTNode *lhs, ASTNode *rhs) :ASTNode("+", lhs, rhs) {
		//std::cout << "Constructor class Add" << std::endl;
	};
	Add(const Add& other);
	Add& operator=(const Add& other);
	~Add() override;

};

