# BombermanTest

Total Dev Time: 16ish hours

Finished Downloadable Build: https://zubby.itch.io/bomberman

Development Process:
Started by implementing the player character's, made it so that the player can't move if you press two input keys at the same time, this and stops the player moving diagonally. One challenge was getting the input for both the players, as keyboard input is automaticlly assigned to player 1 controller. So I used the Player 1 to call movement functions on Player 2, when Player 2s inputs are pressed, which allowed Player 2 to move.

Next step was implementing the bomb - both placement and explosion. The bombs in Bomberman are first placed on the spot that the Player is at, the player can then move through it but then the bomb becomes solid. To achieve this I setup the Bomb blueprint to have a sphere trigger collider and a sphere collider. The sphere collider is disabled at the start, and upon the event ActorEndOverlap the collider is turned back on. Also once the bomb has been destroyed it updates it's owners total bomb count to 1, this will be updated to increment it by 1, when the players bomb total count increases. Also made sure that when the bombs are placed, they are placed on the center of the grid position. For the explosion, four raycasts are sent from the center of the bomb (in each direction). The raycasts go as far as the player's damage value is (1 damage = 1 square, 2 damage = 2 squares). If they hit any Walls (Breakable/Unbreakable tags), we update the explosion distance in that direction, if no wall is hit then the distance is set to max. The explosion is then visualised and damage messages sent to objects with the damage interface.

Finally was the walls + powerups, the power ups themselves are quite straight forward. They inherit from a Power Up class, which just has a box collider and destroys upon collision. Each power up then calls a differnt update player function from the player interface, which updates either the speed, damage or amount value of the player. The breakable walls, when hit by an explosion get a random number between 0-100, if it's greater than or equal to 70, it spawns a power up. The type of power up is chosen from a random number between 0-2 (0,1,2. This is spawned at the walls position. 

The final things done, was the HUD for the players, which reads variable values from each player character, and displays them on screen (health and bomb amount). Also addedd a Player win UI for each player, and a starter screen to inform the player how to play.


Future Development:
Remote bomb power up - once picked up the player is informed they have it (UI) and use a seperate input button to place the remote bomb, and pressing again triggers it.

Dynamicly created maps - currently the game map is the same every time, but would be more interesting to have it be different each time, even have the user enter the dimensions of the level. Would use a 2D array (100x100)
or ask the user for the size values, first would assign a value for the player spawns, and make sure to leave space around the player spawn (don't want to trap the player). Next loop through and place the unbreakable blocks
every other space (make sure it's possible for both players to reach each other). Finally loop through the remaining squares, and randomly choose a number between 0/1 (1 place breakable wall). Finally loop through entire array and
place the correct actor based on the array position value.

Multiplayer - Add in extra players, most likely have to use gamepads for the extra input (bit difficult to fit 4 people on same keyboard)

Enemies - Simple Ai enemies, with three states (wander, defensive, aggro). Wander just moves around the map, not reacting to bombs. Defensive, move away from bombs when it can. (If within X tiles of a bomb, move in oppisite direction
and check to see if any side spaces are free, to get it out of line of sight). Aggro, move towards nearest player, places bomb when reaches breakable wall and moves out of range. Have enemies have a chance to drop power ups upon death,
improve drop chance based on difficulty (0.3 - Wander, 0.4 - Defense, 0.5 - Aggro).

Extra Power Ups
Power Gloves - Ability to push bombs aways, when player bumps into the bomb with the power up move it directly away from the player till it hits either type of wall
Ghost Mode - Allows player to move through breakable walls for X seconds, turn off breakable wall collider between that player
Invincibilty - Prevents player from taking damage for X seconds, have a bool check, which is checked before taking damage - turned on when pickup is picked up
Resetter - Resets all other players bonses (Damage, speed and bomb amount) by 1, call function from each other player reducing their variable stats by 1

Resources Used:
Unreal Starter Content
Textures: (Found in Texture folder)
Pixel Heart: https://cdn.pixabay.com/photo/2017/09/23/16/33/pixel-heart-2779422_640.png
Pixel Bomb: https://image.spreadshirtmedia.net/image-server/v1/designs/11510420,width=178,height=178/pixel-bomb.png
