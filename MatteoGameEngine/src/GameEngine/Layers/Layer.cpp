#include "GenginePCH.h"

#include "GameEngine/Layers/Layer.h"

namespace MGEngine
{
	Layer::Layer(const std::string& InName)
		:DebugName(InName)
	{
	}

	Layer::~Layer()
	{
	}

	inline const std::string& Layer::GetName()
	{
		return DebugName;
	}
}