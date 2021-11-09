#pragma once
#include <string>
#include "astnode.hpp"

class Sub :public ASTNode
{
public:
	Sub() = delete;
	Sub(std::string& Sub_root) = delete;
	Sub(ASTNode* lhs, ASTNode* rhs) :ASTNode("/", lhs, rhs) {
		//std::cout << "Constructor class Sub" << std::endl;
	};

	Sub(const Sub& other)=delete;
	Sub& operator=(const Sub& other)=delete;
	~Sub() override;

};