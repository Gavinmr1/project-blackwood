# Project Blackwood Master Context

Version: 1.0

---

# Purpose

This document is the single source of truth for understanding Project Blackwood.

Every developer, designer, artist, writer, audio designer, tester, and AI assistant should read this document before contributing to the project.

It explains:

- what Project Blackwood is,
- why it is being built,
- how development decisions are made,
- how the team is organized,
- what the current milestone is,
- and how all major systems fit together.

Detailed implementation belongs in the other documents within the `Docs` folder.

This document exists to provide the complete mental model of the project.

---

# Vision

Project Blackwood is a first-person cooperative park ranger simulation set inside a large national park where ordinary ranger work slowly gives way to mystery and supernatural horror.

The player should first enjoy simply being a ranger.

They patrol trails.

Repair signs.

Maintain campsites.

Help lost hikers.

Observe wildlife.

Respond to emergencies.

Explore forests.

Learn the park.

Only after the player feels comfortable inside this believable world should strange events begin to appear.

Project Blackwood is not built around constant combat.

It is built around immersion.

The world itself is the main character.

---

# Core Design Philosophy

Every design decision should support these principles.

## 1. Believability before Horror

The park must feel like a real place before anything supernatural happens.

Routine creates contrast.

Contrast creates fear.

## 2. Small Finished Systems Beat Large Unfinished Systems

A complete repair system is more valuable than five partially finished mechanics.

Finish gameplay loops before expanding the project.

## 3. Modular Architecture

Every gameplay system owns one responsibility.

Inventory stores items.

Equipment tracks equipped gear.

Tasks track progression.

Interaction begins interactions.

Widgets display information.

Avoid mixing responsibilities.

## 4. Expand Through Existing Systems

Whenever adding a feature, first ask:

> Can an existing system support this?

If yes:

Extend it.

Do not create unnecessary new systems.

## 5. Future-Proof Without Overbuilding

The project has ambitious long-term goals, but development focuses only on what supports the current milestone.

Ideas are documented before they are implemented.

---

# Current Development Goal

The current milestone is to build the first polished vertical slice.

The player should be able to:

- receive a ranger task,
- collect the required tool,
- manage inventory,
- equip the correct tool,
- travel into the world,
- repair an object,
- receive task completion,
- return to the ranger station.

Everything currently being developed should support this experience.

Features that do not improve this gameplay loop should generally be postponed.

---

# The Player Experience

Project Blackwood should create the following emotional progression:

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

The supernatural elements should always feel earned.

The player's knowledge of the world should become their greatest source of tension.

---

# Team Philosophy

Project Blackwood is developed through clear ownership.

Each contributor owns a defined area of responsibility.

The Project Lead owns:

- gameplay systems,
- architecture,
- C++,
- Blueprint framework,
- core mechanics,
- technical decisions.

The World Developer owns:

- environments,
- world layout,
- level dressing,
- lighting,
- environmental audio,
- approved content creation,
- documentation,
- playtesting.

Specialists should improve their own area without unintentionally changing another developer's systems.

---

# AI Philosophy

AI is considered a development partner.

Its role is to:

- explain,
- teach,
- review,
- document,
- improve maintainability,
- preserve architecture.

AI should never increase project scope simply because something is technically possible.

It should recommend the smallest solution that supports the current milestone.

When multiple solutions exist, prefer the one that future developers will understand most easily.

---

# Living Document

This document evolves with the project.

Whenever a major architectural decision or milestone changes, update this document before beginning new development.

It should always represent the current direction of Project Blackwood.