# BombermanTest

-First Commit

- Have implemented the Player Character with simple movement.
- Have since created a PlayerCharacter class, which contains the move and bomb drop function, Player1 and Player2 both inherit this class. Now there is an issue with using the Keyboard for multiplayer input (so both players use it), this is due to Unreal assigning the keyboard inputs to controller 0 only. To solve this, I have the Player 1 cast to Player 2 and call the functions from there, it's not an efficent mode and would be changed (will swap this to C++ if I have time)
- The bombs in Bomberman are first placed on the spot that the Player is at, the player can then move through it but then the bomb becomes solid. To achieve this I setup the Bomb blueprint to have a sphere trigger collider and a sphere collider. The sphere collider is disabled at the start, and upon the event ActorEndOverlap the collider is turned back on. Also once the bomb has been destroyed it updates it's owners total bomb count to 1, this will be updated to increment it by 1, when the players bomb total count increases.
