# Athlete Competition Sorter in C

This C program manages data about athletes participating in races. It allows:
- Inputting athlete details and their race results
- Filtering only those who completed the race
- Classifying athletes by race type (300m and 400m)
- Sorting them by race completion time (ascending)

## Features

- Dynamically allocates memory for athlete data
- Supports multiple athletes and race types
- Filters only those who completed the race ("oui")
- Classifies by race type: 300m or 400m
- Sorts each group by fastest time
- Frees allocated memory to prevent leaks

---

## How to Compile

```bash
gcc main.c -o athlete-sorter
```
## How to Run

```bash
./athlete-sorter
```

## Example Input

```

Donnez le nombre d'athletes: 4

Athlete 1
Code: 101
Nom et prenom: Usain Bolt
Temps en seconde: 44
Type de course (400m/300m): 400m
Il termine la course? oui

Athlete 2
Code: 102
Nom et prenom: Yohan Blake
Temps en seconde: 42
Type de course (400m/300m): 400m
Il termine la course? oui

Athlete 3
Code: 103
Nom et prenom: Justin Gatlin
Temps en seconde: 38
Type de course (400m/300m): 300m
Il termine la course? oui

Athlete 4
Code: 104
Nom et prenom: Tyson Gay
Temps en seconde: 40
Type de course (400m/300m): 300m
Il termine la course? non

```

## Example Output

```
--- Résultats des 400m (trié par temps) ---

Athlete 1
Code: 102
Nom: Yohan Blake
Temps: 42 secondes
Type de course: 400m
A termine: oui

Athlete 2
Code: 101
Nom: Usain Bolt
Temps: 44 secondes
Type de course: 400m
A termine: oui

--- Résultats des 300m (trié par temps) ---

Athlete 1
Code: 103
Nom: Justin Gatlin
Temps: 38 secondes
Type de course: 300m
A termine: oui

```
