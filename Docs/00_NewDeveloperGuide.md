# Project Blackwood
## New Developer Guide

---

# Welcome

Welcome to Project Blackwood.

This guide will walk you through setting up your computer, downloading the project, building it, and verifying that everything is working correctly.

You do **not** need previous Unreal Engine experience.

Follow each step exactly.

If something doesn't work, stop and ask before continuing.

---

# Goals

By the end of this guide you will be able to:

- Open the project
- Build the project
- Launch Unreal Engine
- Play the prototype
- Open the inventory
- Equip the repair tool
- Repair the trail sign

If you can complete all of those tasks, your development environment is correctly configured.

---

# Required Software

This project requires:

- Epic Games Launcher
- Unreal Engine 5.8
- Visual Studio 2022 Community
- Git
- Git LFS
- VS Code (recommended)

Installation instructions are below.

# Installing Unreal Engine

## Step 1 - Install Epic Games Launcher

1. Open your web browser.

2. Navigate to:

https://www.epicgames.com/

3. Download and install the Epic Games Launcher.

4. Sign in with your Epic Games account.

If you do not already have an Epic Games account, create one before continuing.

---

## Step 2 - Install Unreal Engine

1. Open the Epic Games Launcher.

2. Select **Unreal Engine** from the left sidebar.

3. Open the **Library** tab.

4. Press the **+ Add Versions** button.

5. Install **Unreal Engine 5.8**.

> **Important**
>
> Project Blackwood is currently developed using Unreal Engine **5.8**.
> Using a different engine version may cause compatibility issues.

The installation may take a significant amount of time depending on your internet connection.

---

## Step 3 - Launch Unreal Engine

After installation finishes:

1. Launch Unreal Engine 5.8.

2. Wait for the editor to finish compiling shaders.

3. Close Unreal Engine.

This verifies that the engine installed successfully before downloading Project Blackwood.

# Installing Visual Studio

## Step 1 - Download Visual Studio

Download Visual Studio Community 2022 from Microsoft's website.

The Community edition is free and is the version used by the Project Blackwood team.

---

## Step 2 - Install Required Workloads

During installation, select the following workloads:

- Desktop development with C++
- Game development with C++

These workloads install everything required to compile Unreal Engine C++ projects.

---

## Step 3 - Required Components

Verify the following components are installed:

- MSVC Build Tools (Latest)
- Windows 11 SDK
- CMake Tools
- Address Sanitizer

If any of these components are missing, Project Blackwood may fail to compile.

---

## Step 4 - Verify Installation

Launch Visual Studio.

Open the Visual Studio Installer.

Select **Modify**.

Confirm that both required workloads remain checked.

Close Visual Studio.

# Installing Git

## Step 1 - Install Git

Download Git from:

https://git-scm.com/

Install using the default settings unless instructed otherwise.

---

## Step 2 - Install Git LFS

Project Blackwood uses Git Large File Storage (Git LFS).

After Git finishes installing, open a terminal and run:

```bash
git lfs install
```

This only needs to be done once per computer.

---

## Step 3 - Verify Git

Open a terminal.

Run:

```bash
git --version
```

Then run:

```bash
git lfs version
```

If both commands return a version number, Git has been installed correctly.

# Downloading Project Blackwood

## Step 1 - Accept the Repository Invitation

Before downloading the project, verify that you have been added to the Project Blackwood GitHub repository.

If you cannot see the repository on GitHub, contact the project owner before continuing.

---

## Step 2 - Clone the Repository

Open a terminal.

Navigate to the folder where you want to store the project.

Run:

```bash
git clone <Repository URL>
```

Replace `<Repository URL>` with the GitHub repository URL provided by the project owner.

After the clone completes, navigate into the project folder:

```bash
cd ProjectBlackwood
```

---

## Step 3 - Verify the Project Structure

Your project folder should contain folders similar to the following:

```
ProjectBlackwood/
│
├── Config
├── Content
├── Docs
├── Source
├── .gitignore
├── ProjectBlackwood.uproject
└── ProjectBlackwood.sln
```

If any of these folders are missing, the repository may not have downloaded correctly.

---

## Step 4 - Open the Project Folder

Open the project folder in Visual Studio Code.

