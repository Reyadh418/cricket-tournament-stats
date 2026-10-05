# Cricket Tournament Statistics

> *"Runs, wickets, and an average that will divide by zero the first time you run it."*

A command-line tournament statistics management system designed to track cricket player performances, compute key batting metrics, handle domain-specific mathematical edge cases, and utilize recursive algorithms for analysis.

---

## 👥 Group Information

- **Group:** Group 7
- **Group Name:** Team Undefined

| Name | ID |
| :--- | :--- |
| MD REYAD HASAN | 2633449 |
| IFTEDAR RAHMAN AFIF | 2621942 |
| MD AHONAF TAZWAR | 2621754 |
| MAHIM AHMED | 2631589 |

---

## 📋 Data Structure (`Record`)

Each player entry consists of the following attributes:

| Field | Type | Description |
| :--- | :--- | :--- |
| **Player ID** | `int` | Unique identifier for the player |
| **Name** | `string` | Full name of the player |
| **Innings** | `int` | Number of innings batted |
| **Runs** | `int` | Total runs scored |
| **Times Out** | `int` | Total dismissals |
| **Balls Faced** | `int` | Total deliveries faced |

---

## 🎯 Features & Menu Options

The application provides an interactive menu with the following operations:

1. **Add a Performance** — Input or update player match performances and statistics.
2. **Batting Averages** — Display batting averages across all players.
3. **Strike Rates** — Calculate and display batting strike rates.
4. **Search by Player** — Look up player records by ID or name.
5. **Top Five by Average** — Rank and display the top 5 batsmen sorted by batting average.
6. **Save & Load** — Persist player records to disk and reload them between sessions.

---

## 🧮 Computations & Formulas

- **Batting Average**:
  $$\text{Batting Average} = \frac{\text{Runs}}{\text{Times Out}}$$
  *Example:* $248\text{ runs} \div 9\text{ outs} \rightarrow 27.56$

- **Strike Rate**:
  $$\text{Strike Rate} = \frac{\text{Runs}}{\text{Balls Faced}} \times 100$$

---

## ⚠️ Important Considerations & Pitfalls

### 1. Division by Zero (Undefined Average)
* **Rule**: What to print for a batsman who has **never been out** (`times_out == 0`).
* **Handling**: In cricket statistics, the batting average for an undefeated batsman is **undefined** (neither $0$ nor $\infty$).
* **Requirement**: The system must explicitly detect this case and display an indicator (e.g., `Undefined` / `N/A`) without crashing or producing an arithmetic exception.

### 2. Integer Division Trap
* **Pitfall**: Evaluating `runs / times_out` where both operands are integers performs integer division, truncating the fractional part (e.g., `248 / 9` yields `27` instead of `27.56`).
* **Fix**: Ensure explicit floating-point division (e.g., casting one or both operands to `double` / `float`).

---

## 🔁 Algorithmic Requirements

- **Recursive Maximum**:
  Implement a recursive algorithm to find the **highest score over a slice of the array** (divide-and-conquer or recursive linear search).

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
