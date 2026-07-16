# Player Architecture

## Overview

The player system represents the park ranger character.

Players should feel like capable but realistic humans working in a wilderness environment.

The player system must support:
- Movement
- Interaction
- Equipment
- Inventory
- Tools
- Health
- Multiplayer replication

---

# Player Character

The player is represented by a Ranger Character.

Responsibilities:
- First-person camera
- Movement
- Looking
- Jumping
- Sprinting
- Interaction detection
- Equipment handling

The character should not contain all gameplay logic.

Complex systems should be separated into components.

---

# Component Design

The player should use modular components.

Example:

Ranger Character

Contains:
- Movement Component
- Interaction Component
- Inventory Component
- Equipment Component
- Health Component
- Communication Component

---

# Movement System

Supports:
- Walking
- Sprinting
- Crouching
- Jumping
- Swimming
- Climbing (future)

Movement should prioritize immersion.

The ranger is not a superhero.

---

# Interaction System

The interaction system allows players to interact with the world.

Examples:
- Open doors
- Pick up objects
- Repair equipment
- Use tools
- Read journals
- Activate devices

Interactions should use a common interface.

---

# Equipment System

Equipment represents ranger tools.

Examples:

## Starting Tools
- Flashlight
- Radio
- First aid kit
- Repair tools

---

## Advanced Tools
- Camera
- Tracking equipment
- Drone
- Fire equipment
- Rescue gear

---

# Inventory

Inventory should be realistic.

The player has limited carrying capacity.

Equipment decisions matter.

Example:

Bring:
- Fire extinguisher

or:
- Medical supplies

Players must prepare for situations.

---

# Tool Usage

Tools should have meaningful actions.

Examples:

Hammer:
- Repair structures

Chainsaw:
- Remove fallen trees

Radio:
- Communicate

Camera:
- Document evidence

---

# Health System

Players can become injured.

Possible conditions:
- Minor injuries
- Exhaustion
- Environmental hazards

Players recover through:
- First aid
- Rest
- Station resources

---

# Player States

Possible states:
- Healthy
- Injured
- Exhausted
- Downed
- Rescued

---

# Multiplayer Requirements

Player systems must support:
- Network replication
- Shared interactions
- Player visibility
- Equipment synchronization

---

# Design Rule

The player should feel like a trained ranger, not a combat character.

Tools solve problems.

Not weapons.
