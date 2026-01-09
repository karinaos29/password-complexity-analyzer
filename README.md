## 🛡️ Password Strength Analyzer (C)

A simple, command-line tool written in C that evaluates password complexity based on length, character variety, and common weak patterns. The results are displayed with high-visibility, color-coded strength levels.

## Password Requirements - Minimum length of 8 characters.

## Strength Evaluation Logic
The analyzer calculates a score based on the following criteria:


** Contains Lowercase -> +1 
** Contains Uppercase -> +1 
** Contains Digits -> +1 
** Contains Special Characters -> +1 
** Length > 9 -> +1 
** Length > 12 -> +2 

Penalties:
** Consecutive Repeated Chars (>4) -> -1 
** Single-type only (e.g. only digits) -> -1 

### Visual Feedback
Scores are mapped to colored terminal output for immediate readability:
* <span style="color:red">**WEAK**</span> (Score ≤ 2)
* <span style="color:yellow">**MEDIUM**</span> (Score 3–4)
* <span style="color:green">**STRONG**</span> (Score 5–7)
* <span style="color:cyan">**VERY STRONG**</span> (Score 8+)

---

##  Demo

The following screenshot demonstrates the analyzer in action, showcasing the logic for different complexity levels and terminal color output:

![Password Analyzer Terminal Output](screenshot.jpeg)

---

## File Structure
```text
password_analyzer/
│── main.c          # Core program logic
└── README.md       # Project documentation
```
---
## How to Compile
```bash
gcc main.c -o analyzer
./analyzer
```
