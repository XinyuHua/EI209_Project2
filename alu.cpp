#include "alu.hpp"
#include "env.hpp"
using namespace Env;

namespace MIPS {
void ALU::onChange()
{
	// Add your code here
	LineData rst = 0;
	switch(in[aluCtr])
	{
	case 0:
  	    rst = in[input1] & in[input2];
	    break;
	case 1:
		rst = in[input1] | in[input2];
		break;
	case 2:
		rst = in[input1] + in[input2];
		break;
	case 6:
		//printf("SUB!!!!!!!!!!!\n");
		rst = in[input1] - in[input2];
		break;
	case 7:
		if(in[input1] < in[input2])
			rst = 1;
		else 
			rst = 0;
		break;
	case 12:
		rst = ~(in[input1] | in[input2]);
		break;
	}
	if(rst == 0)
		setOutput(zero,1);

	setOutput(aluRes,rst);

	      	 
}
}
