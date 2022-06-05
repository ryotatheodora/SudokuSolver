Members:  
- Ryota  
- Tammy Le
- Yohanes  

Exact Steps to build and run program 

Commands: 
$ rm -f a.out (clear any output text file)
$ rm -rf HW4
$ g++ -g -std=c++11 *.cpp
$ ./a.out 100 1000

Repeat fourth command (step 4) until solution pops up (depending on sudoku difficulty, this may have to repeat many, many times)

Brief Analysis
Using the genetic algorithm was challenging for our code to achieve an optimal solution in a reasonable amount of time. Restarting the GA when it got "stuck" often worked, although it might take many restarts before getting the correct solution. An "optimal" restart strategy, using the best solutions from several generations, had a better chance of finding the correct solution but did not always do so. (Dr. Weiss) 

We agree with Dr. Weiss that changing the fundamental GA parameters (population size) profoundly impacted performance. However, it was not obvious how to generalize results from one problem instance to the next. As expected, larger populations of solutions were helpful and additional genetic operators. Based on our code, using the non-deterministic method (genetic algorithm) prove remarkably ineffective in solving Sudoku. We cannot reliably get reasonable solutions using this algorithm. When we get the perfect solution (rare), it will take 100 population sizes with 1000 generations, and we would run the output many times before reaching the solution. Overall, using the GA performance in solving Sudoku was remarkably slow. From our experience, it is safe to say that the test cases given were complex problems of Sudoku. When we input an easier sudoku problem, it does take less time to get to the solution.

Reference: http://micsymposium.org/mics_2009_proceedings/mics2009_submission_66.pdf
