
/*
CSC 134
M4LAB1 - 
Putnam, Elijah
9/24/25
Expanded by Gemini
*/

#include <iostream>
#include <limits> // Required for clearing input buffer

using namespace std;

// ========== FUNCTION PROTOTYPES ==========
// Declare all your "rooms" up here
void fighting_postion_Kilo(); // Starting location
void city_center();          // A possible path
void governor_palace();      // Another path
void organizing_the_defenses(); // The next scene (fixed location)
void the_last_stand();       // The final battle sequence
void communications_outpost(); // Side path to try and call for help
void grim_victory();         // Transition to the campaign phase
void grim_victory_transition(); // Introduction of Commander Moore & CSM Rexor
void elysian_campaign_start(); // The first choice of the campaign
void landing_zone_alpha();  // NEW: Aircav assault on LZ Alpha (The Ia Drang scenario)
void strike_cache_B_aircav();  // Aircav assault on Cache B
void gameOver();             // An ending
void victory();              // Another ending
void tactical_victory();      // NEW: A successful campaign mission victory

// ========== MAIN FUNCTION ==========
int main()
{
    cout << "==================================" << endl;
    cout << " WELCOME TO YOUR ADVENTURE " << endl;
    cout << "==================================" << endl;
    cout << endl;
    
    // Start the adventure!
    fighting_postion_Kilo();
    
    cout << "\n=== THE END ===" << endl;
    return 0;
}

// Helper function to handle invalid input
void handleInvalidInput() {
    cout << "Invalid choice. Please enter 1 or 2." << endl;
    cin.clear(); // Clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
}

// ========== LOCATION FUNCTIONS ==========

void fighting_postion_Kilo()
{
    cout << "\nYour vision slowly returns to you and you hear **lasgun fire and explosions** all around you. Your soldiers are screaming and fighting to hold the enemy back. You hear your commander hailing you on your vox." << endl;
    cout << "Lt Smith, gather your forces and fallback to the city center to secure the Governor." << endl;
    cout << "Will you fallback? (1 = Yes, 2 = No): ";
    int choice;
    
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Will you fallback? (1 = Yes, 2 = No): ";
    }
    
    if (choice == 1)
    {
        cout << "\n'You gather your forces and lead a fighting withdrawal back to the city center. During the withdrawal your forces are harassed by enemy **jet bikes and aircraft** trying to break up your formation!'" << endl;
        city_center(); // Go to city_center function
    }
    else
    {
        cout << "\n'The fighting intensifies and you organize your soldiers into a formidable defense but your heavy bolters run out of ammo and a sudden high pitched screech rings out and a flash of light speeds through the air and hits your Chimera destroying it. The enemy quickly overcomes your forces and the planet falls. !'" << endl;
        gameOver(); // Go to game over
    }
}

void city_center()
{
    cout << "\n[ As you lead your convoy to the city center the **Dark Eldar** pursue you and harass your convoy and destroys the Chimera at the back of the column.]" << endl;
    cout << "Will you stop the convoy and try and recover the crew of the Chimera or continue to the city center? (1 = Recover Crew, 2 = Continue to Center): ";
    int choice;
    
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Will you stop the convoy? (1 = Recover Crew, 2 = Continue to Center): ";
    }
    
    if (choice == 1)
    {
        cout << "\n{You stop the convoy and form a perimeter around the destroyed Chimera and your men are firing in all directions but the Dark Eldar are too quick on their jet bikes and quickly overwhelm your forces and kill everyone. }" << endl;
        gameOver(); // Go to game over
    }
    else
    {
        cout << "\n[You sadly order your men to continue the movement to the city center and leave the crew of the last Chimera to die. As you approach the city center you call your higher command to request covering fire to suppress the Dark Eldar forces attacking your convoy. “This is Captain Lewis, continue straight and our gunners will engage the enemy as soon as they enter range.” Heavy bolter fire suddenly starts flying overhead and drives the Dark Eldar back. They take minimal losses in the exchange.]" << endl;
        
        // FORK: Do you trust the orders?
        cout << "\nCaptain Lewis has ordered you straight to the Palace, but your comms officer expresses concern that the Governor might be unreliable. Where will you direct the remainder of your forces? (1 = Governor's Palace, 2 = Remote Communications Outpost): ";
        
        int second_choice;
        while (!(cin >> second_choice) || (second_choice != 1 && second_choice != 2)) {
            handleInvalidInput();
            cout << "Where will you go? (1 = Governor's Palace, 2 = Remote Communications Outpost): ";
        }

        if (second_choice == 1) {
            governor_palace(); // Existing path
        } else {
            communications_outpost(); // New path
        }
    }
}

