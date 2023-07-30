
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLvl.generated.h"

class UBoxComponent;

UCLASS()
class ESCAVERSE_API ABaseLvl : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseLvl();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
		UBoxComponent* Trigger;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
		UBoxComponent* SpawnLocation;

public:

	UBoxComponent* GetTrigger();
	UBoxComponent* GetSpawnLocation();

};
