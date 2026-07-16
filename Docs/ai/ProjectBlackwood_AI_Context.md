# Project Blackwood
## AI Context Document

Version: 0.1

---

# Purpose

This document provides the architectural context for AI assistants working on Project Blackwood.

Its purpose is to ensure every AI assistant gives guidance that aligns with the project's long-term vision, architecture, and development philosophy.

This document should be provided to every new AI conversation before requesting programming or design assistance.

---

# About Project Blackwood

Project Blackwood is a first-person cooperative park ranger simulation with survival, mystery, horror, and progression mechanics.

The game begins as a realistic park ranger simulator.

Players perform routine ranger duties including:

- Repairing trails
- Cleaning campsites
- Maintaining equipment
- Assisting lost hikers
- Wildlife observation
- Fire prevention

As the game progresses, increasingly strange events begin occurring.

The supernatural elements are intentionally introduced slowly.

Routine comes first.

Mystery comes second.

Horror comes last.

The player should constantly question whether events have logical explanations before discovering the truth.

Project Blackwood is not an action game.

It is a simulation game first.

---

# Design Philosophy

Every gameplay mechanic should support three goals.

## 1. Immersion

Whenever possible, gameplay should feel believable.

Menus should represent physical objects.

Examples:

Inventory = Backpack

Notebook = Field Journal

Objectives = Ranger Tasks

Map = Paper Map

Avoid abstract game mechanics when immersive alternatives exist.

---

## 2. Systems Before Content

New gameplay systems are developed before large amounts of content.

One completed gameplay loop is preferred over ten incomplete systems.

Avoid feature creep.

Finish systems before expanding them.

---

## 3. Reusable Architecture

Avoid creating one-off Blueprints or C++ classes.

Extend existing systems whenever possible.

Every new mechanic should be evaluated for reuse by future gameplay features.

---

# Current Gameplay Loop

The current prototype gameplay loop is:

Find Repair Tool

↓

Pick Up Repair Tool

↓

Open Backpack

↓

Equip Repair Tool

↓

Repair Broken Trail Sign

↓

Complete Task

This gameplay loop serves as the architectural foundation for future gameplay systems.

---

# Core Systems

The following systems currently exist.

Interaction System

Inventory System

Equipment System

Task System

HUD System

World Object System

These systems should be extended instead of replaced.

---

# Inventory Philosophy

Inventory and Equipment are intentionally separate systems.

Inventory answers:

"What does the player own?"

Equipment answers:

"What is the player currently using?"

Do not combine these systems.

Future gameplay depends on this separation.

---

# Blueprint Philosophy

Blueprints should remain small and readable.

When Blueprint graphs become difficult to understand:

Create Functions.

Create Components.

Reuse existing logic.

Avoid long execution chains inside Event Graphs.

The Event Graph should describe gameplay flow, not implementation details.

---

# C++ Philosophy

Use C++ for:

Core systems

Reusable gameplay logic

Data structures

Components

Use Blueprints for:

UI

Level scripting

Animation

Visual effects

Simple gameplay assembly

Avoid placing complex gameplay logic directly inside Blueprints.

---

# Data Assets

Gameplay items should be defined using Data Assets whenever possible.

Avoid hardcoding gameplay values.

Item names

Descriptions

Meshes

Weights

Icons

Future balancing should occur through Data Assets rather than code.

---

# User Interface Philosophy

UI should communicate gameplay state clearly.

Every player action should produce visible feedback.

Examples:

Equipping an item updates the Loadout.

Completing a task updates the HUD.

Repairing an object changes the world.

Players should never wonder whether an action succeeded.

---

# Documentation Philosophy

Every completed gameplay feature should also update the documentation.

Documentation is considered part of the feature.

A feature is not complete until:

The code works.

The documentation is updated.

---

# AI Responsibilities

An AI assistant working on Project Blackwood should:

Preserve existing architecture.

Avoid unnecessary redesigns.

Prefer extending existing systems.

Explain why changes are recommended.

Avoid introducing temporary solutions.

Teach the developer instead of simply providing code.

Favor maintainability over speed.

Help keep the project organized.
