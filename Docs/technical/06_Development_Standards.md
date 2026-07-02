# Development Standards

## Overview

This document defines the organization and development practices for Project Blackwood.

The goal is to keep the project maintainable as it grows.

---

# Project Organization

The project should use a modular structure.

Systems should be separated by responsibility.

Avoid placing unrelated logic together.

---

# Unreal Folder Structure

Recommended:

Content/
├── Blueprints/
│   ├── Player/
│   ├── AI/
│   ├── World/
│   ├── Vehicles/
│   └── Items/
│
├── Maps/
│
├── Materials/
│
├── Models/
│
├── UI/
│
├── Audio/
│
├── Effects/
│
└── Data/

---

# Naming Convention

Use descriptive names.

Examples:

Good:
BP_RangerCharacter
BP_Wildlife_Deer
BP_RepairableBridge
DA_TaskDefinition

Bad:
Thing1
TestActor
NewBlueprint

---

# Blueprint Guidelines

Blueprints should handle:
- Gameplay logic
- Prototyping
- Visual scripting

Avoid extremely large blueprints.

Large systems should become reusable components.

---

# C++ Guidelines

C++ should handle:
- Core systems
- Performance sensitive code
- Reusable frameworks

---

# Component Philosophy

Prefer composition over inheritance.

Example:

Instead of:
RangerCharacter
  |
  + RepairRanger
  + FireRanger
  + WildlifeRanger

Use:
RangerCharacter
with:
- RepairComponent
- EquipmentComponent
- RescueComponent

---

# Git Workflow

Use branches:

main
Stable releases.

---

development
Active development.

---

feature/
New systems.

Examples:
feature/task-system
feature/wildlife-ai

---

# Commit Messages

Use descriptive commits.

Examples:

Good:
"Add basic player interaction system"
"Create repair task prototype"

Bad:
"stuff"
"changes"

---

# Design Rule

Every system should be built so it can grow.
