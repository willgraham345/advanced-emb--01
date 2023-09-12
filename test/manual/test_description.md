# Test Plan
Recursion test plan. 


## Testing Strategy
Inputs: Invariant or constant. If not, they are state. Our test should include multiple cases of different input combinations. 
State: Properties or data of the system that change over time. 
Outputs: Typically invariant over time. 
Execution contexts: There are two, the thread and the main loop. Execution contexts represent a computational environment where the code runs. Usually managed by the hardware or OS.
Dependencies: Systems, devices, and behaviors external to your code that your code relies on. 


## Unit vs Integration Testing
### Unit Tests
- Usually invariant
- Initial state is set ahead of time to a known value, and changes in state are usually due to the execution of the code. 
Unit tests usually have an expected output for a given input, and the output is asserted to be the expected value
- Unit tests should have limited references to dependences. Dependencies either need to be controlled or mocked with a simulated implementation. 
- Should be automated and fast to run
### Integration Tests
- Cover the behavior of the system in aggregate. This measures interactions between units you tested via unit tests. 
- Often done manually, simulated, or run on actual hardware. 



# Test Plan
## How to set up the test scenario


## How to exercise the system
## Expected results

# Test Cases
### Test main_setup()
### Test main_loop()