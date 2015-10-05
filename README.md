# CSE
hons work. Character Simulation Engine. using sfml & c++

The largest solo project I have worked on, CSE is a project that uses GOAP in conjuction with a personality model to detemine how NPC characters will act.

For the project a specific story scenario was written in which the characters can act.
This was the classic tale of Little Red Riding Hood.

Since the project is large and somewhat complicated I will describe it in sections.

# Actors
First, I will mention actors, there is the player actor, NPC actors and a Drama Manager.
All the types of actors inherit from the abstract actor class.
All types of actors plan actions, and if they are still okay to perform they will then do so.

To begin I will cover the Player actor, the player's avatar in the game world, this character actions are decided by how the player controlling them tells them how to act.
The actions that the player has available at a given time are decided by the context of the scenario by adding or removing them from the pool of available actions as the situation changes.

Next is the NPC actors, then non-player characters that inhabit the setting.
These are the most interesting of all the actors and they have the most going on.
One key distinction is the personality model that they use to determine their plan their actions.
Both of these (personality & planning) I will describe later.

The Drama Manager is indeed an actor, though it may not be as obvious as the NPCs or indeed the player's character, it operates in the same fashion, preforming action and observing the action of other actors.
The Drama Manager could be thought of as 'Fate' setting events in motion or nudging events back on track.
In the scenario I made it doesn't often interfere, but when it does it is for something important.

#Actions
The actors are capable of performing actions to affect the world.
Each action has a subject, the entity performing the action, and many have an object (to which they are directed).

Actions have conditions and effects, the circumstances under which they can occur and how they effect the world.
These conditions and effects will also be importnat when we look at how NPCs plan to do an action.

Actions also have something called 'inclination', how inclined the NPC will be to perform the action, again this will be important when we look at planning.
Many actions inclination is calculated using the personality traits of the NPC.
A simple example would be an aggresive character would be more inclined to perform a punch action than a timid character.

The way in which actions get performed is in the main engine loop, which operates in a turn-based manner.
Each cycle, the plans of actors is checked and if the action is okay to perform it's consequences occur, then the action is added to the history book (which records all the past actions).
The Drama Manager is given priority, then the player, then NPCs.
This means that if the Drama Manager wants to alter or invalidate the actions of NPCs (or the player) it is able to do so in order to ensure the integrity of the scenario.
Then the player is the most important, with the first chance to act, they could alter NPCs actions, and not be unexpectedly blocked by the actions of NPCs.
However, there are systems in place that delay the player from acting, for example if an NPC has a reaction to one of their actions the player may not continously chain actions to block them.

The final thing I wish to note is that each action has a sentence that will be output so the player can see what actions are being performed, these can be custom written for each action, or take the form: 'subject' 'verb's 'object'.

#Personality
As has been mentioned, one of the aspects of this system is the implementation of a personality model to guide characters choices in actions that they perform.
The personality model that was used is the 5 factor model, with the personality traits of  open, conscientious, extraverted, agreeable, neurotic.
Each trait ranges from positive to negative, a high value of (for example) extraverted would an extravert, a negative value would be an introvert and a value near 0 would be neutral.
The values used to represent these are bounded numbers limited between -1 and 1.
These bounded numbers mean that increases/decreases are not absolute, but relative to the current value.
To explain: an increase of 0.1 will move 10% of the distance from the current value from the maximum.
As a result even at 0.99 an increase of 0.1 will not push that value over 1.0.
This also means that the distibution of personalities will tend to leave most people in the middle with fewer outliers, like a bell curve, which is good enough to mirror real distribution of personalities.

In addition to these personality traits there are moods, for this version of the system there are only 2 moods: happy and angry.
The difference between mood and personality is best summed up as personality being (semi-)permanent and moods being temporary.
Moods of characters slowly decay back to the default resting state (of 0) each cycle.

The final bit of personailities is the perception of traits in others, as in does the character believe another to be conscientious etc.
In actions that are being performed on others it is very likely the object of the action factor into if the subject wishes to perform the action, so for this reason perceiving the traits of others is important.

The personality is used to calculate the inclination for the character to perform a given action.
The inclinination that the character has for or against an action is used as a cost when determining the actions that a character will do when planning.
Not all personality traits will necessarily affect every action, for example how conscientious a character is, probably isn't the key factor in whether they will kiss another.
The which traits, and how much each is weighted, have to be decided individually and specifically for each action, at the discretion of the author (in this case me).

#Planning
Having covered the other major aspects of the program, it now makes sense to cover (probably) the most complicated system in the program, that being how NPCs form plans and decide what actions to perform.
Each NPC has a planner, and is capable of planning a sequence of actions, to achieve a goal.

The technique used is Goal-Oriented Action Planning (GOAP), character have goals and actions and use that knowledge to plan a path from the current state to one where their goal is fulfilled.
The goals of the NPCs are the state of the world that they would like it to be, and as mentioned previously each action effects the state of the world, and has conditions (about the state of the world) under which they can be performed.
Using this knowledge, characters can determine a way to chain sequences of actions from their desired state back to the current world state.
The cost of performing each action is calculated by the characters inclination, some actions may align with the character personality and barely increase the cost, actions that are against the characters personality would greatly increase the cost.
The lowest cost sequence of actions will be the one chosen and this sequence will be added as the characters plan of actions they will perform.

Reactions the character have, or completing goals can cause the character to change goal, in which case they will have to replan and form a new sequence of actions.
Characters can have multiple goals, but in the current system they will only plan for one at a time, they will prioritize their goals in order of relevance.
