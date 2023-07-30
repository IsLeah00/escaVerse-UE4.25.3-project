
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LvlSpawner.generated.h"

class ABaseLvl;

UCLASS()
class ESCAVERSE_API ALvlSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ALvlSpawner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION()
		void SpawnLevel(bool IsFirst);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	APawn* Player;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLvl> Lvl1;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLvl> Lvl2;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLvl> Lvl3;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLvl> Lvl4;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLvl> Lvl5;

	TArray<ABaseLvl*> LevelList;

public:

	int RandomLevel;

	FVector SpawnLocation = FVector();
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();

};
