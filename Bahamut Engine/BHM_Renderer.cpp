#include "BHM_Renderer.hpp"

BHM_Renderer::BHM_Renderer(){
	rendererSet = nullptr;
	components = make_shared<list<shared_ptr<BHM_Component>>>();
	initializingComponents = make_shared<list<weak_ptr<BHM_Component_Queue_Bond>>>();
	loopingComponents = make_shared<list<weak_ptr<BHM_Component_Queue_Bond>>>();

	int layerQuantity = BHM_Config::LAYERS;

	sprites = new shared_ptr<list<weak_ptr<BHM_Component_Queue_Bond>>>[layerQuantity]; 

	for (int i = 0; i < layerQuantity; i++){
		sprites[i] = make_shared<list<weak_ptr<BHM_Component_Queue_Bond>>>();
	}
}

void BHM_Renderer::BHM_Initialize(){

}

void BHM_Renderer::BHM_Loop(){

}

bool BHM_Renderer::BHM_AddComponent(shared_ptr<BHM_Component> component){
	if(component->BHM_SetRenderer(this)){
		components->push_back(component);
		cout << "Component added\n";
		return true;
	}

	return false;
}

bool BHM_Renderer::BHM_AddToQueue(shared_ptr<BHM_Component> component){
	BHM_Renderer* componentRenderer = component->BHM_GetRenderer();

	if(componentRenderer == nullptr){
		this->BHM_AddComponent(component);
		cout << "Setting renderer" << endl;
	} 
	else if (componentRenderer != this) return false;

	shared_ptr<BHM_Component_Queue_Bond> initializeBond = make_shared<BHM_Component_Queue_Bond>(component.get(), this, BHM_QueueType::INITIALIZE);
	initializingComponents->push_back(initializeBond);
	component->BHM_AddBond(initializeBond);
 
	return true;
}

bool BHM_Renderer::BHM_AddComponentToQueue(shared_ptr<BHM_Component> component){

	if(!this->BHM_AddToQueue(component)) return false;

	component->BHM_AddBondCommand(new BHM_Loop_Bond_Command());

	return true;
}

bool BHM_Renderer::BHM_AddFullSpriteToQueue(shared_ptr<BHM_Sprite> sprite, int layer){
	if(!this->BHM_AddToQueue(sprite)) return false;
	//BHM_Full_Sprite_Bond_Command* fsbc;
	sprite->BHM_AddBondCommand(new BHM_Full_Sprite_Bond_Command(layer));
	return true;
}


void BHM_Renderer::BHM_SetRendererSet(BHM_Renderer_Set* rendererSet){
	this->rendererSet = rendererSet;
}

void BHM_Renderer::BHM_InitializeComponents(){
	
	/*
	bhm_utils::while_each(initializingComponents, [this](auto & componentBond){
		BHM_Component* component = componentBond->lock()->BHM_GetComponent();
		component->BHM_DeleteBond(componentBond->lock());
		cout << "Ate aqui tudo bem 1\n";
		system("pause");
		
		//ADDING LOOP BOND
		//BHM_AddLoopBond(component);
		component->BHM_GetBondCommand()->BHM_Execute(component);
		cout << "Ate aqui tudo bem 2\n";
		system("pause");
		componentBond = this->initializingComponents->erase(componentBond);

		cout << "Ate aqui tudo bem 3\n";
		system("pause");
		component->BHM_StartInitialize();
		cout << "Ate aqui tudo bem 4\n";
		system("pause");
		componentBond--;
		cout << "Ate aqui tudo bem 5\n";
		system("pause");
	});*/

	auto componentBond = initializingComponents->begin();
	while (componentBond != initializingComponents->end()) {
		cout << "Estou aqui 1\n";
		system("pause");
		if (componentBond->lock() != NULL) {
			BHM_Component* component = componentBond->lock()->BHM_GetComponent();
			cout << "Estou aqui 2\n";
			system("pause");
			component->BHM_DeleteBond(componentBond->lock());
			cout << "Estou aqui 3\n";
			system("pause");
			component->BHM_GetBondCommand()->BHM_Execute(component);
			component->BHM_StartInitialize();
		}
		componentBond = this->initializingComponents->erase(componentBond);
	}
}

void BHM_Renderer::BHM_AddLoopBond(BHM_Component* component){
	shared_ptr<BHM_Component_Queue_Bond> componentQueueBond = make_shared<BHM_Component_Queue_Bond>(component, this, BHM_QueueType::LOOP);
	loopingComponents->push_back(componentQueueBond);
	component->BHM_AddBond(componentQueueBond);
}

void BHM_Renderer::BHM_AddSpriteBond(BHM_Sprite* sprite, int layer){
	shared_ptr<BHM_Component_Queue_Bond> componentQueueBond = make_shared<BHM_Component_Queue_Bond>(sprite, this, BHM_QueueType::SPRITE);
	auto spriteLayer = sprites[layer];
	spriteLayer->push_back(componentQueueBond);
	sprite->BHM_AddBond(componentQueueBond);
}

void BHM_Renderer::BHM_AddFullSpriteBond(BHM_Sprite* sprite, int layer){
	this->BHM_AddLoopBond(sprite);
	this->BHM_AddSpriteBond(sprite, layer);
}

void BHM_Renderer::BHM_LoopComponents(){
	
	bhm_utils::for_each(loopingComponents, [](auto & bond){
		bond->lock()->BHM_GetComponent()->BHM_StartLoop();
	});
}

void BHM_Renderer::BHM_RenderSprites(int layer){
	auto & spritesLayer = sprites[layer];

	int i = 0;
	bhm_utils::for_each(spritesLayer, [&i](auto & bond){
		cout << "Rendering" << "\n";
		//BHM_Config::standardGUI->BHM_Draw(dynamic_cast<BHM_Sprite*>(bond->lock()->BHM_GetComponent()));
	});
}