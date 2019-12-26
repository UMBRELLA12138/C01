#pragma once

#include <cstdint>
#include <utility>
#include <string>
#include <iostream>
#include <cstring>

namespace miniplc0 {

	enum Operation {
		ILL,
		LIT,
		LOD,
		STO,
		ADD,
		SUB,
		DIV,
		MUL,
		WRT,
		bipush,
		ipush,
		pop,
		loadc,
		loada,
		iload,
		aload,
		iaload,
		istore,
		iastore,
		iadd,
		isub,
		imul,
		idiv,
		ineg,
		icmp,
		jmp,
		je,
		jne,
		jl,
		jle,
		jg,
		jge,
		call,
		ret,
		iret,
		iprint,
		cprint,
		printl,
		iscan,
		nop
	};
	
	class Instruction final {
	public:
		Instruction(Operation opr) :_opr(opr) {};
		Instruction(Operation opr, int32_t x) : _opr(opr), _x(x), _y(-1) {};
		Instruction(Operation opr, int32_t x, int32_t y) : _opr(opr), _x(x), _y(y) {};

		Operation GetOperation() const { return _opr; }
		int32_t GetX()  { return _x; }
		int32_t GetY() {
			return _y; 
		}
		void SetX(int32_t value) {
			_x = value;
		}
	private:
		Operation _opr;
		int32_t _x;
		int32_t _y;
	};
}