# Blueprint Architecture

## Goal

Project Blackwood should be built from reusable systems, not one-off Blueprints.

Every gameplay object should be easy to extend, save, replicate, and connect to tasks or events.

---

# Core Blueprint Types

## BP_WorldObjectBase

Base class for important objects in the park.

Used for:
- Signs
- Bridges
- Doors
- Campsites
- Generators
- Radio towers
- Repairable structures

Responsibilities:
- Unique object ID
- Object state
- Save support
- Interaction support
- Optional repair/damage support

---

## BPI_Interactable

Interface for anything the player can interact with.

Common functions:
- Interact
- Get Interaction Text
- Can Interact

---

## BPC_Interaction

Player component responsible for detecting and activating interactable objects.

Responsibilities:
- Line trace from camera
- Detect interactable actors
- Show prompt
- Call Interact

---

## BPC_WorldObjectState

Component for persistent world object state.

Tracks:
- Object ID
- Current state
- Is damaged
- Is repaired
- Is discovered

---

## BPC_Repairable

Component for objects that can be repaired.

Tracks:
- Repair progress
- Required tool
- Repair duration
- Reward data

---

# First Architecture Rule

Avoid putting all logic directly inside object Blueprints.

Prefer:
Actor + Components + Interfaces

Example:

BP_BrokenTrailSign

Uses:
- BPC_WorldObjectState
- BPC_Repairable
- BPI_Interactable

---

# Object State Examples

World objects may use states like:
- Unknown
- Functional
- Damaged
- Broken
- Repaired
- Disabled

---

# Design Rule

If multiple objects need the same behavior, that behavior should become a component.
