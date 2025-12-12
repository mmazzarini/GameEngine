#include "GenginePCH.h"

#include "GameEngine/Layers/LayersStack.h"

namespace MGEngine
{
	LayersStack::LayersStack()
	{
		LayerInsertIndex = 0;
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
		Layers.emplace(Layers.begin() + LayerInsertIndex, InLayer);
		LayerInsertIndex++;
	}

	void LayersStack::PushOverlay(Layer* InOverlay)
	{
		Layers.emplace_back(InOverlay);
	}

	void LayersStack::PopLayer(Layer* InLayer)
	{
		auto LIt = std::find(Layers.begin(), Layers.end(), InLayer);
		if (LIt != Layers.end())
		{
			InLayer->OnDetach();
			Layers.erase(LIt);
			LayerInsertIndex--;
		}
	}
	
	void LayersStack::PopOverlay(Layer* InOverlay)
	{
		auto Oit = std::find(Layers.begin(), Layers.end(), InOverlay);
		if (Oit != Layers.end())
		{
			InOverlay->OnDetach();
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
