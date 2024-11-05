# I Woke Up in a Cave and All I Want is Wi-Fi

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
![cs100 uml (1)](https://github.com/user-attachments/assets/db6b87f0-7206-496d-9153-0c5721ddd149)

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
