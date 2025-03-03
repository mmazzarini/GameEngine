#include "GenginePCH.h"

#include "GameEngine/Layers/LayersStack.h"

namespace MGEngine
{
	LayersStack::LayersStack()
	{
		LayersIt = Layers.begin();
	}

	LayersStack::~LayersStack()
	{
		for (Layer* layer : Layers)
		{
			delete layer;
		}
	}

	void LayersStack::PushLayer(Layer* InLayer)
	{
		LayersIt = Layers.emplace(LayersIt, InLayer);
		InLayer->OnAttach();
	}

	void LayersStack::PushOverlay(Layer* InOverlay)
	{
		Layers.emplace_back(InOverlay);
		InOverlay->OnAttach();
	}

	void LayersStack::PopLayer(Layer* InLayer)
	{
		auto LIt = std::find(Layers.begin(), Layers.end(), InLayer);
		if (LIt != Layers.end())
		{
			Layers.erase(LayersIt);
			LayersIt--;
		}
	}
	
	void LayersStack::PopOverlay(Layer* InOverlay)
	{
		auto Oit = std::find(Layers.begin(), Layers.end(), InOverlay);
		if (Oit != Layers.end())
		{
			Layers.erase(Oit);
		}
	}

	std::vector<Layer*>::iterator LayersStack::begin()
	{
		return Layers.begin();
	}
	
	std::vector<Layer*>::iterator LayersStack::end()
	{
		return Layers.end();
	}
}
