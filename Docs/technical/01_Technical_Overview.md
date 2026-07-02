# Technical Overview

## Engine

Project Blackwood will be developed using Unreal Engine 5.

Primary reasons:
- Strong first-person tools
- Multiplayer support
- Advanced lighting
- Large environment capabilities
- AI framework
- Marketplace resources

---

# Development Goals

The technical architecture should support:
- 1-4 player cooperative gameplay
- Persistent world changes
- Dynamic events
- AI wildlife
- Large outdoor environments
- Future content expansion

---

# Development Philosophy

Systems should be:
- Modular
- Data-driven
- Expandable
- Easy to test

Avoid creating systems that only support one feature.

---

# Core Systems

Project Blackwood will contain:

## Player System

Handles:
- Movement
- Interaction
- Inventory
- Equipment
- Health
- Player states

---

## Interaction System

Handles:
- Picking up objects
- Using tools
- Repairing objects
- Activating equipment

---

## Task System

Handles:
- Ranger assignments
- Objectives
- Rewards
- Completion states

---

## World State System

Tracks:
- Repairs
- Damage
- Events
- Player impact

---

## AI System

Handles:
- Wildlife
- Visitors
- Cryptids
- NPC behavior

---

## Event System

Controls:
- Weather
- Emergencies
- Mystery events
- Cryptid encounters

---

## Multiplayer System

Handles:
- Player replication
- Shared world state
- Team interactions

---

# Save System Goals

The game should save:
- Player progression
- Station upgrades
- Equipment
- Park improvements
- Discovered locations
- Story discoveries

---

# Performance Goals

Target:
- Stable multiplayer gameplay
- Large outdoor environments
- Smooth AI simulation
- Expandable world

---

# Design Rule

Every system should support the feeling of being a park ranger in a living wilderness.
