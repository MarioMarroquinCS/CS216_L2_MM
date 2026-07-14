**NG 7/13/2026**
* To provide you with thorough feedback, your instructor reads your code line by line, sometimes multiple times. Jumping from file to file is too time-consuming. Unless noted otherwise, place your class definitions above the main() and all function definitions below main(), all in one file. While the industry standard involves multi-source file programs, we will use a single file format for these labs unless instructed otherwise. Submit a fully completed lab by th due date using correct GitHib invite link to get a second chance
* feedback.md is for instructor use only.  Please DO NOT change the feedback.md; make a copy if needed; do no add anything
* if any, items with (-X) - no deductions this time, serve as a warning; please ensure these errors are corrected, as repeating them in future assignments will result in X points being deducted
* in feedback, #N means line number, e.g., 
```text
* #25  global var(s); only constant may be global -10
meaning: see line #25 ; -10 deduction points for the mistake
```
* class definition style & standards:  first, member vars  one per line and do not forget to initialize them; altghou private is a default access specifier, still label private members  clearly for better readability;  second- functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions, except for static function,  should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary;  to promote strong exception guarantee and to reduce redundancy, all setter functions, including c’tors, must call a setter function that sets all member variables

* 17 and like to ensure a strong exception guarantee, all setter functions, including c’tors,  must call the set function that sets all member variables, and all member variables must be initialized at the time of definition; this is to reduce the number of statements needed in setter function, reduce redundancy, simplify validation (if any),  and to avoid initialization list,e.g., setHealth() should be calling setCreature with 3 args -2 (-5)
* #21 why private?
* 24 and like: do not put closing } on the same line as else; else/else-if should be on their lines;  hard to read (-2)
* 38 should be const function (-1)
* 160 and like:<< not needed between strings -1
```text
 cout << "\n\nMenu Options:\n"
```
 * should have created a separate function to set up  a creature  and call it twice -2 
* could create two objects or ref to swap creatures depending on who attacks (-2)
* 166-167 should have been global const so it can be changed easily  (-1)
* inadequate and/ insufficient test data/ not all possible scenarios and edge cases have been tested; e.g., each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is a valid record; all menu options should be tested;  no zeros and/or negative numbers, no numbers divisible by both 7 and 5 etc.; big test numbers != good test data; must test all created functions; all possible pathways should be tested -5

***

