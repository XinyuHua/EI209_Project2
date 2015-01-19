#include "alucontrol.hpp"
#include "env.hpp"
using namespace Env;

namespace MIPS {
void ALUControl::onChange()
{
	//printf("function code = %d(alucontrol.cpp)\n",in[funct]);
	// Add your code here
	if(in[aluOp] == B("00")) //lw,sw
	{
		setOutput(aluCtr,B("0010")); //add
	}
	else if(in[aluOp] == B("01")) //branch
	{
		setOutput(aluCtr,B("0110")); //sub
	}
	else 
	{   
		int tmp = in[funct] & 0x0f;
		//int tmp = in[funct] - 10000*(in[funct]/10000); //grab lower 4-bit of funct
		printf("          lower 4 bit of function code = %d(in alucontrol.cpp)\n",tmp);
        if( tmp == B("0000") )
		{
			setOutput(aluCtr,B("0010")); //add
		}
		else if( tmp == B("0010") )
		{
			setOutput(aluCtr,6);//B("0110")); //sub
		}
		else if( tmp == B("0100") )
		{
			setOutput(aluCtr,B("0000")); //and
		}
		else if( tmp == B("0101") )
		{
			setOutput(aluCtr,B("0001")); //or
		}
		else if( tmp == B("1010") )
		{
			setOutput(aluCtr,B("0111")); //slt
		}
	}
}
}
