# I Woke Up in a Cave and All I Want is Wi-Fi 
![Build Status](https://github.com/cs100/final-project-pinkie-pie/actions/workflows/main.yml/badge.svg)
 > Authors: [Sookie Drabla](https://github.com/sdrabla), [Stanley Lew](https://github.com/stanleylew5), [Gregory Wang](https://github.com/rowletribombee), [Kelly Ma](https://github.com/kellyma073), & [Anthony Emery](https://github.com/antodough)

## Project Description

We love video games and wanted to take this opportunity to create our own. *I Woke Up in a Cave and All I Want is Wi-Fi* blends strategy and fantasy while adding a satirical take on the isekai trope. It's a fun project because it allows us to explore creative game design, implement unique mechanics, and exercise our coding skills in C++. We're excited to design how the player's journey unfolds as they attempt to escape the cave!

We plan to use C++ for the backend and GitHub for tracking tasks and progress. For the output, ASCII art might be incorporated to depict simple visuals of characters or maps to add flavor.

Input: The game will take the user's choices through text-based commands like movement (up, down, left, right), item usage, and combat interactions. For instance, players will choose their character class at the start, affecting base stats like Attack (ATK), Health (HP), and Defense (DEF). Example inputs include choose direction (e.g., "move left"), attack options (e.g., "attack goblin"), and use item (e.g., "equip sword").

Output: The output will show the consequences of these choices. Example outputs include descriptions of the current location, results of battles, and score at the end of the game based on how efficiently they escaped or navigated the cave.

Some features we plan on providing include:
* Character Classes: Players choose from different character classes (Barbarian, Human, Dwarf, Elf, etc.), each with distinct base stats. Classes affect combat mechanics.
* Movement System: Players navigate the cave with a vector grid (e.g., vector<vector<int>> vect). Players can move up, down, left, or right but may encounter monsters or barriers that require a decision to fight or find another route.
* Combat and Items: Players battle monsters they encounter and can equip items like swords, shields, and potions. Each item improves their chances in combat.
* Dialogue: Humorous, story-driven dialogue adds to the game’s quirky tone. All the characters are a little silly.
* Map Visualization: A 2D grid map will help players visualize their progress and decide their next moves.
* Scoring System: The player's score is determined by how quickly they find the optimal path out of the cave. Certain paths may have detours to pick up items or fight bosses, but they add to the "move count." Winning is possible through various paths, but those who play strategically get higher points.
* Save/Load Game Functionality: Players can save their current game state at any point, allowing them to load and continue their adventure later. This feature ensures that players can manage their gameplay time effectively without losing progress.


### Navigation Diagram
This navigation diagram represents how our screen and interaction options change as the player progresses from the main menu into character setup and the main game loop, where they navigate through exploration, item interaction, and combat outcomes.
![Screenshot 2024-12-06 143022](https://github.com/user-attachments/assets/95011911-e4c3-4d05-98a0-1c94bb106a02)

### Screen Layouts
[Screen Layout](https://docs.google.com/document/d/1VOla1fuHbr2JOMuvnhqX7As1DWS0icjsOhyZanJbCrs/edit?usp=sharing)

### Dummy Game Map
![image](https://github.com/user-attachments/assets/aaaf8e3f-1447-4c96-9c33-b07e5e4f94ff)

## Class Diagram
Updated Diagram: 
![Screenshot 2024-12-06 161131](https://github.com/user-attachments/assets/26095829-5698-4e52-bfa8-bcee65e3d7c2)


 
 ## Screenshots
* Starting game: <br/>
![image](https://github.com/user-attachments/assets/1279e814-a1d0-4282-9768-e73471712eed)
* Starting message and instructions: <br/>
![image](https://github.com/user-attachments/assets/4173ed84-1e17-4e37-be67-58c85e7b1380)
* Race selection: <br/>
![image](https://github.com/user-attachments/assets/b409c98e-edd8-4be2-b717-350cee921c7c)
* Choosing race: <br/>
![image](https://github.com/user-attachments/assets/2da0a841-c004-42c0-9af2-a838ff8126af)
* Choice menu: <br/>
![image](https://github.com/user-attachments/assets/a81403e2-c98f-42b4-84bf-a6776459f705)
* (G) Map <br/>
![image](https://github.com/user-attachments/assets/bfdaaccc-d721-4c40-bbcc-2c6edabf0c08)
* (X) Credits <br/>
![image](https://github.com/user-attachments/assets/64ffe7eb-cf95-41f7-a333-da71000c39a0)
* (I) Inventory <br/>
![image](https://github.com/user-attachments/assets/2540e603-490b-4e7b-9e63-da71aa824805)
* (S) Stats <br/>
![image](https://github.com/user-attachments/assets/9f1c5a56-ed7a-4b26-8e7d-b82147ee981a)
* Move through the map: <br/>
![image](https://github.com/user-attachments/assets/435e00c3-f83b-476a-b582-33734b583191)
* Saving and quiting: <br/>
![image](https://github.com/user-attachments/assets/efaf813b-714c-410d-97dd-35028a48be1c)


 ## Installation/Usage
 To install and run 'I Woke Up in a Cave and All I Want is Wi-Fi,' clone the repository and then run the following commands in your terminal:
 > cmake . && make && ./startGame

 ## Testing
* Our project was tested (gtest) and validated using CI via Github Actions. We tested our project using unit tests, and using the googletest submodule as a framework to validate the tests. In the folder called tests, we include all of our separate testing .cpp files for separate interfaces as well as a CMakeLists.txt file to have executables to run the tests. 
 
