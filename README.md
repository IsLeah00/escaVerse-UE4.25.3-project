# escaVerse
escaVerse is a 3D side view, VR compatible, Endless Runner game built on Unreal Engine version 4.25.4 in C++ programming language.
     The goal of the game is for the player to continuously advance on an endlessly generated track, while the wall behind him approaches and closes off the previous part of the track. With the character, it is possible to move left and right, as well as jump to avoid the obstacles that appear. If the player collides with the wall behind him or an obstacle, he loses and the game starts over.
         VR headsets are supported within the game, so players can play in virtual reality.


## 1. Functional specification
• VR compatibility: The game supports VR headsets, allowing players to play in virtual reality.

• Dynamic background elements: The game includes lightning, rain and moving sky elements that enhance the atmosphere and visual experience of the game, especially in VR.

• 3D side view: The player sees the playing field from a side view, on which he must continuously move forward.

• Player movement: The player can move left and right and jump to avoid obstacles.

• Dynamically changing track: The track is dynamically generated using the LvlSpawner class. LvlSpawner builds the 'endless' level from 5 mini-levels that are randomly combined.


## 2. Class structure
### ARunnerCharacter
• Description: This class is responsible for the control and behavior of the player character.

• Inheritance: comes from ACharacter class.

• More important member variables:
     - UCameraComponent* SideViewCamera: Camera component representing the player's view.

     - float zPosition: Value indicating the height of the camera.

     - bool CanMove: Logical value indicating the movement of the player.

• More important member functions:
     - void MoveRight(float value): Moves the player sideways based on the "value" parameter.

     - void RestartLevel(): Restarts the game if the player dies.

     - void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult): Monitors and handles collisions in the game.

### APlatforms
• Description: The base platform class from which obstacles and background elements are derived.

• Inheritance: Derived from AActor class.

### ANegativePlatforms
• Description: Class representing obstacles and background elements.

• Inheritance: Derived from AActor class.

• Note: This class represents obstacles that the player must avoid.

### AEndWall
• Description: A wall class that "chases" the player, indicating the end of the game.

• Inheritance: Derived from ANegativePlatforms class.

### ABaseLvl
• Description: This class represents a basic track element from which the dynamically generated track is built.

• Inheritance: Derived from AActor class.

• More important member variables:
     - UBoxComponent* Trigger: The obstacle indicator trigger that detects player collisions.

     - UBoxComponent* SpawnLocation: Trigger indicating the spawn position of the next track element.

• More important member functions:
     - UBoxComponent* GetTrigger(): Returns the trigger indicating obstacles.

     - UBoxComponent* GetSpawnLocation(): Returns the trigger indicating the spawn position of the next track element.

### ALvlSpawner
• Description: This class is responsible for the dynamic generation of the track, it handles the track elements in the game.

• Inheritance: Derived from AActor class.

• More important member variables:
     - TSubclassOf<ABaseLvl> Lvl1, Lvl2, Lvl3, Lvl4, Lvl5: Blueprint references indicating the types of all track elements.

     - TArray<ABaseLvl*> LevelList: The array that stores the currently active level elements.

• More important member functions:
     - void SpawnLevel(bool IsFirst): Function responsible for generating new track elements.
    
     - void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult): Monitors and handles collisions between track elements.


## 3. Test
• I tested the game manually based on the following aspects:
     - Appropriate appearance and positioning of the game surface and characters.

     - The reaction of the game to the player's inputs (movement, jump, etc.).

     - Proper operation of collisions and collision detection.

     - Accuracy of track generation and gameplay variety.

• I performed performance tests, in which I evaluated game speed, frame rate, memory usage, etc.

• The results of the tests were positive, the game worked properly with the planned functions and mechanics.
