# Fantasy Football Application

## Overview

This project is a command-line application for managing a fantasy football league. Users can sign up, manage teams, conduct player transactions, and track league standings. The application is developed in C++ with a focus on modularity and object-oriented principles.

## Features

1. **User and Team Management**

   - **Signup:** Users can create a new fantasy team by providing a team name and password.
   - **Login:** Users log into their teams and manage their squads.
   - **Logout:** Users can securely log out of their sessions.
2. **Player Transactions**

   - **Buy/Sell Players:** Manage player transfers with validation on player availability and budget constraints.
   - **Set Captain:** Assign a captain to your team who earns extra points.
   - **View Budget:** Check your remaining budget after transactions.
3. **Team Management**

   - **View Squad:** Display your current team lineup, including player roles, points, and total team cost.
   - **Team of the Week:** View the best performers of the week based on their scores.
4. **League Management**

   - **League Standings:** Track the standings of all teams in the league.
   - **User Rankings:** See how your team ranks against other users.
   - **Match Results:** View the results of matches for each week.

## Data Structure

The application uses several CSV files to store and retrieve data:

- **premier_league.csv:** Contains data on all players in the league, including price, score, goals, assists, and clean sheets.
- **weeks_stats:** A folder containing weekly performance stats for players.

### Example CSV Structure

```plaintext
data
├─── premier_league.csv
└─── weeks_stats
      ├─── week_1.csv
      ├─── week_2.csv
      ├─── week_3.csv
      ...
```

## Getting Started

### Prerequisites

- **C++ Compiler:** A C++11 compatible compiler (e.g., g++) is required.
- **Makefile:** The project includes a Makefile for easy compilation.

### Installation and Setup

1. **Clone the repository:**

   ```bash
   git clone https://github.com/tahamajs/UT_Football_Fantesy_phase_2.git
   ```
2. **Compile the code:**

   ```bash
   make
   ```
3. **Run the application:**

   ```bash
   ./futballFantasy.out
   ```

### Commands Overview

- **Signup:**

  ```bash
  POST signup ? team_name <team_name> password <password>
  ```
- **Login:**

  ```bash
  POST login ? team_name <team_name> password <password>
  ```
- **Buy a Player:**

  ```bash
  POST buy_player ? name Virgil Van Dijk
  ```
- **View Squad:**

  ```bash
  GET squad ? fantasy_team Liverpool_Iran
  ```
- **View League Standings:**

  ```bash
  GET league_standings
  ```

## Contribution

If you want to contribute to the project, follow the standard GitHub flow:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
