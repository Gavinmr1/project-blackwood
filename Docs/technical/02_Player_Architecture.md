# Player Architecture

Version 1.0

---

# Purpose

This document describes how the player is constructed.

The player should be viewed as a collection of independent gameplay systems rather than one large Blueprint.

Each system has a single responsibility.

This architecture allows Project Blackwood to grow without creating an overly complex player Blueprint.

---

# High-Level Architecture

Player Character

│

├── Camera

├── Movement

├── Interaction Component

├── Inventory Component

├── Equipment Component

├── Task Component

├── UI

└── Future Components

---

# Current Components

## Interaction Component

Purpose

Detects objects the player can interact with.

Responsibilities

- Performs interaction traces
- Finds interactable objects
- Calls the interaction interface
- Does not contain gameplay logic

The interaction component should never know what an object actually does.

It only starts the interaction.

---

## Inventory Component

Purpose

Stores every item owned by the player.

Responsibilities

- Add items
- Remove items
- Stack items
- Query item quantities

The Inventory Component owns player possessions.

It does not know what is equipped.

---

## Equipment Component

Purpose

Tracks which items are currently equipped.

Responsibilities

- Equip tools
- Unequip tools
- Report equipped items
- Provide equipped meshes

The Equipment Component owns player loadout.

It does not own inventory.

Inventory and Equipment remain separate systems.

---

## Task Component

Purpose

Tracks player objectives.

Responsibilities

- Current tasks
- Progress
- Completion
- Objective updates

Tasks should never directly modify gameplay systems.

Instead they observe gameplay events.

---

## User Interface

Purpose

Display gameplay information.

Responsibilities

- Backpack
- Loadout
- Item Details
- Task Tracker
- Interaction Prompts

UI should display gameplay state.

It should never own gameplay state.

---

# Current Gameplay Loop

Current prototype

Explore

↓

Find Repair Tool

↓

Interact

↓

Inventory

↓

Equip Tool

↓

Repair Trail Sign

↓

Task Progress

↓

Complete Objective

Future gameplay loops should extend this pattern instead of replacing it.

---

# Future Components

The following systems are planned but not yet implemented.

Health Component

Stamina Component

Radio Component

Notebook Component

Quest Component

Save Component

Audio Component

Vehicle Component

Multiplayer Component

None of these systems should be added to the player until they have a clearly defined responsibility.

---

# Architectural Rules

Every component should answer one question.

Interaction

"What is the player looking at?"

Inventory

"What does the player own?"

Equipment

"What is the player using?"

Tasks

"What is the player trying to accomplish?"

UI

"What should the player currently see?"

Whenever a component begins answering multiple questions, consider splitting it into separate components.

---

# Philosophy

The player should become simpler over time, not more complicated.

New gameplay systems should usually become new Components rather than expanding the player Blueprint.

The player Blueprint should primarily coordinate systems instead of implementing gameplay itself.