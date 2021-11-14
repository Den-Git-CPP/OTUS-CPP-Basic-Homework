#pragma once

#include <string>
#include "astnode.hpp"

class Number : public ASTNode {
  public:
    Number() = delete;
    Number(int val) : ASTNode(std::to_string(val)),val_(val){};
    Number(const Number& other) = delete;
    Number& operator=(const Number& other) = delete;
    ~Number() override;
  	int value() const { return val_; }
  private:
    int val_;
};