void governor_palace()
{
    cout << "\n[Your forces enter the defensive perimeter and you tell your men to resupply and join the defenses. Captain Lewis approaches you: “LT Smith, I need you to come with me. We’ve taken heavy casualties and need to speak with the governor about the situation and plan our next move.”]" << endl;
    cout << "You walk into the palace next to Captain Lewis and approach the governor. He is clearly panicking and speaking to himself. Captain Lewis speaks loudly: “ Sir, we need to call for reinforcements.” The governor ignores the Captain." << endl;
    cout << "The governor continues to talk to himself, and you and Captain Lewis hear him say **'they were supposed to only raid the fringe settlements.'**" << endl;
    cout << "You and Captain Lewis aim your weapons at the governor as Captain Lewis yells: “You made a deal with these xeno scum!”" << endl;
    cout << "Do you shoot the Governor? (1 = Execute the Traitor, 2 = Lower Weapon and De-escalate): ";
    
    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Do you shoot the Governor? (1 = Execute the Traitor, 2 = Lower Weapon and De-escalate): ";
    }

    if (choice == 1) {
        cout << "\n***For the Emperor!*** You shoot the Governor. Captain Lewis turns to shoot you, so you quickly shoot him too. You take control of the defenses and lead the remaining soldiers." << endl;
        organizing_the_defenses(); // Go to organizing_the_defenses
    } else {
        cout << "\nCaptain Lewis lowers his weapon and asks the Governor what his orders are. The Governor, in a fit of despair, decides to **surrender** to the Dark Eldar. The planet is taken, and its people are led away as slaves." << endl;
        gameOver();
    }
}

void communications_outpost()
{
    cout << "\n***THE COMMUNICATIONS OUTPOST***" << endl;
    cout << "You divert the convoy toward the high-ground relay. The comms room is secured by a small, exhausted detachment, but the main dish is broken from an orbital strike. An engineer says he can fix it in ten minutes, but the Dark Eldar have just started targeting the outpost with heavy fire." << endl;
    cout << "Do you... (1 = Defend the Engineer for 10 minutes, 2 = Overload the secondary relay for an instant, risky message): ";
    
    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Do you choose? (1 = Defend the Engineer, 2 = Overload Relay): ";
    }
    
    if (choice == 1) {
        // --- EXPANDED DEFEND PATH ---
        cout << "\n[You choose to defend the Engineer.] The battle is fierce. You manage to hold the perimeter for eight minutes, but the Dark Eldar launch a swift counter-attack, bringing forward a heavily armed **Ravager anti-grav tank** to breach the final defenses. The engineer has two minutes left!" << endl;
        cout << "What is your counter-measure? (1 = Order all available troops to fire Melta-bombs and focus Lasgun fire on the Ravager, 2 = Deploy the secondary Chimera as a sacrificial barricade, drawing its fire): ";

        int defense_choice;
        while (!(cin >> defense_choice) || (defense_choice != 1 && defense_choice != 2)) {
            handleInvalidInput();
            cout << "What is your counter-measure? (1 = Fire Melta-bombs, 2 = Deploy Sacrificial Chimera): ";
        }

        if (defense_choice == 1) {
            cout << "\n'FOR THE EMPEROR!' Your troops rush the Ravager. The Melta-bombs stick, but the tank unleashes a torrent of deadly fire, cutting down nearly half your remaining force before it explodes. The engineer finishes the repair just as the last enemy jet bikes retreat." << endl;
            grim_victory(); // Leads to costly success and transition
        } else {
            cout << "\nYou order the brave crew of the secondary Chimera to drive forward. It draws the Ravager's attention and is quickly vaporized, but the brief distraction gives your heavy weapons time to disable the Ravager's main gun. The engineer is safe, the distress call is sent, but the loss of life and vehicles is severe." << endl;
            grim_victory(); // Also leads to costly success and transition
        }
        // --- END EXPANDED DEFEND PATH ---
    } else {
        // --- OVERLOAD PATH ---
        cout << "\n'You order the comms officer to overload the secondary relay. The signal goes out instantly! But the overload causes the relay to explode, drawing the immediate, full attention of the Dark Eldar aircraft, who annihilate the outpost, sealing your fate. You made the call, but paid the ultimate price.'" << endl;
        gameOver(); // Leads to Game Over
    }
}

