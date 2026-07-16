# Project Blackwood — Current Project State

Version: 0.1

---

# Purpose

This document records the current state of Project Blackwood.

It should answer four questions:

1. What currently works?
2. What is being worked on now?
3. What should happen next?
4. What should not be worked on yet?

Update this document whenever a milestone is completed or the project’s immediate priorities change.

---

# Current Milestone

## Ranger Station Vertical Slice

The current goal is to turn the working repair prototype into a small, understandable playable experience centered around a ranger station.

The vertical slice should eventually allow the player to:

1. Begin at a ranger station.
2. Receive or view a ranger task.
3. Locate the required repair tool.
4. Pick up the repair tool.
5. Open the Backpack.
6. Select and equip the repair tool.
7. Follow a short trail.
8. Repair a broken trail sign.
9. See task progress update.
10. Reach a clear completion state.

The current milestone is intentionally small.

Do not expand into a large open world during this phase.

---

# Completed Systems

## Interaction System

Current status: Working

The player can:

- Look at an interactable object.
- Trigger an interaction.
- Pass the interacting actor to the target object.
- Use the shared Blackwood interaction interface.

The interaction system starts interactions but does not own object-specific gameplay behavior.

---

## Item Definition System

Current status: Working

Items are defined through `UBlackwoodItemDefinition` Primary Data Assets.

Current item data includes:

- Item ID.
- Display name.
- Description.
- Item type.
- Equip eligibility.
- Maximum stack size.
- Weight.
- World mesh.
- Equipped mesh.

---

## Inventory System

Current status: Working

The inventory can:

- Add items.
- Remove items.
- Stack matching items.
- Check whether an item is owned.
- Return item quantities.
- Expose stored items to Blueprint and UI.

The Inventory Component owns what the player carries.

It does not own equipped state.

---

## Equipment System

Current status: Working foundation

The equipment system can:

- Equip an item.
- Unequip an item.
- Track the currently equipped item.
- Track the equipped primary tool.
- Return the equipped mesh.
- Expose equipped state to Blueprint.

The Equipment Component owns what the player is currently using.

---

## Task System

Current status: Working

The task system can:

- Set an active task.
- Track current progress.
- Clamp progress to the target.
- Determine when a task is complete.
- Broadcast task updates.
- Update the HUD through an event-driven flow.

The current prototype task is repairing the trail sign.

---

## Backpack and Loadout UI

Current status: Working prototype

The interface currently supports:

- Opening with Tab.
- Closing with Tab or Escape.
- Mouse cursor and input-mode switching.
- Displaying inventory items dynamically.
- Selecting an inventory item.
- Displaying the selected item’s name and description.
- Equipping the selected item.
- Displaying the equipped primary tool in the Loadout.
- Refreshing Backpack and Loadout information when opened.

The interface currently uses placeholder visuals and text styling.

---

## Broken Trail Sign

Current status: Working

The trail sign:

- Checks whether it has already been repaired.
- Checks whether the repair tool is equipped.
- Refuses repair when the correct tool is not equipped.
- Changes its repaired state.
- Changes its visual rotation.
- Adds task progress.
- Prevents progress from being awarded more than once.

Its Event Graph has been cleaned into readable gameplay flow using:

- `CanRepair`
- `RepairSign`

---

# Current Playable Loop

The current working loop is:

```text
Find Repair Tool
    ↓
Pick Up Repair Tool
    ↓
Open Backpack
    ↓
Select Repair Tool
    ↓
Equip Repair Tool
    ↓
Loadout Updates
    ↓
Interact With Broken Trail Sign
    ↓
Sign Checks Equipped Tool
    ↓
Repair Sign
    ↓
Task Progress Updates

## Current Milestone

Completed the first version of the equipment framework.

Implemented:

- Item Definitions
- Inventory Component
- Equipment Component
- Equip / Unequip
- Equipped mesh spawning
- Hand socket attachment
- Inventory UI integration
- Loadout display
- Animation state for equipped items (placeholder)

Known TODOs:

- Replace placeholder equipped animation.
- Create proper tool meshes.
- Add additional equipment slots.