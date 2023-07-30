

#include "LvlSpawner.h"
#include "BaseLvl.h"
#include "Engine.h"
#include "Components/BoxComponent.h"

ALvlSpawner::ALvlSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ALvlSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);
}

void ALvlSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALvlSpawner::SpawnLevel(bool IsFirst)
{
	SpawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	SpawnRotation = FRotator(0, 90, 0);

	if (!IsFirst)
	{
		ABaseLvl* LastLevel = LevelList.Last();
		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}

	RandomLevel = FMath::RandRange(1, 10);
	ABaseLvl* NewLevel = nullptr;

	if (RandomLevel == 1)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLvl>(Lvl1,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 2)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLvl>(Lvl2,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 3)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLvl>(Lvl3,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 4)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLvl>(Lvl4,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 5)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLvl>(Lvl5,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}


	if (NewLevel)
	{
		if (NewLevel->GetTrigger())
		{
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ALvlSpawner::OnOverlapBegin);
		}
	}

	LevelList.Add(NewLevel);
	if (LevelList.Num() > 5)
	{
		LevelList.RemoveAt(0);
	}
}

void ALvlSpawner::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SpawnLevel(false);
}

