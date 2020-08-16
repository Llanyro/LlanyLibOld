#pragma once
#ifndef PROCESO_OBJECT_HPP_
#define PROCESO_OBJECT_HPP_

#include "../LibreriasSimples/LlanyTypes.h"

namespace LlanyLib
{
	namespace Objetos
	{
		class Proceso
		{
			protected:
				void* proceso;
				pid_t pid;
			public:
				Proceso();
				~Proceso();
		};
	}
}
#endif // !PROCESO_OBJECT_HPP_
