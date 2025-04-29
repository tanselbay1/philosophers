# Philosophers

This project is part of the 42 curriculum and is an implementation of the classic "Dining Philosophers" problem. It demonstrates the use of multithreading, mutexes, and synchronization to solve concurrency issues.

---

## 🛠️ Project Overview

The goal of the project is to simulate a group of philosophers sitting at a round table. Each philosopher alternates between three states: **thinking**, **eating**, and **sleeping**. Philosophers share forks, and they must follow specific rules to avoid deadlocks and starvation.

---

## 🚀 Features

- Handles multiple philosophers with shared resources (forks).
- Implements mutexes to prevent race conditions.
- Avoids deadlocks and ensures proper synchronization.
- Includes a monitor thread to check for philosopher deaths or completion of meals.
- Configurable parameters for simulation.

---

## 📋 Usage

### Compilation

To compile the project, run:

```bash
make
```

This will generate an executable named `philo`.

### Running the Program

Run the program with the following arguments:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

- `<number_of_philosophers>`: Number of philosophers (and forks).
- `<time_to_die>`: Time (in milliseconds) a philosopher can live without eating.
- `<time_to_eat>`: Time (in milliseconds) it takes for a philosopher to eat.
- `<time_to_sleep>`: Time (in milliseconds) a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]` (optional): If provided, the simulation ends when all philosophers have eaten this many times.

### Example

```bash
./philo 5 800 200 200
```

This runs the simulation with 5 philosophers, where:
- Each philosopher dies if they don't eat within 800ms.
- Eating takes 200ms.
- Sleeping takes 200ms.

---

## 🧠 How It Works

1. **Philosopher States**:
   - **Thinking**: The philosopher is thinking and waiting for forks.
   - **Eating**: The philosopher picks up two forks and eats.
   - **Sleeping**: After eating, the philosopher sleeps.

2. **Forks**:
   - Each philosopher has a left and right fork.
   - Forks are shared between neighboring philosophers.

3. **Synchronization**:
   - Mutexes are used to lock forks and shared resources.
   - A monitor thread checks for philosopher deaths or completion of meals.

---

## 🛠️ Code Structure

- **`main.c`**: Entry point of the program. Initializes data, starts threads, and cleans up resources.
- **`init/`**: Contains initialization functions for philosophers and mutexes.
- **`routine/`**: Implements the philosopher routines and the monitor thread.
- **`utils/`**: Utility functions for parsing arguments, printing statuses, and handling time.

---
