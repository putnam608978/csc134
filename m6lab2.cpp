
/*
CSC 134
Putnam, Elijah
9/24/25
*/

#include <iostream>
#include <limits> // Required for clearing input buffer

using namespace std;

// ========== GLOBAL STATE FOR CAMPAIGN EFFECTS ==========
// If true, the Dark Eldar cannot use their fast-attack Jet Bikes in LZ Alpha.
bool g_fuel_destroyed = false;

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
void strike_cache_B_aircav();  // EXPANDED: Quick strike that leads to LZ Alpha
void landing_zone_alpha_stage_one(); // NEW: LZ Alpha - Initial Landing
void lz_alpha_stage_two_night_siege(); // NEW: LZ Alpha - Night Defense
void lz_alpha_stage_three_dawn_assault(); // NEW: LZ Alpha - Final Push
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
    cout << "Commander Moore has established a temporary command post near the outpost. He lays out his plan: The 224th will use rapid insertion via **Valkyrie Assault Carriers** to seize two crucial Dark Eldar supply caches (A and B) simultaneously. He needs your advice on which objective to prioritize." << endl;
    cout << "Cache A (LZ Alpha) is the communications relay, heavily defended. Cache B is the primary fuel source for their jet bikes." << endl;
    cout << "Which objective should the Elysian Drop Troopers prioritize to begin the counter-attack? (1 = LZ Alpha: The main objective, a direct, high-risk assault, 2 = Cache B: Disable their mobility first, then proceed to LZ Alpha): ";
    
    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "Which objective should be prioritized? (1 = LZ Alpha, 2 = Cache B): ";
    }
    
    if (choice == 1) {
        cout << "\nCommander Moore nods. 'A swift punch to their heart. Understood. Prepare your squad for Valkyrie insertion to LZ Alpha.'" << endl;
        landing_zone_alpha_stage_one(); // Go straight to the main fight
    } else {
        cout << "\nCommander Moore considers this. 'Deny them mobility. A riskier deep strike, but the reward is worth it. Prepare your squad for Valkyrie insertion to Cache B.'" << endl;
        strike_cache_B_aircav(); // Complete the pre-mission first
    }
}

void strike_cache_B_aircav()
{
    cout << "\n***STRIKE ON CACHE B (FUEL DEPOT)***" << endl;
    cout << "You are part of a small, fast-moving insertion team. The mission is surgical: blow the fuel depot and exfiltrate. The depot is guarded by a handful of Dark Eldar Wych squads and a single Raider transport." << endl;
    
    // Quick decision to determine success
    cout << "Your team spots the Raider about to patrol the main access road. Do you... (1 = Ambush the Raider and secure the entire depot first, 2 = Bypass the guards, plant the charges, and detonate immediately): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "What is your strike plan? (1 = Ambush, 2 = Bypass and Detonate): ";
    }
    
    if (choice == 1) {
        cout << "\n'Ambush!' You eliminate the Raider crew and the Wych guards, but the delay allows a distress signal to be sent, alerting the main force at LZ Alpha." << endl;
        g_fuel_destroyed = true;
    } else {
        cout << "\n'Bypass the guards! Plant the charges!' The depot erupts in a blinding, massive fireball. The Dark Eldar are stunned by the speed and severity of the attack. No warning is sent. The fuel is gone, mobility is crippled, and the LZ Alpha force is unaware of the loss." << endl;
        g_fuel_destroyed = true; // Still sets the flag, but with a better tactical result.
    }
    
    cout << "\n**[FUEL DESTROYED. DARK ELDAR MOBILITY CRIPPLED.]**" << endl;
    cout << "Mission complete. You quickly regroup with the main 224th command and proceed to the primary objective: LZ Alpha." << endl;
    landing_zone_alpha_stage_one();
}

// =======================================================
// LZ ALPHA MULTI-STAGE BATTLE
// =======================================================

