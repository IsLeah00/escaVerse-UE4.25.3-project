
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NegativePlatforms.generated.h"

UCLASS()
class ESCAVERSE_API ANegativePlatforms : public AActor
{
	GENERATED_BODY()
	
public:	
	ANegativePlatforms();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
