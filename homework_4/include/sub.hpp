#pragma once

#include <string>
#include "astnode.hpp"

class Sub :public ASTNode{
public:
	Sub() = delete;
	Sub(std::string& Sub_root) = delete;
	Sub(ASTNode* lhs, ASTNode* rhs) :ASTNode("-", lhs, rhs){};
	Sub(const Sub& other)=delete;
	Sub& operator=(const Sub& other)=delete;
	~Sub() override;
};