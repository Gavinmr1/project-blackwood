# Development Philosophy

---

# Purpose

This document explains **how Project Blackwood is developed.**

It is not a list of coding rules.

It is a guide for making development decisions.

When deciding between multiple possible solutions, developers should use the principles in this document.

---

# Principle 1
## Build Systems Before Content

Project Blackwood is built one gameplay loop at a time.

The goal is not to create a large amount of content quickly.

The goal is to create reusable gameplay systems that can support large amounts of content later.

Example:

Bad:

Create twenty different repairable objects.

Good:

Create one repair system that twenty different objects can use.

---

# Principle 2
## Finish Before Expanding

Every feature should be considered complete before beginning another feature.

Example:

Inventory

↓

Equipment

↓

Interaction

↓

Repair Object

↓

Task Progress

↓

Completed

Only after a gameplay loop is complete should additional mechanics be added.

---

# Principle 3
## Reuse Existing Systems

Before creating a new Blueprint, Component, Widget, or C++ class, ask:

Can an existing system solve this problem?

Existing systems should be extended whenever possible.

Duplicated systems create unnecessary maintenance.

---

# Principle 4
## Separate Responsibilities

Every system should own exactly one responsibility.

Examples:

Inventory

Owns items.

Equipment

Owns equipped items.

Task Component

Owns objectives.

HUD

Displays information.

Interaction Component

Finds interactable objects.

Avoid systems that try to perform multiple unrelated jobs.

---

# Principle 5
## Event Graphs Should Be Readable

Blueprint Event Graphs should explain gameplay flow.

Implementation details should be moved into functions.

Example:

Interact

↓

CanRepair()

↓

RepairObject()

Instead of:

Interact

↓

50 Blueprint nodes

↓

Result

The goal is that another developer can understand gameplay flow in a few seconds.

---

# Principle 6
## Data Over Hardcoding

Gameplay values should be stored in Data Assets whenever practical.

Examples:

Item Names

Descriptions

Weights

Meshes

Icons

Balance values

Changing gameplay should not require recompiling code whenever possible.

---

# Principle 7
## Document Every System

Every gameplay feature should be documented.

Documentation is considered part of development.

If another developer cannot understand how a system works without reading source code, the documentation should be improved.

---

# Principle 8
## Prototype First

Do not attempt to build the final version immediately.

Start with:

Working

↓

Reliable

↓

Reusable

↓

Polished

Prototype gameplay first.

Improve presentation later.

---

# Principle 9
## Avoid Feature Creep

Project Blackwood contains many long-term ideas.

Only build features that support the current milestone.

Future ideas should be documented rather than immediately implemented.

---

# Principle 10
## Teach, Don't Memorize

Project Blackwood is also a learning project.

Developers should understand why a system exists, not only how to build it.

Every major system should include explanations describing the architectural reasoning behind the implementation.
