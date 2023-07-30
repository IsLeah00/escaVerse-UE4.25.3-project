
#include "BaseLvl.h"
#include "Components/BoxComponent.h"


ABaseLvl::ABaseLvl()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseLvl::BeginPlay()
{
	Super::BeginPlay();

	if (Trigger != nullptr)
		Trigger->bHiddenInGame = true;
	
}

void ABaseLvl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* ABaseLvl::GetTrigger()
{
	return Trigger;
}

UBoxComponent* ABaseLvl::GetSpawnLocation()
{
	return SpawnLocation;
}