void grim_victory()
{
    cout << "\n--------------------------------------------------" << endl;
    cout << "💀 COSTLY SUCCESS 💀" << endl;
    cout << "The reinforcements arrive, but too late to save the majority of the population. The planet is secured, but the cost in Imperial Guard lives and civilian casualties is immense. Your actions guaranteed the message was sent, but the horror of the Xenos raid will forever haunt this sector." << endl;
    cout << "--------------------------------------------------" << endl;
    // Transition to the next phase
    grim_victory_transition();
}

void grim_victory_transition()
{
    cout << "\n***IMPERIAL RESPONSE***" << endl;
    cout << "The Dark Eldar forces, unable to sustain the raid against the now-secured communications outpost, begin their retreat. Three days later, the sky is filled with the roar of Imperial ships. You are summoned to the command shuttle of the arriving forces." << endl;
    cout << "You meet **Commander Moore** of the 224th Elysian Drop Troopers. He is stern, professional, and entirely focused on the mission. Standing beside him is **Command Sergeant Major Rexor**, a scarred, towering man whose glare could crack ceramite. Rexor's job is to ensure every trooper follows orders or regrets it." << endl;
    cout << "Commander Moore speaks: 'Lt. Smith, your distress call saved this planet from a full enslavement. You and your surviving men will now act as local guides and tactical advisors. I have been given **supreme command** of this sector's liberation. The campaign to cleanse this world starts now.'" << endl;
    
    elysian_campaign_start();
}

void elysian_campaign_start()
{
    cout << "\n***OPERATION: PLANETARY CLEANSING***" << endl;
    cout << "Commander Moore has established a temporary command post near the outpost. He lays out his plan: The 224th will use rapid insertion via **Valkyrie Assault Carriers** to seize two crucial Dark Eldar supply caches (A and B) simultaneously. He needs your advice on which cache will cause the most disruption." << endl;
    cout << "Cache A is closer, but heavily defended by stationary defenses. Cache B is further away, but contains their primary fuel source for their jet bikes." << endl;
    cout << "Which cache should the Elysian Drop Troopers prioritize to begin the counter-attack? (1 = Cache A: Closer but heavily defended, 2 = Cache B: Further, but high-value fuel target): ";
    
    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Which cache should be prioritized? (1 = Cache A, 2 = Cache B): ";
    }
    
    if (choice == 1) {
        cout << "\nCommander Moore nods. 'A swift punch to their immediate defenses. Understood. Prepare your squad for Valkyrie insertion to LZ Alpha.'" << endl;
        landing_zone_alpha(); // Call the RENAMED function
    } else {
        cout << "\nCommander Moore considers this. 'Deny them mobility. A riskier drop, but the reward is worth it. Prepare your squad for Valkyrie insertion to Cache B.'" << endl;
        strike_cache_B_aircav(); // Call the new Aircav function
    }
}

