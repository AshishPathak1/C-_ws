#include<iostream>

int pattern_printing(int total_lines) {
    for (int line_number{1}; line_number <= total_lines; line_number++) {
        for (int digits_per_line{1}; digits_per_line <= line_number; digits_per_line++) {
            std::cout << " " << digits_per_line << " ";
        }
        std::cout << std::endl;
    }
}

void pattern_printing2(int total_lines) {
    for (int line_number{total_lines}; line_number >= 1; line_number--) {
        for (int digits_per_line{1}; digits_per_line <= line_number; digits_per_line++) {
            std::cout << " " << digits_per_line << " ";
        }
        std::cout << "\n";
    }
}


/*
 
 4 3 2 1
 3 2 1
 2 1
 1
 */

void pattern_printing3(int total_lines) {
    for (int line_number{total_lines}; line_number >= 1; line_number--) {
        for (int digits_per_line{line_number}; digits_per_line >= 1; digits_per_line--) {
            std::cout << " " << digits_per_line << " ";
        }
        std::cout << "\n";
    }
}

/*
 
 * * * *
  * * *
   * *
    *
 
 */

void pattern_printing4(int total_lines) {
    for (int line_number{total_lines}; line_number >= 1; line_number--) {
        for (int space_per_line{total_lines}; space_per_line > line_number ; space_per_line--) {
            std::cout << " ";
        }
        for (int star_per_line{1}; star_per_line >= line_number; star_per_line++) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

/*
 
    *
   * *
  * * *
 * * * *
 
 */
void pattern_print5(int total_lines) {
    for (int line_number{1}; line_number <= total_lines; ++line_number) {
        for (int space_per_line{total_lines-1}; space_per_line >= line_number; --space_per_line) {
            std::cout << " ";
        }
        for (int star_per_line{1}; star_per_line <= line_number; ++star_per_line) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

void pattern_printing5(int total_lines) {
    for (int line_number = 1; line_number <= total_lines; line_number++) {
        // Print spaces
        for (int space_per_line = total_lines; space_per_line > line_number; space_per_line--) {
            std::cout << " ";
        }

        // Print stars
        for (int star_per_line = 1; star_per_line <= line_number; star_per_line++) {
            std::cout << " *";
        }
        std::cout << "\n";
    }
}


void pattern_printing5a(int total_lines) {
    for (int line_number = 1; line_number <= total_lines; line_number++) {
        // Print spaces
        for (int space_per_line = 1; space_per_line <= (total_lines-line_number); space_per_line++) {
            std::cout << " ";
        }

        // Print stars
        for (int star_per_line = 1; star_per_line <= line_number; star_per_line++) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}
/*
 
    *
   ***
  *****
 *******
 
 */

/*
 
 *******
 *** ***
 **   **
 *     *  
   

 */

void pattern_printing6(int total_lines) {
    /*Prints the topmost line*/
    for (int line_number = 1; line_number <= (2*total_lines)-1; line_number++) {
        std::cout << "* ";
    }
    std::cout << "\n";
    
    for (int line_number = 1 ; line_number < total_lines; line_number++) {
        for (int star_per_line = 1; star_per_line <= (total_lines-line_number); star_per_line++) {
            std::cout << "* ";
        }
        // Print spaces
        for (int space_per_line = 1; space_per_line <= ((2*line_number)-1); space_per_line++) {
            std::cout << "  ";
        }
        for (int star_per_line = 1; star_per_line <= (total_lines-line_number); star_per_line++) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }

}

/*
 TR = 10
 
 * * * * * * * * * * 
  * * * * * * * * *
   * * * * * * * *
    * * * * * * *
     * * * * * *
      * * * * *
       * * * *
        * * *
         * *
          *
         * *
        * * *
       * * * *
      * * * * *
     * * * * * *
    * * * * * * *
   * * * * * * * *
  * * * * * * * * *
 * * * * * * * * * * 
 
 */
/*
 TR =  5
  
 * * * * * 
 *       * 
 *       *
 *       *
 * * * * *     
  
 */


/*
 IN =  E
  
 A               A
 A B           B A 
 A B C       C B A
 A B C D   D C B A
 A B C D E D C B A 
 
 */

int main() {
    unsigned int number;

    std::cout << "Enter Number of lines to be printed : ";
    std::cin >> number;

    std::cout << "Here is the pattern :\n";
  //  pattern_printing(number);
    pattern_printing6(number);
    // printPattern(number);
}