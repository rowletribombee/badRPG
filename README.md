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

 > ## Phase II

## User Interface Specification

### Navigation Diagram
This navigation diagram represents how our screen and interaction options change as the player progresses from the main menu into character setup and the main game loop, where they navigate through exploration, item interaction, and combat outcomes.
![cs100 navigation diagram (2)](https://github.com/user-attachments/assets/58192b4b-4c31-442f-8fa5-0af64640418f)

### Screen Layouts
[Screen Layout](https://docs.google.com/document/d/1VOla1fuHbr2JOMuvnhqX7As1DWS0icjsOhyZanJbCrs/edit?usp=sharing)

### Dummy Game Map
![image](https://github.com/user-attachments/assets/aaaf8e3f-1447-4c96-9c33-b07e5e4f94ff)

## Class Diagram
Updated Diagram: 
![IMG_0911](https://github.com/user-attachments/assets/8fe3c68b-a37a-4fb3-9ed2-9086d857fae6)

 > ## Phase III
## SOLID Principles
* Single Responsibility: We applied the Single Responsibility principle by implementing a Screen class dedicated solely to managing and printing text for different screens (e.g., command menu, inventory, map, etc.). This allowed us to improve our code by centralizing all printing functionality into one class, reducing redundancy. Originally, many classes in our design included their own print functions, leading to unnecessary complexity. By refactoring to include a single Screen class responsible for printing, we simplified our class diagram and adhered to the principle effectively.
* Open/Closed: This follows the Open/Closed principle, as we extended the Tile class's functionality by creating multiple derived classes for different types of tiles without modifying the original Tile class. This approach allowed us to enhance the behavior of Tile while keeping the base class intact. It improved our code by preventing repeated changes to the Tile class and instead enabling the creation of specific tile types through extension, resulting in a more maintainable and scalable design.
* Interface Segregation: This follows the Interface Segregation principle, as we ensured that the Item class does not force its subclasses to implement irrelevant properties. Originally, the Item class had a weight variable that was only applicable to Weapon but not to Potion. By removing the weight variable from the Item class, we ensured that Potion does not implement functionality it doesn't need. This change improves our code by making the design more focused and preventing future issues where Potion might incorrectly handle a weight value, which is irrelevant to its purpose.
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 To install and run 'I Woke Up in a Cave and All I Want is Wi-Fi,' clone the repository and then run the following commands in your terminal:
 > cmake .
  
 > make

 > ./startGame

 ## Testing
 > Our project was tested and validated using CI via Github Actions. 
 