void landing_zone_alpha()
{
    cout << "\n***LZ ALPHA: BATTLE FOR THE COMM RELAY***" << endl;
    cout << "You are aboard the lead Valkyrie with Commander Moore and CSM Rexor. This is the **LZ Alpha** insertion, intended to seize the critical Dark Eldar communications relay. The moment you land, it's clear the enemy was waiting: the LZ is a **Death Trap**." << endl;
    cout << "Dark Eldar forces, hidden in the surrounding jungle like the jungle warriors of ancient Terra, erupt with concentrated fire, pinning down your Elysian Drop Troopers. The enemy is in overwhelming numbers, immediately threatening to cut off one of your key platoons, commanded by Lieutenant Sarn." << endl;
    
    // The immediate threat, mirroring the 'cut off' plot point
    cout << "Commander Moore radios: 'They're trying to cut Sarn off! If they break his line, they'll overrun the entire LZ! Lieutenant Smith, what's the immediate priority to save Sarn and secure the zone?'" << endl;
    cout << "Your options, based on the principle of airmobile support:" << endl;
    cout << "(1 = Focus all available Air Support (Thunderbolts) on Sarn's sector immediately, 2 = Call for the infantry reserve (Alpha Company) to push through the perimeter to link up with Sarn): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "What is the immediate priority? (1 = Air Support, 2 = Infantry Link-Up): ";
    }
    
    if (choice == 1) {
        // Air Support (The call for fire near your position, mirroring the desperate situation)
        cout << "\n'Air support is priority! Requesting immediate strafing run on Sarn's coordinates, danger close!' The Thunderbolt pilots confirm. The close air support momentarily breaks the Dark Eldar's assault on Sarn, giving his platoon a moment to consolidate. However, the momentary lull allows the *rest* of the Dark Eldar forces to reposition their heavy weapons." << endl;
        
        // Secondary Decision: A counter-attack is now necessary
        cout << "\nCSM Rexor shouts over the vox, 'The Xenos are massing on the North Ridge! If they get heavy weapons up there, the whole LZ is gone! Lieutenant, we need a rush to clear that ridge before they zero in!'" << endl;
        cout << "Moore needs your advice: (1 = Order a full-frontal assault by two platoons on the Ridge, 2 = Send one small, heavily armed squad (a 'search and destroy' element) to flank the Ridge and disrupt their assembly): ";
        
        int second_choice;
        while (!(cin >> second_choice) || (second_choice != 1 && second_choice != 2)) {
            handleInvalidInput();
            cout << "What is your plan for the North Ridge? (1 = Full Frontal, 2 = Flank and Disrupt): ";
        }
        
        if (second_choice == 1) {
            cout << "\n'Full frontal! Fix bayonets and charge the Ridge!' The two platoons run directly into a prepared Dark Eldar killing zone. While they inflict massive casualties, the losses taken are catastrophic. The Ridge is secured, but the battle is now a grim stalemate." << endl;
            gameOver(); // Too costly, the mission stalls and fails.
        } else {
            cout << "\n'Flank and Disrupt! Send the best squad, heavy weapons only! Break their assembly before they form a line!' The small squad, using dense cover, performs a swift, brutal attack, scattering the Dark Eldar massing on the ridge. The LZ is secured, and more Valkyries start landing reinforcements. A costly victory is achieved." << endl;
            tactical_victory();
        }
        
    } else {
        // Infantry Link-Up (The classic 'push through' scenario)
        cout << "\n'Alpha Company, push through and link up with Sarn! Move! Move! Move!' Alpha Company attempts to break through the tight encirclement to reach the cut-off platoon. The Dark Eldar recognize the danger of a unified line and focus all fire on the linking company, annihilating the company commander and forcing a brutal retreat." << endl;
        cout << "Sarn's platoon is overrun and the LZ perimeter collapses. The mission fails spectacularly." << endl;
        gameOver();
    }
}

