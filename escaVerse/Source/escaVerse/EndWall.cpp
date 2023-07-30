


#include "EndWall.h"

AEndWall::AEndWall()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndWall::BeginPlay()
{
	Super::BeginPlay();

	this->GetRootComponent()->ComponentVelocity = FVector(0, 25, 0);

}

void AEndWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(0, 350 * DeltaTime, 0), true);
}