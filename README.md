# 🍝 Philosophers - Thread Synchronization Project

## Overview
An efficient solution to the classic Dining Philosophers problem, implementing thread management and mutex synchronization in C. This project demonstrates advanced understanding of concurrent programming and resource sharing in multi-threaded environments.


## 🔍 Technical Proficiency Demonstrated
This project showcases my ability to:
- Implement complex multi-threaded applications
- Handle critical sections and race conditions
- Manage system resources efficiently
- Debug concurrent programming issues
- Optimize performance in multi-threaded environments

## 🛠 Technical Implementation

### Core Features
- Thread-safe philosopher state management
- Mutex-protected fork allocation
- Precise timing control
- Death detection system
- Resource cleanup handling
  
- ## 💡 Key Learnings
- Advanced thread synchronization
- Mutex management strategies
- Race condition prevention
- Resource allocation patterns
- Performance optimization

## 🚀 Skills Demonstrated

### Threading Concepts
- Thread creation and management
- Mutex synchronization
- Condition variables
- Critical section handling

### System Programming
- Process management
- Memory management
- Time precision handling
- Signal handling

## 📝 Project Status
- ✅ Core implementation complete
- ✅ Thread safety verified
- ✅ Performance optimized
- ✅ Memory leaks addressed
  
## 📊 Performance Considerations

### Resource Optimization
- Efficient mutex locking patterns
- Minimal context switching
- Optimized memory usage
- Clean thread termination

### Deadlock Prevention
- Resource hierarchy
- Timeout mechanisms
- State monitoring
- Fork allocation strategy


### Key Metrics
```c
struct s_program
{
    int philosophers;     // Number of philosophers
    int time_to_die;     // Maximum time without eating
    int time_to_eat;     // Time required to eat
    int time_to_sleep;   // Sleep duration
    int meals_required;  // Optional: meal count target
};
```

## 💻 Usage

### Compilation
```bash
# Build the program
make

# Clean build files
make clean

# Full rebuild
make re
```

### Running the Simulation
```bash
# test with 200 thread or small than 
# Basic usage
./philo <philos> <death_time> <eat_time> <sleep_time>

# With meal count
./philo <philos> <death_time> <eat_time> <sleep_time> <meal_count>

# Example
./philo 5 800 200 200 5
```

## 🔧 Technical Details

### Thread Management
```c
// Thread creation for each philosopher
for (i = 0; i < num_philos; i++) {
    pthread_create(&philos[i].thread, NULL, 
                  philosopher_routine, &philos[i]);
}
```

### Mutex Implementation
```c
// Fork protection
pthread_mutex_t forks[num_philos];
for (i = 0; i < num_philos; i++) {
    pthread_mutex_init(&forks[i], NULL);
}
```



*"Solving concurrent programming challenges with elegant solutions"*

</div>
