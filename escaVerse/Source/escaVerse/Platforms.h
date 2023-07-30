
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platforms.generated.h"

UCLASS()
class ESCAVERSE_API APlatforms : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatforms();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
