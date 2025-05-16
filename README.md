# Drone Simulation Project – Unreal Developer Task

This project was developed as part of a technical assessment for a Drone Simulation assignment using Unreal Engine 5. It demonstrates a fully controllable flying drone with realistic physics, collision handling, and a scoring system.

---

##  Mesh Source

**Model:** [Drone by DennisFan on Fab (Epic Games)](https://fab.com/listings/16440e92-9585-4809-a66d-35e8df760104)  
**Format Used:** `.gltf`

### Import Process:
- Adjusted axis orientation and pivot placement
- Scaled appropriately for gameplay
- Materials lightly optimized to match UE5 PBR setup

---

##  Physics Implementation

- **Blueprints:** Used for drone behavior and movement
- **Floating Pawn Movement:** Enabled physics-based flying with lift and directional control
- **Collision:** Box Collision for physical objects and Trigger Boxes for scoring portals
- **Input Mapping:**
  - `W/A/S/D`: Move
  - `Space`: Ascend
  - `Left Ctrl`: Descend
  - `Left Shift`: Speed Boost

---

##  Scoring System

- Written in **C++**
- Each loop/waypoint has a trigger volume
- Overlap begins score increment only once per portal using a boolean guard
- Win condition checked after final waypoint

##  Development Tools
Blueprint:

Movement (FloatingPawnMovement)

Input handling

Drone tilt using RInterpTo

C++:

Overlap detection

Score tracking

Win condition

## Challenges & Solutions
Drone Tilt Instability:
Resolved with FRotator::RInterpTo for smooth directional control

Falling Through Floor:
Fixed collision settings and mesh pivot alignment

UE5 Data Layer Packaging Error:
Removed unused layers and stripped editor-only content for clean packaging

## Final Submission Includes
Unreal Engine Project (.uproject)

Windows Packaged Build

C++ Source Code

Drone Blueprint System

Instructional Documentation

## Controls
Key	Action
W / A / S / D	Move
Space	Ascend
Left Ctrl	Descend
Left Shift	Boost Speed

## Gameplay Objective
Fly the drone through the loop checkpoints to increase your score. The game ends when all waypoints are cleared. The drone must avoid collisions and fly with precision.

## Future Improvements
Add multiplayer racing mode

Integrate login and leaderboard system

Enhance UI feedback and VFX