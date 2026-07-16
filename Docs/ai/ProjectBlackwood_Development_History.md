# Project Blackwood Development History

Version: 0.1

---

# Purpose

This document preserves the reasoning behind Project Blackwood.

Technical architecture explains how systems work.

This document explains why they exist.

It should be read by:

- future developers
- AI assistants
- contractors
- new teammates

before major development begins.

---

# The Beginning

Project Blackwood did not begin as an attempt to build a giant open world.

It began as an attempt to build believable ranger gameplay.

The player should enjoy being a park ranger before anything supernatural happens.

The world should feel relaxing, authentic, and lived in.

Only after the player becomes comfortable should strange events slowly begin appearing.

---

# The Desired Feeling

Project Blackwood should create this emotional progression.

Comfort

↓

Routine

↓

Curiosity

↓

Unease

↓

Fear

↓

Discovery

↓

Understanding

↓

Choice

The horror should feel earned.

---

# Development Philosophy

The project intentionally avoids feature creep.

Every completed gameplay loop is more valuable than ten unfinished systems.

Whenever choosing between:

- making something larger

or

- making something better

the answer should almost always be:

Make it better.

---

# Vertical Slice First

The first goal is NOT an entire national park.

The first goal is one excellent ranger station.

One trail.

One repair task.

One believable environment.

Everything else grows from that.

---

# Modular Architecture

Every system should do one job.

Inventory owns inventory.

Equipment owns equipped items.

Tasks own progression.

Interaction starts interactions.

Widgets display information.

Whenever responsibilities become mixed, refactor before adding features.

---

# Blueprint Philosophy

Blueprint Event Graphs should read almost like English.

Bad:

Interact

↓

40 nodes

↓

Done

Good:

Interact

↓

CanRepair()

↓

RepairSign()

↓

AwardTaskProgress()

Large logic belongs inside functions.

---

# Teaching Philosophy

The project lead prefers explicit step-by-step instruction.

Future AI assistants should avoid assuming prior Unreal Engine knowledge.

Every instruction should explain:

What

Why

How

Expected Result

How To Test

---

# Long-Term Vision

Project Blackwood has very large ambitions.

Possible future systems include:

vehicle repair

wildlife tracking

medical crafting

building ranger stations

fire management

dynamic weather

survival mechanics

multiplayer

park management

story investigation

However...

None of these should be implemented until they support the current milestone.

Ideas should be documented instead of immediately built.

---

# Team Philosophy

Every developer should own a clear area.

Architecture should have one owner.

World building should have one owner.

Art should have one owner.

Audio should have one owner.

This prevents conflicting decisions.

---

# AI Philosophy

AI is treated as a senior development partner.

It should challenge decisions when appropriate.

It should recommend smaller solutions before larger ones.

It should prefer maintainability over cleverness.

It should preserve architecture.

It should explain reasoning.

It should never introduce unnecessary complexity simply because it is technically possible.

---

# Current State

The project now contains:

working interaction system

working inventory

working equipment

working task progression

repair gameplay loop

modular Blueprint organization

modular C++ components

early documentation

AI onboarding

developer onboarding

The next milestone is building the first believable ranger station gameplay slice.