Verify that the folder structure matches the layout shown above.

Do not modify files until the project has been built successfully.

# Building the Project

## Step 1 - Generate the Solution (If Needed)

If `ProjectBlackwood.sln` is not present:

1. Right-click `ProjectBlackwood.uproject`.
2. Select **Generate Visual Studio Project Files**.

If the solution file already exists, skip this step.

---

## Step 2 - Open Visual Studio

Double-click:

```
ProjectBlackwood.sln
```

Visual Studio should open and begin indexing the project.

Allow it to finish before attempting to build.

---

## Step 3 - Select the Correct Configuration

At the top of Visual Studio, verify the following:

Configuration:

```
Development Editor
```

Platform:

```
Win64
```

These settings are required for Unreal Engine development.

---

## Step 4 - Build the Project

Select:

Build → Build Solution

or press:

```
Ctrl + Shift + B
```

The first build may take several minutes.

Wait for the build to complete before continuing.

---

## Step 5 - Verify the Build

The build is successful when Visual Studio reports:

```
Build succeeded.
```

If the build fails, stop and review the **Common Problems** section at the end of this document before making changes.

# Opening Project Blackwood

## Step 1 - Launch Unreal Engine

Open:

```
ProjectBlackwood.uproject
```

Unreal Engine 5.8 should launch automatically.

If Unreal asks to rebuild the project, choose:

```
Yes
```

Allow Unreal Engine to finish loading completely before continuing.

The first launch after a clean build may take several minutes.

---

## Step 2 - Verify the Project Opens

When Unreal finishes loading, verify the following:

- No compile errors are displayed.
- The project opens successfully.
- The Content Browser is visible.
- The World Outliner is visible.
- The project can enter Play Mode.

If any of these checks fail, stop and resolve the issue before continuing.

---

## Step 3 - Launch the Prototype

Open the prototype level if it is not already loaded.

Press:

```
Play
```

Verify that the player spawns correctly and can move around the world.

# Development Verification

The following checklist verifies that your development environment is fully functional.

Complete each step in order.

---

## Gameplay Checklist

☐ Launch Project Blackwood

☐ Enter Play Mode

☐ Move the player

☐ Locate the Repair Tool

☐ Pick up the Repair Tool

☐ Open the Inventory (Tab)

☐ Verify the Repair Tool appears in the Backpack

☐ Select the Repair Tool

☐ Verify the Details panel updates

☐ Equip the Repair Tool

☐ Verify the Loadout updates

☐ Locate the Broken Trail Sign

☐ Repair the Trail Sign

☐ Verify the task progresses

☐ Attempt to repair the sign again

☐ Verify the message:

"This sign is already repaired."

appears.

---

If every item above works correctly, your development environment has been configured successfully.

# Before You Start Developing

Before beginning work on Project Blackwood, every developer should understand the following principles.

---

## Build Small

Do not attempt to build large systems all at once.

Project Blackwood is intentionally developed one gameplay loop at a time.

Small, finished systems are preferred over large unfinished systems.

---

## Reuse Existing Systems

Before creating a new Blueprint, Component, or C++ class, check whether an existing system already provides the required functionality.

Extending existing systems is almost always preferred over duplicating them.

---

## Ask Questions

If something is unclear, ask before making architectural changes.

Maintaining a consistent architecture is more important than implementing features quickly.

---

## Document Your Work

If you add a new gameplay system, update the documentation so the next developer understands how it works.

Documentation is considered part of the feature.

A feature is not complete until both the code and the documentation are finished.

# Common Problems

## Unreal Engine opens the project but Blueprints fail to compile

Verify that the C++ project builds successfully inside Visual Studio before opening Unreal Engine.

---

## The project will not build

Verify:

- Visual Studio 2022 is installed.
- Desktop Development with C++ is installed.
- Game Development with C++ is installed.
- Windows SDK is installed.

---

## Missing Git LFS files

Run:

```bash
git lfs pull
```

Then reopen the project.

---

## Build errors after pulling changes

Close Unreal Engine.

Rebuild the solution inside Visual Studio.

Reopen Unreal Engine.

---

## Unsure how something works

Read the documentation inside the `Docs` folder before creating new systems.

If the documentation does not answer your question, ask the project lead before changing the architecture.