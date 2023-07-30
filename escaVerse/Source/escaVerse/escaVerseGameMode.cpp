
#include "escaVerseGameMode.h"
#include "escaVerseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AescaVerseGameMode::AescaVerseGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
