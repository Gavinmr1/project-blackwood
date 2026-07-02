# World State Architecture

## Overview

The World State System manages the current condition of the park.

It tracks changes caused by player actions, environmental events, and progression.

The goal is to create a park that feels persistent and reactive.

---

# World State Responsibilities

The system tracks:
- Environmental condition
- Completed tasks
- Damage states
- Restored locations
- Player discoveries
- Event history
- Unlocked areas

---

# World Objects

Important objects in the park have persistent states.

Examples:
- Bridges
- Signs
- Buildings
- Equipment
- Campsites
- Ranger facilities

---

# Object States

World objects can have different states.

Example:

Bridge:

## Functional

Players can use it.

↓

## Damaged

Players notice the issue.

↓

## Broken

Players must repair it.

↓

## Restored

Object returns to normal.

---

# Persistence

Changes should remain after:
- Leaving the area
- Ending a session
- Restarting the game

Example:

Player repairs a bridge.

The next session:
The bridge is still repaired.

---

# Save Data

The game saves:

## Player Data
- Inventory
- Equipment
- Progression
- Discoveries

---

## Station Data
- Upgrades
- Facilities
- Decorations

---

## World Data
- Repairs
- Damaged objects
- Completed tasks
- Discovered locations

---

## Story Data
- Journal discoveries
- Evidence found
- Events witnessed

---

# Dynamic World Changes

The world can change over time.

Examples:

A storm:
- Breaks signs
- Damages trails
- Causes flooding

Wildlife:
- Moves locations
- Changes behavior

Player actions:
- Restore areas
- Improve park condition

---

# Park Condition

The park has an overall condition value.

Affected by:

Positive:
- Completed maintenance
- Successful rescues
- Environmental care

Negative:
- Neglect
- Fires
- Damage
- Failed events

---

# Condition Effects

High park condition:
- More visitors
- Healthy wildlife
- Stable environment

Low park condition:
- More emergencies
- Reduced resources
- Increased unusual activity

---

# Design Rule

The player should be able to look at the park and see their impact.

The world is a reflection of the player's choices.
