# Fantasy Football Application Phase 1

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
   <pre><div class="dark bg-gray-950 contain-inline-size rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>bash</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>Copy code</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">git clone https://github.com/tahamajs/UT_Football_Fantesy_phase_2.git
   </code></div></div></pre>
2. **Compile the code:**
   <pre><div class="dark bg-gray-950 contain-inline-size rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>bash</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>Copy code</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">make
   </code></div></div></pre>
3. **Run the application:**
   <pre><div class="dark bg-gray-950 contain-inline-size rounded-md border-[0.5px] border-token-border-medium"><div class="flex items-center relative text-token-text-secondary bg-token-main-surface-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span>bash</span><div class="flex items-center"><span class="" data-state="closed"><button class="flex gap-1 items-center"><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" class="icon-sm"><path fill="currentColor" fill-rule="evenodd" d="M7 5a3 3 0 0 1 3-3h9a3 3 0 0 1 3 3v9a3 3 0 0 1-3 3h-2v2a3 3 0 0 1-3 3H5a3 3 0 0 1-3-3v-9a3 3 0 0 1 3-3h2zm2 2h5a3 3 0 0 1 3 3v5h2a1 1 0 0 0 1-1V5a1 1 0 0 0-1-1h-9a1 1 0 0 0-1 1zM5 9a1 1 0 0 0-1 1v9a1 1 0 0 0 1 1h9a1 1 0 0 0 1-1v-9a1 1 0 0 0-1-1z" clip-rule="evenodd"></path></svg>Copy code</button></span></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">./bin/futballFantasy.out</code></div></div></pre>

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
