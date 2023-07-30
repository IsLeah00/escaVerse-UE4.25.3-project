

#pragma once

#include "CoreMinimal.h"
#include "NegativePlatforms.h"
#include "EndWall.generated.h"

/**
 * 
 */
UCLASS()
class ESCAVERSE_API AEndWall : public ANegativePlatforms
{
	GENERATED_BODY()

public:

	AEndWall();

protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	
};
