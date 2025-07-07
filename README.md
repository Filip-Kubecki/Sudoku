# Sudoku Application 🧠✨

This is a Sudoku application developed using the **Qt framework** and **C++**. It provides a classic 9x9 Sudoku grid with an interactive user interface, allowing users to play, generate, clear, and solve Sudoku puzzles.

![image](https://github.com/user-attachments/assets/2e9f1d1d-78a5-4cc1-8bfb-471b78fa3d8a)

## Features 🚀

  * **Interactive 9x9 Grid:** A grid of buttons lets you select a cell and enter a value. 🖱️
  * **UI Numpad:** An on-screen numpad (buttons for numbers 1-9) for easy input of values into the selected Sudoku cells. 🔢
  * **Generate Button:** Creates a new, random Sudoku board with a specified number of missing values. 🎲
  * **Clear Button:** Clears all values from the current Sudoku board, allowing you to start fresh. 🧹
  * **Solve Button:** Automatically fills in all missing values with the correct solution for the current Sudoku puzzle. ✅
  * **Difficulty Slider:** Adjust the difficulty of generated puzzles. Moving the slider to a higher difficulty will result in more empty fields on the board. 

## Technologies Used 🛠️

  * **Qt Framework:** For the graphical user interface (GUI) development. 
  * **C++:** The core programming language for the application logic and Sudoku algorithms. 

## How to Use 🎮

1.  **Generate a Puzzle:** Click the **"Generate"** button to create a new Sudoku puzzle. Use the **difficulty slider** to control how many cells are left empty. 🆕
2.  **Enter Values:** Click on a cell in the 9x9 grid to select it. Then, use the **UI numpad** to enter a number (1-9). ✍️
3.  **Clear Board:** If you want to start over, click the **"Clear"** button to remove all values from the board. 👋
4.  **Solve Puzzle:** If you get stuck or want to see the solution, click the **"Solve"** button. The application will automatically fill in the correct values. 💡

## Building and Running the Application ⚙️

To build and run this application, you'll need the Qt development environment set up on your system.

**Prerequisites:**

  * Qt (e.g., Qt 5 or Qt 6)
  * A C++ compiler (e.g., GCC, Clang, MSVC)

**Steps:**

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/Filip-Kubecki/Sudoku
    cd Sudoku
    ```

2.  **Open the project in Qt Creator:**

      * Launch Qt Creator.
      * Go to `File` \> `Open File or Project...` and navigate to the project's `CMakeLists.txt` file (located in the cloned `Sudoku` directory).

3.  **Build the project:**

      * Once the project is loaded, go to `Build` \> `Build Project "SudokuApp"` (or a similar option depending on your project name).

4.  **Run the application:**

      * After a successful build, go to `Build` \> `Run` or click the green "Run" button in Qt Creator.
