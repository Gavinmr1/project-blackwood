# Gameplay Framework

## Purpose

This document defines how Project Blackwood's major gameplay systems connect.

The goal is to prevent one-off systems and keep the project modular.

---

# High-Level Framework

Player
↓
Interaction Component
↓
Interactable World Object
↓
Task / Repair / Event System
↓
World State
↓
Save System

---

# Core Rule

The player does not directly own the world.

The world owns its state.

The player asks to interact.

World objects decide what happens.

---

# Main Systems

## Player

Responsible for:
- Movement
- Camera
- Input
- Equipment selection
- Health state

Should not contain task logic, repair logic, or save logic.

---

## Interaction Component

Lives on the player.

Responsible for:
- Looking forward from camera
- Detecting interactable objects
- Showing interaction prompt
- Calling the interact function

---

## World Object

Base class for important park objects.

Examples:
- Trail signs
- Bridges
- Doors
- Generators
- Campsites
- Ranger equipment

Responsible for:
- Identity
- State
- Components
- Interfaces

---

## World Object State Component

Tracks persistent state.

Responsible for:
- Object ID
- Current state
- Discovered state
- Damaged/repaired state

---

## Repairable Component

Adds repair behavior.

Responsible for:
- Repair duration
- Repair progress
- Required tool
- Repair completion

---

## Task System

Creates ranger work.

Responsible for:
- Assignments
- Objectives
- Rewards
- Completion checks

---

## Event System

Creates dynamic situations.

Responsible for:
- Weather events
- Emergencies
- Wildlife events
- Mystery events

---

## World State System

Stores the condition of the park.

Responsible for:
- Object states
- Completed repairs
- Park condition
- Discovered locations
- Event history

---

## Save System

Writes and loads persistent data.

Responsible for:
- Player progress
- Station upgrades
- World object states
- Story discoveries

---

# Interaction Flow

Example: Repairing a Trail Sign

1. Player looks at trail sign.
2. Interaction Component detects it.
3. Player presses Interact.
4. Interaction Component calls Interact on the sign.
5. Trail sign checks whether it is repairable.
6. Repairable Component updates repair progress.
7. World Object State Component changes state to Repaired.
8. Task System checks if related task is complete.
9. World State System records the change.
10. Save System persists the result.

---

# Ownership Rules

## Player Owns
- Input
- Movement
- Equipped tool
- Personal inventory
- Health

## World Object Owns
- Its current state
- Whether it can be interacted with
- Which components it has

## Task System Owns
- Active assignments
- Task objectives
- Rewards

## World State Owns
- Persistent park condition
- Object state records
- Global progress

---

# Blueprint Architecture

Preferred pattern:
Actor
+Components
+Interfaces

Avoid:
- Giant Blueprints
- Duplicated logic
- Hardcoded object behavior
- Systems that only work for one object

---

# First Prototype Framework

Prototype 0.1 will include:
- Player
- Interaction Component
- World Object base class
- Broken Trail Sign child class
- Repairable Component
- World Object State Component

Not included yet:
- Save system
- Full task system
- Multiplayer
- AI
- Weather
- Cryptids

---

# Design Rule

Build the smallest version of the system that can grow into the final version.