void landing_zone_alpha_stage_one()
{
    cout << "\n***STAGE 1: LZ ALPHA - THE INITIAL SIEGE***" << endl;
    cout << "The Valkyries scream over the LZ. As you land, the surrounding dense terrain erupts with fire. This is the **Death Trap**. The Elysian troopers immediately take casualties." << endl;

    if (g_fuel_destroyed) {
        cout << "\n**[CRIPPLED MOBILITY]** The enemy is limited to foot infantry and standard transports. There are no swift **Jet Bikes** to exploit gaps in your line!" << endl;
    } else {
        cout << "\n**[FULL MOBILITY]** Dark Eldar **Jet Bikes** are everywhere, darting across the flanks and striking your soft underbelly!" << endl;
    }
    
    // The immediate threat, mirroring the 'cut off' plot point
    cout << "The Xenos are trying to cut off Lieutenant Sarn’s platoon. Commander Moore yells into the vox: 'They're trying to cut Sarn off! What's the immediate priority to save Sarn and secure the zone?'" << endl;
    cout << "Your options:" << endl;
    cout << "(1 = Request *Thunderbolt Strike* on Sarn's coordinates, danger close, 2 = Order CSM Rexor's command platoon to manually fight and link up with Sarn): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "What is the immediate priority? (1 = Air Strike, 2 = Infantry Link-Up): ";
    }
    
    if (choice == 1) {
        // Air Support: Risky but fast
        cout << "\n'BROKEN ARROW! Danger close on Sarn’s sector!' The strike breaks the encirclement, saving Sarn. However, the ordnance run is too close, and several Valkyrie gunships are forced to scatter, temporarily abandoning the LZ, leaving you light on air support." << endl;
        lz_alpha_stage_two_night_siege(); // Proceed to next stage
    } else {
        // Infantry Link-Up: Slow but safe for air support
        cout << "\n'Rexor! Take your men and push through to Sarn! Clear the path!' CSM Rexor leads a brutal, methodical charge. The fight is intense, but the line is restored. Rexor glares at the retreating Xenos. 'They hit hard, Lieutenant, but they can’t take a direct punch.' Your air support remains fully committed." << endl;
        lz_alpha_stage_two_night_siege(); // Proceed to next stage
    }
}

void lz_alpha_stage_two_night_siege()
{
    cout << "\n***STAGE 2: LZ ALPHA - THE NIGHT SIEGE***" << endl;
    cout << "Night falls, and the perimeter is established. Commander Moore gathers his officers. The Dark Eldar are probing your lines with relentless, close-quarters attacks, reminiscent of the shadowy Viet Cong attacks." << endl;
    cout << "CSM Rexor reports: 'We're holding, sir, but the Xenos are using hidden tunnels to breach our wire on the East Flank. We need a way to seal those tunnels and gain an hour of rest before the main assault at dawn.'" << endl;

    // Night Siege Decision: Counter-attack or defensive trap
    cout << "Moore looks at you: 'We can't spare the men to hold every inch. How do we stop those tunnel attacks?'" << endl;
    cout << "(1 = Launch a night-time search-and-destroy patrol to locate and collapse the main tunnel entrance, 2 = Use flamers and demo charges to create a 'scorched earth' kill zone on the East Flank, denying cover): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        handleInvalidInput();
        cout << "What is your night defense strategy? (1 = Search and Destroy, 2 = Scorched Earth Kill Zone): ";
    }

    if (choice == 1) {
        // Search and Destroy: High Risk, High Reward
        cout << "\n'Search and Destroy. Find the source.' The patrol manages to find the main entrance and collapses it with a chain of melta charges. The Dark Eldar night attacks cease entirely. Your troops get 4 hours of critical sleep." << endl;
        lz_alpha_stage_three_dawn_assault(); // Proceed with an advantage
    } else {
        // Scorched Earth: Medium Risk/Reward
        cout << "\n'Scorched Earth. Burn the cover.' The flames light up the East Flank and detonate secondary charges, making the Xenos think twice about breaching there. However, the noise and fire force your own troops to stay alert, resulting in a tense, sleepless night. Your troops are exhausted." << endl;
        lz_alpha_stage_three_dawn_assault(); // Proceed to final stage, but with a penalty (simulated by a slightly harder condition to win)
    }
}

