Philo - Philosophers with Threads and Mutexes

Overview :

The Philo project simulates philosophers sitting at a round table, eating, thinking, and sleeping. 
The simulation involves managing threads and mutexes to ensure proper synchronization and avoid data races.

Project Structure: 

  Program Name: philo
  Files: Makefile, *.h, *.c
  Makefile Targets: NAME, all, clean, fclean, re

make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

number_of_philosophers: The number of philosophers and forks.
time_to_die (in milliseconds): Time for a philosopher to die if they haven't eaten.
time_to_eat (in milliseconds): Time it takes for a philosopher to eat.
time_to_sleep (in milliseconds): Time a philosopher spends sleeping.
[number_of_times_each_philosopher_must_eat]: Optional argument to stop when philosophers have eaten a specified number of times.

Mandatory Part Rules :

  Each philosopher should be a thread.
  There is one fork between each pair of philosophers.
  If there are several philosophers, each philosopher has a fork on their left and right side.
  If there is only one philosopher, there should be only one fork on the table.
  To prevent duplicating forks, the forks' state should be protected with a mutex for each.
