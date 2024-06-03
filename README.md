## C++ mini-project - Blackjack
![C++ blackjack - github](https://github.com/kivelf/Blackjack/assets/107556520/22f3103e-e9ea-43bd-bd71-1726d2323360)

# 1. Motivation for choosing the task
Blackjack is a popular card game that I had never played before, so at the beginning I researched the rules and played some rounds online to get the hang of it. Afterwards, after considering some of the other options for the project, I thought that Blackjack seemed like an excellent choice because it offers an opportunity to demonstrate and apply the various programming concepts and techniques that are required in this project: such as object-oriented programming (OOP), the Standard Template Library (STL) and direct memory management through pointers.

# 2. Use of STL (Standard Template Library) in the solution
STL is utilized extensively in my Blackjack game implementation. Here are some key areas where STL has been applied:
- Vectors: **std::vector** is used to manage collections of cards in the Deck and Hand classes. Vectors provide dynamic array capabilities, enabling efficient addition, removal and access to elements which is why I chose them to represent the card collections.
 
*Example code:*

![Picture1](https://github.com/kivelf/Blackjack/assets/107556520/49c1f6ee-76af-4ed5-ab5e-d64f4e7072bc)

*// in the Deck class*

![Picture2](https://github.com/kivelf/Blackjack/assets/107556520/0bb1f459-a72d-4132-acf0-f31a6aa69a02)

*// in the Hand class*

- Algorithms: The **std::shuffle** algorithm in the Deck class is used to shuffle the deck of cards, thus ensuring randomness in the order of the cards.

*Example code:*

![Picture3](https://github.com/kivelf/Blackjack/assets/107556520/5f433849-e638-4af4-a4cd-743c56f542c6)

Using STL in C++ is a good practice because it provides a set of efficient, well-tested and reusable data structures and algorithms, which can significantly reduce development time and improve code reliability and maintainability.

# 3. Use of pointers in the solution
Pointers are used in several parts of my code to manage memory and references to objects efficiently:
- Card dealing: The **dealCard** method in the Deck class returns a pointer to a Card object, therefore allowing direct access to the card without copying it.

![Picture4](https://github.com/kivelf/Blackjack/assets/107556520/aae94a7b-7996-4212-8ddb-a6c9f48f56b7)

-	Hand Management: The Hand class stores pointers to Card objects. This approach minimizes memory usage and enhances performance by avoiding unnecessary copying of Card objects.

![Picture5](https://github.com/kivelf/Blackjack/assets/107556520/b1949075-c1ff-43df-aa3c-00020663df8f)

Using pointers in C++ is a great advantage because they allow for direct memory management, therefore enabling efficient and flexible control over resource allocation and deallocation, which in turn can optimize performance. Pointers also can be used for dynamic data structures such as linked lists and trees, where they can provide the needed flexibility in handling varying amounts of data.


# 4. Use of Classes and OOP
Classes are a fundamental part of this project, encapsulating the properties and behaviors of different components of the game. I have split the objects needed for the game in the following classes:
-	**Card Class:** Represents a single playing card with properties for rank and suit and methods to get the card's value and string representation.
-	**Deck Class:** Manages a collection of cards, providing the ability to shuffle and deal cards.
-	**Hand Class:** Represents the player's (or dealer's) hand, including methods to add cards, calculate the total value, check for busts and clear the hand.
-	**Player Class:** Manages player-specific information such as balance, current hand(s) and actions taken.
-	**Game Class:** Manages the game logic/flow, including dealing cards, managing the player and dealer turns and determining who is the winner at the end of every round.

Here is a simple UML class diagram representing the relationship between the classes (note that attributes and methods have been omitted for simplicity’s sake):

![Picture6](https://github.com/kivelf/Blackjack/assets/107556520/4d8c1aa4-e326-43a1-8865-4432366d2e0e)

Using classes and object-oriented programming (OOP) is a good practice because it promotes code modularity, reusability and maintainability by encapsulating data and behavior into cohesive units, thus making it easier to manage complex systems and facilitate collaboration. OOP also supports inheritance and polymorphism, and therefore allows for flexible code design.


# 5. Assembly Code for a Method
This task proved quite challenging as I didn't really have any simple standalone methods in my code that easily could be used in it. Therefore, I decided to make a tiny snippet of code inspired by the interaction with the user (from the game logic code in *Game.cpp*). Here's a simple method in main that asks for user input to demonstrate how the code would look like as assembly code:

![Picture7](https://github.com/kivelf/Blackjack/assets/107556520/e1985933-f1bd-4818-ac3e-c4128a38ac4e)

*C++ code*

![Picture8](https://github.com/kivelf/Blackjack/assets/107556520/a5942f50-93ad-47f2-b4fb-68e563e696aa)

![Picture9](https://github.com/kivelf/Blackjack/assets/107556520/8836483d-c8ef-4f6b-b02a-eefd86e79482)

*… and the code translated to Assembly code*

The provided assembly code snippet showcases the low-level representation of the C++ code's execution in machine language. In comparison to the C++ code, the assembly version contains a more detailed breakdown of the program's operations. One also immediately notices that the simple 7 lines of C++ code have turned into a whopping 66 lines of assembly code! The assembly code begins with initialization and destruction routines, highlighting memory management and object lifecycle handling. The main function, where user input is captured, reveals the sequence of instructions executed (such as stack manipulation, function calls and assigning registers).
Understanding assembly code provides insight into program behavior and aids performance optimization. The contrast between C++’s simplicity and assembly’s (seeming) complexity highlights the importance of writing efficient and readable C++ code, as it directly influences the resulting assembly output and overall program performance.


# 6. Organization of C++ Code
The project is organized into several header (.h) and source (.cpp) files, each serving a distinct purpose. The main components and their files are as follows:

-	Card Class: card.h, card.cpp
-	Deck Class: deck.h, deck.cpp
-	Hand Class: hand.h, hand.cpp
-	Player Class: player.h, player.cpp
-	Game Class: game.h, game.cpp
-	Main: main.cpp

Here is a screenshot of the project’s file structure shown in Visual Studio:

![Picture10](https://github.com/kivelf/Blackjack/assets/107556520/f5fe207a-b76f-4dc3-a45a-6f112d122367)

Organizing one’s code by using .h and .cpp files promotes modularity, thus making the code easier to manage, read and debug. It separates interface definitions from implementations and makes the code easier to reuse and maintain.


# 7. Application of C++ Core Guidelines
The project follows several of the C++ Core Guidelines to ensure safe, efficient and maintainable code:
-	[P.8: Don’t leak any resources:](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rp-leak) By making use of vectors and pointers to manage resources and avoid memory leaks.
-	[P.13: Use support libraries as appropriate:](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rp-lib) By using the STL: ctime, chrono, algorithm and others throughout the code, thus saving time and effort.
-	[Enum.2: Use enumerations to represent sets of related named constants:](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Renum-set) Enums are used for the Rank and Suit of Card objects.
-	[Error Handling:](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-errors) By using error messages to handle unexpected conditions such as trying to deal a card from an empty deck.

Applying the C++ Core Guidelines is a good idea as it improves one’s code by providing best practices and recommendations. Adhering to these guidelines helps prevent common programming errors and enhances code readability and robustness.

# 8. Documentation of the Program
The program includes documentation through comments within the code which explain the purpose and functionality of each method and class. Below are some screenshots of the running program, as well as selected code snippets:

![Picture11](https://github.com/kivelf/Blackjack/assets/107556520/201bfaec-6b4e-4cad-ba55-487cae4be412)

*Here we can see that Double and Surrender work as intended.*

![Picture12](https://github.com/kivelf/Blackjack/assets/107556520/2db26be5-0d8a-4ed5-a799-fd3f90b30e71)

*This part of the gameplay requires some improvements - the implementation of Split and handling several hands for the player has proven to be a bit challenging.*

![Picture13](https://github.com/kivelf/Blackjack/assets/107556520/25619013-a5fd-4524-bdb9-50efa118f10e)

*Endgame - here we can see that the game correctly handles the cases when the player has busted and when their balance goes below the minimum bet (10 euro).*

![Picture14](https://github.com/kivelf/Blackjack/assets/107556520/dd3927a9-add8-4d51-bc4d-ddcf44978f49)

*In Card.h we can see the use of Enum classes in C++ - something that we did not cover in the lectures, but I decided to learn and implement on my own since it seemed like the most logical way of representing the cards’ suits and ranks.*

![Picture15](https://github.com/kivelf/Blackjack/assets/107556520/39b8025f-919e-4765-9967-8603c661796f)

*By implementing this method in Hand.cpp I learned about the arrow operator in C++. Moreover I am proud that my implementation correctly handles the value for the Ace cards (which can either be 11 or 1).*

These screenshots illustrate the interactive nature of the game and highlight the use of enum classes as well as the method for calculating the hand total from the Hand class.

# Conclusion
This project has been an invaluable experience in refreshing some of my old knowledge in C++, as well as learning more about the language through practical application. By implementing a Blackjack game I not only deepened my understanding of core C++ concepts such as classes, pointers and STL, but I also gained insight into the importance of clean code organization and adherence to coding standards such as the C++ Core Guidelines.

"Learning by doing" has been at the heart of this project, as I tackled challenges and made decisions guided by hands-on experience. The most important part was working incrementally, adding to the project little by little and figuring out how to turn my ideas into C++ code. I stumbled upon several curious challenges along the way, including an interesting bug where the player would get a random amount of blackjack hands repeatedly one after another (thus increasing their profit tremendously - great for the player, but not so much for the casino! 🙂). Long story short, the heart of the issue was that modern day processors are simply too fast and I had not correctly accounted for that in my original idea of how to randomise the shuffling of the deck.

Overall, this project has been an excellent opportunity to solidify my C++ skills and has left me eager to continue exploring and mastering this powerful programming language. In the near future I would like to make a version 2.0 of this project where I deal with some minor bugs and tackle the challenge of adding a GUI to my program - something entirely new to me (in C++), which I unfortunately did not have enough time to attempt doing now, but am eager to try out very soon!
