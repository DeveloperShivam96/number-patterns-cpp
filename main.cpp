#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>

/**
 * Project: Task 01 - Number Patterns
 * 
 * Requirements Met:
 * 1. Single console program printing:
 *    a) Multiplication table for a number chosen by the user.
 *    b) Star pyramid of a height chosen by the user.
 * 2. Nested loops utilized for both outputs:
 *    - Multiplication table:
 *        * View 1: Multi-column formatted side-by-side equations using nested row/column loops.
 *        * View 2: Complete 2D matrix multiplication grid using nested row/column loops.
 *    - Star pyramid:
 *        * Outer loop for rows, inner loop 1 for leading spaces, inner loop 2 for star columns.
 * 3. Neatly aligned columns using <iomanip> (std::setw).
 * 4. Resilient input handling:
 *    - Gracefully handles 0 and negative inputs without crashing.
 *    - Recovers from non-integer/malformed input stream errors.
 * 5. Single, self-contained .cpp file.
 */

// Displays a visual separator line of specified character and length
void printDivider(char ch = '-', int length = 60) {
    for (int i = 0; i < length; ++i) {
        std::cout << ch;
    }
    std::cout << '\n';
}

// Robust integer input reader with validation and stream recovery
bool readInteger(const std::string& prompt, int& outValue) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> outValue) {
            // Discard any residual characters on the line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }

        if (std::cin.eof()) {
            return false;
        }

        // Handle invalid input (e.g. non-numeric characters) without crashing
        std::cout << "[Error] Invalid input detected. Please enter a valid integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
 * Prints the multiplication table for a user-specified integer.
 * 
 * Uses nested loops:
 * - Nested loop View 1: Outputs multipliers 1 to 10 split into 2 neatly aligned side-by-side columns.
 * - Nested loop View 2: Outputs a 2D matrix multiplication grid up to the target number.
 * 
 * Robustness:
 * - If 0 is entered: Shows mathematically correct products (all 0) cleanly formatted.
 * - If a negative number is entered: Correctly displays negative products with proper padding and sign handling.
 */
void printMultiplicationTable(int num) {
    std::cout << "\n============================================================\n";
    std::cout << "                   MULTIPLICATION TABLE                     \n";
    std::cout << "============================================================\n";
    std::cout << "Target Number: " << num << "\n\n";

    // -------------------------------------------------------------
    // View 1: Multi-Column Side-by-Side Table (Using Nested Loops)
    // -------------------------------------------------------------
    std::cout << "[View 1] Side-by-Side Aligned Table (Multipliers 1 to 10):\n";
    printDivider('-', 55);

    const int rowsPerColumn = 5;
    const int totalColumns = 2;

    // Outer loop: rows (1 to 5)
    for (int r = 1; r <= rowsPerColumn; ++r) {
        // Inner loop: side-by-side columns (Col 0: 1-5, Col 1: 6-10)
        for (int c = 0; c < totalColumns; ++c) {
            int multiplier = r + (c * rowsPerColumn);
            long long product = static_cast<long long>(num) * multiplier;

            // Neatly aligned columns using std::setw
            std::cout << std::setw(6) << num << " x "
                      << std::setw(2) << multiplier << " = "
                      << std::setw(7) << product;

            if (c < totalColumns - 1) {
                std::cout << "   |   ";
            }
        }
        std::cout << '\n';
    }
    printDivider('-', 55);

    // -------------------------------------------------------------
    // View 2: 2D Matrix Grid (Using Nested Loops)
    // -------------------------------------------------------------
    std::cout << "\n[View 2] 2D Multiplication Grid Table:\n";
    printDivider('-', 60);

    int startCol = 1;
    int endCol = 10;

    if (num == 0) {
        startCol = 0;
        endCol = 0;
    } else if (num < 0) {
        int absVal = std::abs(num);
        int displayLimit = (absVal > 10) ? 10 : absVal;
        startCol = -displayLimit;
        endCol = -1;
    } else {
        int displayLimit = (num > 10) ? 10 : num;
        startCol = 1;
        endCol = displayLimit;
    }

    const int colWidth = 7;

    // Grid Column Header
    std::cout << std::setw(4) << "x" << " |";
    for (int c = startCol; c <= endCol; ++c) {
        std::cout << std::setw(colWidth) << c;
    }
    std::cout << '\n';

    std::cout << "-----+";
    for (int c = startCol; c <= endCol; ++c) {
        for (int k = 0; k < colWidth; ++k) {
            std::cout << '-';
        }
    }
    std::cout << '\n';

    // Outer loop: Multipliers 1 through 10
    for (int r = 1; r <= 10; ++r) {
        std::cout << std::setw(4) << r << " |";

        // Inner loop: Columns from startCol to endCol
        for (int c = startCol; c <= endCol; ++c) {
            long long product = static_cast<long long>(r) * c;
            std::cout << std::setw(colWidth) << product;
        }
        std::cout << '\n';
    }
    printDivider('-', 60);
}

/**
 * Prints a centered star pyramid of a user-specified height.
 * 
 * Uses nested loops:
 * - Outer loop: Row iterator (1 to height)
 * - Inner loop 1: Leading spaces for symmetrical center alignment
 * - Inner loop 2: Stars (2 * row - 1)
 * 
 * Robustness:
 * - If height is 0: Prints a clear notice without crashing or drawing.
 * - If height is negative: Prints a clear notice without crashing or negative loop bounds.
 */
void printStarPyramid(int height) {
    std::cout << "\n============================================================\n";
    std::cout << "                        STAR PYRAMID                        \n";
    std::cout << "============================================================\n";
    std::cout << "Chosen Height: " << height << "\n\n";

    if (height < 0) {
        std::cout << "[Notice] Negative height (" << height 
                  << ") entered. Pyramid height must be non-negative.\n";
        std::cout << "         No pyramid layers to render.\n";
        return;
    }

    if (height == 0) {
        std::cout << "[Notice] Height is 0. No pyramid layers to render.\n";
        return;
    }

    std::cout << "Pyramid Output:\n";

    // Outer loop: Controls rows from layer 1 up to height
    for (int i = 1; i <= height; ++i) {
        // Inner loop 1: Leading spaces to horizontally center the pyramid
        for (int s = 0; s < height - i; ++s) {
            std::cout << ' ';
        }

        // Inner loop 2: Star columns (odd numbers: 1, 3, 5, 7, ... = 2 * i - 1)
        for (int j = 0; j < (2 * i - 1); ++j) {
            std::cout << '*';
        }

        // End of row
        std::cout << '\n';
    }

    std::cout << "\n(Pyramid successfully rendered with " << height << " layers)\n";
}

int main() {
    std::cout << "============================================================\n";
    std::cout << "              NUMBER PATTERNS CONSOLE PROGRAM               \n";
    std::cout << "============================================================\n";
    std::cout << "Features demonstrated:\n";
    std::cout << " - Multiplication table with nested loops and aligned columns\n";
    std::cout << " - Symmetrical star pyramid with nested loops\n";
    std::cout << " - Safe handling of 0, negative, and invalid inputs\n\n";

    // 1. Prompt and generate multiplication table
    int tableNumber = 0;
    if (!readInteger("Enter an integer for the multiplication table: ", tableNumber)) {
        std::cout << "Input stream closed. Terminating.\n";
        return 0;
    }
    printMultiplicationTable(tableNumber);

    // 2. Prompt and generate star pyramid
    int pyramidHeight = 0;
    if (!readInteger("\nEnter the desired height for the star pyramid: ", pyramidHeight)) {
        std::cout << "Input stream closed. Terminating.\n";
        return 0;
    }
    printStarPyramid(pyramidHeight);

    std::cout << "\n============================================================\n";
    std::cout << "       All tasks completed successfully. Goodbye!           \n";
    std::cout << "============================================================\n";

    return 0;
}
