# Networking Architecture

## Overview

Project Blackwood is designed as a cooperative multiplayer experience supporting 1-4 players.

Networking should prioritize reliability, shared experiences, and cooperative gameplay.

---

# Multiplayer Model

Project Blackwood uses a client-server model.

One player acts as the host.

The host manages:
- World state
- Events
- AI decisions
- Task generation
- Save data

Clients connect to the host and receive synchronized information.

---

# Network Responsibilities

## Server Authority

The server controls:
- World changes
- Task completion
- AI behavior
- Event generation
- Object states

This prevents players from creating conflicting changes.

---

# Replicated Systems

The following systems require replication.

## Player

Replicate:
- Position
- Movement
- Equipment
- Player state
- Actions

---

## World Objects

Replicate:
- Damage states
- Repairs
- Interactions
- Changes

Example:

Player repairs bridge.

All players see:
- Repair animation
- Updated bridge state
- Saved progress

---

## Tasks

Replicate:
- Available tasks
- Task progress
- Completion state
- Rewards

---

## AI

Replicate:
- Creature location
- Behavior states
- Important actions

AI decisions happen on the server.

---

# Shared World Progression

All players share:
- Ranger station
- Park condition
- Unlocks
- Major discoveries

---

# Player Inventory

Player inventories are individual.

Players manage:
- Personal tools
- Equipment
- Supplies

Some resources may be shared.

---

# Communication

Multiplayer communication includes:

## Voice Chat

For player coordination.

---

## Ranger Radio

In-world communication system.

Radio can include:
- Player communication
- Park alerts
- Story events

---

# Connection Handling

The game should handle:
- Player joining
- Player leaving
- Reconnection

---

# Save System

The save belongs to the park.

Saved:
- World state
- Station upgrades
- Discoveries
- Progression

Not saved:
- Temporary player actions

---

# Design Rule

Players should feel like they are in the same park, not separate copies of the world.
