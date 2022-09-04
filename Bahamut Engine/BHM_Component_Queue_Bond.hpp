#pragma once
#include "BHM_Common.hpp"
#include "BHM_QueueType.hpp"

class BHM_Renderer;
class BHM_Component;


class BHM_Component_Queue_Bond{
	private:
		BHM_Component* component;
		BHM_Renderer* renderer;
		BHM_QueueType queueType;

	public:
		BHM_Component_Queue_Bond(BHM_Component* component, BHM_Renderer* renderer, BHM_QueueType queueType);
		~BHM_Component_Queue_Bond();
		BHM_QueueType BHM_GetQueueType();
		BHM_Component* BHM_GetComponent();
};