void lz_alpha_stage_three_dawn_assault()
{
    cout << "\n***STAGE 3: LZ ALPHA - THE DAWN ASSAULT***" << endl;
    cout << "The morning mist clears, revealing a massive concentration of Dark Eldar infantry advancing on your position. This is the **Final Push**. The enemy knows they must take the LZ now." << endl;
    
    if (g_fuel_destroyed) {
        cout << "The enemy infantry advance is slow and deliberate. Their lack of Jet Bike support means they cannot concentrate overwhelming force quickly. You have time for one crucial final move." << endl;
        
        // Easier choice due to no Jet Bikes
        cout << "Commander Moore: 'They're slow, Lieutenant. We have time. Do we call for a high-explosive artillery barrage on their main column, or order an aggressive platoon-sized counter-attack to break their formation before they reach the wire?'" << endl;
        cout << "(1 = Artillery Barrage, 2 = Aggressive Counter-Attack): ";
        
        int choice;
        while (!(cin >> choice) || (choice != 1 && choice != 2)) {
            handleInvalidInput();
            cout << "Final choice? (1 = Artillery Barrage, 2 = Aggressive Counter-Attack): ";
        }
        
        if (choice == 1) {
            cout << "\n'Artillery! Bring the fire!' The pinpoint barrage annihilates the enemy column, turning the tide of the entire battle. The remaining Dark Eldar scatter in panic." << endl;
            tactical_victory(); // Successful
        } else {
            cout << "\n'Counter-attack! Hit them before they hit us!' The charge is brave, but the enemy infantry line is too dense. The counter-attacking platoon is forced to retreat, having lost momentum and causing severe casualties to the Elysian force. The line holds, but only just." << endl;
            gameOver(); // Too costly a victory
        }
        
    } else {
        cout << "The enemy assault is fast and overwhelming. Dark Eldar **Jet Bikes** are screaming across the flanks, hitting every weak point in the perimeter. You have seconds to react." << endl;
        
        // Harder choice due to Jet Bikes
        cout << "Commander Moore: 'The Jet Bikes are tearing us apart! We need to destroy their fast attack capability *or* break the main infantry. What's the focus?!'" << endl;
        cout << "(1 = Focus all heavy weapon fire on the Jet Bikes, 2 = Call in all available Air Support on the main infantry line, ignoring the bikes): ";
        
        int choice;
        while (!(cin >> choice) || (choice != 1 && choice != 2)) {
            handleInvalidInput();
            cout << "Final choice? (1 = Focus on Jet Bikes, 2 = Focus on Infantry Line): ";
        }
        
        if (choice == 1) {
            cout << "\n'Target the bikes! Deny them mobility!' The heavy weapons crews manage to shoot down several key Jet Bikes, but the time spent not shooting the infantry allows the main Dark Eldar line to reach the wire and breach the perimeter. The LZ is overrun." << endl;
            gameOver(); // Too little, too late
        } else {
            cout << "\n'Strike the main line! Destroy the heart of the assault!' The Thunderbolt pilots unleash a devastating torrent of rockets and cannons on the infantry, shattering the main column. The remaining Jet Bikes are disorganized and retreat without orders. The LZ is secured." << endl;
            tactical_victory(); // Successful
        }
    }
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
    cout << "The LZ is secured. The Elysian Drop Troopers have established a critical foothold on the planet. Commander Moore's tactical doctrine proves effective, but the cost in Imperial Guard blood has been paid. The liberation campaign continues, setting the stage for the final assault on the Xenos command structure!" << endl;
    cout << "--------------------------------------------------" << endl;
}