#pragma once
#include <string>
#include "astnode.hpp"

class Variable:public ASTNode{
public:
	Variable()=delete;
	Variable(std::string var) : ASTNode(var), var_(var){};
	Variable(const Variable& other)=delete;
	Variable& operator=(const Variable& other)=delete;
	~Variable() override;
private:
	std::string var_;
};