void strike_cache_B_aircav()
{
    cout << "\n***STRIKE ON CACHE B (FUEL DEPOT)***" << endl;
    cout << "You and Commander Moore prepare for the deep strike mission to Cache B, the valuable fuel depot. This high-value target is protected by Dark Eldar speeder patrols and traps. Awaiting implementation..." << endl;
    // This is the placeholder for future expansion of the campaign.
}

void organizing_the_defenses()
{
    cout << "\nCaptain Lewis looks at you and asks “Why did you do that?” you reply: “He was a traitor, he sold us out and he deserved to die!” Captain Lewis hangs his head and solemnly says: “What are we going to do now?”" << endl;
    cout << "Suddenly the planet's **Astropath** walks forward and says there are ancient rites he can perform to summon the Emperor's Angels (Astartes)." << endl;
    cout << "Do you have the Astropath conduct the ancient rights? (1 = Yes, hope for the Angels, 2 = No, it's superstition): ";
    
    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Do you have the Astropath conduct the ancient rights? (1 = Yes, hope for the Angels, 2 = No, it's superstition): ";
    }
    
    if (choice == 1) {
        cout << "\n“We cannot surrender. We must fight to the last man. To surrender would be heresy!” Captain Lewis concedes your point and tells the Astropath to go and do his ancient rites. He tells you to take control of the defenses. You respond “Yes sir!” and move outside to start coordinating your planet’s **last stand**." << endl;
        the_last_stand();
    } else {
        cout << "\nCaptain Lewis says: 'Nothing more than old superstitions, no one is coming to save us. We must surrender.' Without the will to fight, your forces collapse, and the battle is lost." << endl;
        gameOver();
    }
}

void the_last_stand()
{
    cout << "\n***THE LAST STAND***" << endl;
    cout << "The Dark Eldar are mounting a final, heavy assault. The Astropath's ritual is underway, but you don't know if it will work. You have one remaining **Vindicator tank** with three demolition shells." << endl;
    cout << "Captain Lewis asks for your final command: “Should we fire all three shells now to break their initial advance, or hold them back for when their main line breaks through the perimeter?”" << endl;
    cout << "Tactical Choice: (1 = Fire All Shells Now, 2 = Save Shells for Final Perimeter Breach): ";
    
    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Tactical Choice: (1 = Fire All Shells Now, 2 = Save Shells for Final Perimeter Breach): ";
    }
    
    if (choice == 1) {
        cout << "\nYou order the Vindicator to fire. The initial enemy wave is annihilated, but you are now exposed when the second, larger wave hits the defenses. The Astropath cries out as the ritual fails from lack of defense." << endl;
        gameOver();
    } else {
        cout << "\n[You hold the line, taking heavy losses, but as the Dark Eldar breach the perimeter, you unleash the Vindicator shells, shattering their morale and their main column. The Astropath's ritual culminates in a blinding light, and three squads of **Space Marine Terminators** teleport directly into the fray, saving the day.]" << endl;
        victory();
    }
}

void gameOver()
{
    cout << "\n--------------------------------------------------" << endl;
    cout << "💀 GAME OVER 💀" << endl;
    cout << "The planet is lost. The will of the Emperor was not enough." << endl;
    cout << "--------------------------------------------------" << endl;
}

void victory()
{
    cout << "\n--------------------------------------------------" << endl;
    cout << "🌟 VICTORY! 🌟" << endl;
    cout << "The Sons of Dorn arrive to cleanse the Xeno threat. The planet is saved!" << endl;
    cout << "--------------------------------------------------" << endl;
}

void tactical_victory()
{
    cout << "\n--------------------------------------------------" << endl;
    cout << "⚔️ TACTICAL VICTORY ⚔️" << endl;
    cout << "The LZ is secured. The Elysian Drop Troopers have established a critical foothold on the planet. Commander Moore's tactical doctrine proves effective, but the cost in Imperial Guard blood has been paid. The liberation campaign continues..." << endl;
    cout << "--------------------------------------------------" << endl;
}
