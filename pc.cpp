#include "pc.hpp"
#include "env.hpp"
using namespace Env;

namespace MIPS {
void PC::onClock()
{
	m_pc += 4;
	int tmp = 4*in[immData];
	
	// Add your code here
	if(in[clock_in] == 1)
	{
		if(in[jump] == 1)
		{
			m_pc = (m_pc & 0xf0000000) + tmp;
		}
		else if(in[branch] == 1 && in[zero] == 1)
		{
		    m_pc += tmp;
		}
		//printf("m_pc = %d(pc.cpp)\n",m_pc);
		setOutput(newPC, m_pc);
	}
}
}
