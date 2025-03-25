---

# 🚀 Battle Ship – A Console-Based Shooting Game  

## 📌 Overview  
**Battle Ship** is a command-line shooting game developed in **C++**, where players control an aircraft, shoot enemy ships, and avoid enemy fire. The game includes a **dynamic battlefield**, scoring system, and power-ups that enhance gameplay.  

This project demonstrates **fundamental game development concepts** such as **object movement, collision detection, event handling, and game loops** in C++.  

---

## 🎮 Features  

✅ **Player-controlled Aircraft** – Move across the screen using **WASD keys**  
✅ **Shooting Mechanism** – Fire missiles (`|`) to destroy enemy ships (`#`)  
✅ **Enemy AI & Attacks** – Enemies fire back (`!`), reducing player health  
✅ **Power-ups & Collectibles** – Restore health and increase score (`+`)  
✅ **Stage Progression** – Game difficulty increases as the score rises  

---

## 🛠️ Installation & Setup  

### 1️⃣ **Prerequisites**  
Ensure you have a C++ compiler installed:  
- **G++ (for Linux/macOS/WSL):** `sudo apt install g++`  
- **MinGW (for Windows):** Install from [MinGW-w64](https://www.mingw-w64.org/)  

### 2️⃣ **Compilation**  
To compile the game, use the following command:  
```sh
g++ BattleShip.cpp -o BattleShip
```

### 3️⃣ **Running the Game**  
Execute the compiled file:  
```sh
./BattleShip   # For Linux/macOS
BattleShip.exe # For Windows (if using MinGW)
```

---

## 🎯 Controls  

| Key | Action |
|-----|--------|
| `W` | Move Up |
| `S` | Move Down |
| `A` | Move Left |
| `D` | Move Right |
| `Spacebar` | Fire Bullets |

---

## 📜 Code Structure  

The project consists of **modular functions**, each handling a specific aspect of the game.  

### ✈️ **Player & Movement**
- `plane()` – Initializes the player's aircraft  
- `Move(n, health)` – Moves the aircraft based on user input  

### 🎯 **Game Logic**  
- `Game()` – Renders the battlefield and updates the score  
- `generateEnemies()` – Spawns enemy ships at random locations  
- `generateGifts()` – Places power-ups (`+`) on the screen  
- `updateplaneFire()` – Updates player bullets and destroys enemies  
- `updateEnemyFire()` – Moves enemy projectiles downward  
- `updateGifts()` – Detects when the player collects a power-up  

---

## 🏆 Scoring System  

| Action | Points |
|--------|--------|
| Destroying an enemy | +2 points |
| Collecting a power-up | +10 to +20 points |
| Reaching **Stage 2** (Score ≥30) | Increased difficulty |

---

## 📷 Game Preview  
_(You can add a screenshot or ASCII preview of the game interface here.)_  

---

## 🚀 Future Enhancements  

🔹 Advanced AI with strategic enemy movement  
🔹 Multiple levels and enemy ship types  
🔹 High-score leaderboard integration  

---

## 🤝 Contribution  

We welcome contributions! Follow these steps:  
1. **Fork** the repository  
2. **Clone** your fork locally  
3. Create a **new branch** for your feature  
4. Submit a **pull request** for review  

---

## 📝 License  

This project is licensed under the **MIT License** – you are free to use, modify, and distribute it.  

---
