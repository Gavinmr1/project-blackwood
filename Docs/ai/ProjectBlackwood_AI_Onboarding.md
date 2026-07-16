# Project Blackwood — AI Onboarding

Version: 0.1  
Audience: AI assistants helping the World Developer  
Project Lead: Gavin Riggs

---

# Instructions for the AI Assistant

You are assisting a beginner developer working on Project Blackwood.

The developer has extensive experience playing games but has little or no programming, Unreal Engine, level-design, or source-control experience.

Your job is to:

- Teach one manageable step at a time.
- Give explicit instructions about where to click and what to name things.
- Explain unfamiliar Unreal Engine terminology.
- Confirm the developer’s current result before moving forward.
- Preserve the project’s existing architecture and standards.
- Keep the developer focused on their assigned role.
- Avoid introducing unnecessary systems or redesigning the project.
- Prefer small, testable, reversible tasks.
- Remind the developer to compile, save, test, and commit at appropriate checkpoints.
- Ask for screenshots when visual confirmation would prevent confusion.
- Clearly distinguish white Blueprint execution wires from colored data wires.
- Never claim that a graph or asset is correct unless the available information supports that conclusion.

Do not overwhelm the developer with a large sequence of advanced steps. Break complicated work into smaller checkpoints.

When recommending changes, explain:

1. What the developer is doing.
2. Why the project needs it.
3. Which asset or folder it belongs in.
4. What successful completion should look like.
5. How to test it safely.

---

# Project Overview

Project Blackwood is a first-person cooperative park-ranger simulation that gradually develops into a supernatural mystery and horror experience.

The player begins with believable ranger work:

- Maintaining trails and park infrastructure.
- Repairing signs and equipment.
- Cleaning campsites.
- Observing wildlife.
- Helping hikers.
- Preventing and responding to fires.
- Investigating reports and unusual events.

Supernatural events should appear gradually.

The intended progression is:

1. Routine.
2. Uncertainty.
3. Mystery.
4. Horror.

Project Blackwood is a grounded simulation first. It is not primarily an action game.

---

# Current Scope Philosophy

Project Blackwood has large long-term ambitions, but development must remain controlled.

Do not attempt to build the final open-world game immediately.

The current goal is a small, functional, polished playable slice.

Prefer:

- One finished ranger station over several unfinished locations.
- One working trail over a huge empty landscape.
- One polished campsite over twenty placeholder campsites.
- One complete gameplay loop over many incomplete mechanics.

Future ideas should be documented rather than implemented unless they support the current milestone.

---

# Current Playable Loop

The current prototype supports this loop:

1. The player receives a repair objective.
2. The player finds a repair tool.
3. The player picks up the repair tool.
4. The repair tool appears in the Backpack.
5. The player selects and equips it.
6. The equipped tool appears in the Loadout.
7. The player interacts with a broken trail sign.
8. The sign verifies that the repair tool is equipped.
9. The sign becomes repaired.
10. Task progress updates on the HUD.

This working loop is the reference example for how Project Blackwood systems communicate.

---

# Existing Core Systems

The following systems already exist and must be preserved.

## Interaction System

Purpose:

- Detect the object the player is looking at.
- Call the project’s interaction interface.
- Start an interaction without knowing what the target object does.

The Interaction Component should not contain object-specific gameplay logic.

## Inventory System

Purpose:

- Store physical items owned by the player.
- Add, remove, stack, and query items.
- Provide inventory data to the Backpack UI.

Inventory answers:

> What does the player own?

Inventory does not own equipped state.

## Equipment System

Purpose:

- Track currently equipped items.
- Track the primary tool.
- Provide the equipped item and mesh.

Equipment answers:

> What is the player currently using?

Do not move equipped-state ownership back into the Inventory Component.

## Task System

Purpose:

- Store the active task.
- Track progress.
- Determine completion.
- Broadcast task updates to the HUD.

## User Interface

Current UI includes:

- Objective HUD.
- Backpack.
- Loadout.
- Selected-item details.
- Inventory open and close behavior.
- Mouse and input-mode handling.

The UI displays gameplay state. It must not become the authoritative owner of gameplay state.

## Item Definitions

Items use `UBlackwoodItemDefinition` Primary Data Assets.

Item definitions currently support information such as:

- Item ID.
- Display name.
- Description.
- Item type.
- Whether the item can be equipped.
- Maximum stack size.
- Weight.
- World mesh.
- Equipped mesh.

Prefer Data Assets over hardcoded item-specific logic.

---

# Development Architecture

Project Blackwood favors this pattern:

```text
Data Asset
    ↓
Gameplay Component
    ↓
Blueprint Assembly
    ↓
Widget or World Feedback