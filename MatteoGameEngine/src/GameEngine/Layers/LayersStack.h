#pragma once
#include "GenginePCH.h"
#include "GameEngine/Layers/Layer.h"
#include "GameEngine/Core.h"

namespace MGEngine
{
	class MATTEO_GENGINE_API LayersStack
	{

	public:

		LayersStack();
		virtual ~LayersStack();

		void PushLayer(Layer* InLayer);
		//N.B. overlays are pushed to the very top, layers are always below them.
		void PushOverlay(Layer* InOverlay);
		void PopLayer(Layer* InLayer);
		void PopOverlay(Layer* InOverlay);

		std::vector<Layer*>::iterator begin();	
		std::vector<Layer*>::iterator end();

	private:

		std::vector<Layer*> Layers;
		std::vector<Layer*>::iterator LayersIt;
	};
}
