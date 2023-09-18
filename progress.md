 - [x] Write `zephyr/prj.conf`
 - [ ] Find main function, interrupt handlers and thread entry points
 - [ ] Identify the behavioral code in these contexts
 - [x] Find any infinite loops in the code (main setup, main loop)
    - [ ] Identify the difference between setup and repeated execution
    - [ ] Identify any time dependent behavior, especialy delays between iterations


- [x] Create new header file in the `lib/lab1/include` directory to hold definition of your function
- [ ] Create new source file in the `lib/lab1/src` directory to hold your function
- [ ] Take a block of code you identified in the infinite loop of your main execution context. Create a function in your new files, and move all of the code in a block into it
- [ ] Put a call to the function where the code used to be.
- [ ] Compile the code. You will be missing includes, variables, references, outputs, etc.

- [ ] For each missing variable or reference in the function you created, add input to the function
- [ ] If you need to return more than one value, pass it as an out param, which is a pointer to a value in the caller taht the function will populate. 
- [ ]Once your function is compiling, switch to the original location it was called from and populate the parameters of the function.


- [ ] In the function you extracted, identify any references to global variables, HAL devices, system functions, etc.
- [ ]See if you can remove the dependency by separating the concern of your code from the behavior of the dependency. For example, you could move a call to get data from a peripheral to the caller and pass the data into your function instead.
- [ ]Create new inputs to your function for pointers to dependencies.


- [ ]Make sure your code compiles.
- [ ]Commit the code you extracted.
- [ ]Add the following lines to your platformio.ini file.


- [ ] Create a new file in the test directory


- [ ] Create a new file in the test directory.
It can have any name, but by convention it has a similar name to the file you put your code in.
This can make it easier for another person to find the test later.
Add the code template from test.c in this directory to the file.
Your test must include a setUp and tearDown function. You can put any code in here that will be run at before and after each of test.
Your tests must have a main function.
This sets up the testing framework with the UNITY_BEGIN and UNITY_END macros.
For each test, you will call the RUN_TEST macro.
- [ ] Remove the example tests and add your own.
Tests by convention start with test_ but don't need to.
Each test should generally demonstrate one possible case. Having multiple tests instead of one big one makes it easier to identify what is failing.
- [ ] In your test, use any one of the GPIO peripherals available.
- [ ] Exercise the function under test and check the state of the GPIO peripherals.
Hint: check the docs at https://docs.zephyrproject.org/2.7.5/reference/peripherals/gpio.html for what functions are available to check the state of the GPIO peripheral.
- [ ] If you find yourself having trouble setting up the test, you have too many parameters, or a dependency is getting in the way, try refactoring the function further. Follow the same techniques from the previous activities.