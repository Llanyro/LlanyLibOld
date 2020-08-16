#include "SubscriptorSingletons.hpp"

#include "GestorSingletons.hpp"

LlanyLib::Basic::Gestores::SubscriptorSingletons::SubscriptorSingletons(){}
LlanyLib::Basic::Gestores::SubscriptorSingletons::~SubscriptorSingletons(){}
void LlanyLib::Basic::Gestores::SubscriptorSingletons::subscribir(void (*singFree)(void))
{
	GESTOR_SINGLETONS->subscribirse(singFree);
}
