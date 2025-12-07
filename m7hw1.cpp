// debrief.cpp
// "After Action — Mogadishu Debrief (enhanced, fictionalized)"
// Single-file interactive text game with expanded specifics (call signs, logs, transcripts, expanded adjudication).
// Compile: g++ -std=c++17 -O2 -o debrief debrief.cpp
// Run: ./debrief
//
// Note: This is a fictionalized training exercise inspired by historical events. It is intended for
// educational purposes (leadership, ethics, decision-making). All names/locations/callsigns are fictional.

#include <bits/stdc++.h>
using namespace std;

struct Outcome {
    int credibility = 50;
    int tactical = 50;
    int intel = 50;
    int civilian_impact = 50; // higher = better mitigation
    int unit_care = 50;
    int political_risk = 50; // higher = worse
    vector<string> notes;
};

void pause() {
    cout << "\n(press Enter to continue)";
    string tmp;
    getline(cin, tmp);
}

int get_choice(int minc, int maxc) {
    while (true) {
        string line;
        getline(cin, line);
        try {
            int c = stoi(line);
            if (c >= minc && c <= maxc) return c;
        } catch(...) {}
        cout << "Please enter a number between " << minc << " and " << maxc << ": ";
    }
}

void show_status(const Outcome &o) {
    cout << "\n--- STATUS ---\n";
    cout << "Credibility: " << o.credibility << "/100\n";
    cout << "Tactical soundness: " << o.tactical << "/100\n";
    cout << "Intel handling: " << o.intel << "/100\n";
    cout << "Civilian-impact mitigation: " << o.civilian_impact << "/100\n";
    cout << "Unit care (perceived): " << o.unit_care << "/100\n";
    cout << "Political risk: " << o.political_risk << "/100\n";
    cout << "----------------\n";
}

void final_adjudication(const Outcome &o) {
    cout << "\n--- PANEL ADJUDICATION ---\n";
    // More granular decisions
    if (o.credibility >= 75 && o.tactical >= 65 && o.unit_care >= 65 && o.political_risk <= 55) {
        cout << "Result: CLEARED. Recommended: Formal commendation for leadership under duress and recommended doctrinal changes documented.\n";
    } else if (o.credibility >= 60 && o.tactical >= 50 && o.intel >= 55 && o.political_risk <= 70) {
        cout << "Result: CLEARED WITH CONDITIONS. Recommended: Remedial command training, procedural reforms, and close oversight for 12 months.\n";
    } else if (o.credibility >= 45 && o.tactical >= 40) {
        cout << "Result: FORMAL REPRIMAND. Recommended: Article 15 consideration unlikely but corrective action and probation required.\n";
    } else {
        cout << "Result: RELIEVED OF COMMAND / FURTHER INVESTIGATION. Recommended: Immediate relief and full administrative/disciplinary review including potential courts-martial.\n";
    }
    cout << "--------------------------\n";
}

string format_time(const string &hhmm) {
    // Return human-friendly time like "02:15"
    if (hhmm.size() == 4) return hhmm.substr(0,2) + ":" + hhmm.substr(2,2);
    return hhmm;
}

// Pre-written fictional logs & transcripts (player may choose which to release)
struct LogExcerpt {
    string id;
    string title;
    string content;
    bool classified; // if true, releasing will cost political_risk unless authorized
};

vector<LogExcerpt> create_excerpts() {
    vector<LogExcerpt> v;
    v.push_back({
        "LOG1",
        "Blue Force Tracker Snapshot (Sector Grid Delta-3)",
        "0208Z: Friendly alpha convoy enters Sector Delta-3. BFT: Viper 2-1 (Lead Helo), Falcon 3-2 (Ground QRF), Raven 5 (JTAC) noted. Grid coords: 11.956N, 45.321E (fictional).",
        false
    });
    v.push_back({
        "LOG2",
        "Flight Telemetry - Viper 2-1",
        "0212Z: Viper 2-1 reports 'small arms fire, left engine hit, losing tail rotor effectiveness.' 0215Z: Mayday transmitted. Emergency transponder beacon active. Crash site approximate: Sector Delta-3 intersection at Hawlwadig Road.",
        true
    });
    v.push_back({
        "LOG3",
        "Interpreter 'Ahmed' witness fragment",
        "0216Z: 'They came from the market, with technicals and RPGs, blocking the alleys. We saw them set up a ring.' Interpreter expresses fear; identifies multiple militia elements east of compound.",
        false
    });
    v.push_back({
        "LOG4",
        "JTAC Audio (Raven 5) excerpt",
        "0213:45Z: 'Viper 2-1, be advised potential RPG signature from rooftop, recommend suppressive fire from overwatch if possible.' 0214:30Z: 'Unable to get eyes; ground elements report heavy small arms.'",
        true
    });
    v.push_back({
        "LOG5",
        "Medical Evac Request (Bravo 4)",
        "0225Z: 'MEDIC: One KIA, two WIA (gunshot, femoral), CASEVAC priority 1. LZ constrained; require immediate CASEVAC or we cannot stabilize.'",
        false
    });
    v.push_back({
        "LOG6",
        "After-Action Photo Metadata (timestamped ISR)",
        "0218Z: ISR image shows two damaged rotor discs on Viper 2-1 and a cluster of technical vehicles converging on the intersection. Image classified - pending release authorization.",
        true
    });
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned)time(nullptr));
    Outcome o;
    auto excerpts = create_excerpts();

    cout << "AFTER-ACTION DEBRIEF — ENHANCED\n";
    cout << "Mission: Night capture operation — primary objective: 'High-value local faction leader (target alias \"Al-Farid\")'\n";
    cout << "Fictionalized setting: Urban market complex / sector grids used for exercise purposes.\n\n";
    cout << "You are the Special Operations commander (fictionalized). The operation used rotary insertion (call sign Viper 2-1), ground QRF (Falcon 3-2), JTAC/Overwatch (Raven 5), and fireteams (Bravo 4, Charlie 6). The mission timeline and events are partly classified and partly public; you will be asked to release or withhold certain logs.\n\n";
    cout << "Game mechanics: Each answer will adjust metrics (credibility, tactical soundness, intel handling, civilian-impact mitigation, unit care, political risk). Final adjudication is based on combined metrics.\n";
    pause();

    // Pre-mission specifics
    cout << "\nPRE-MISSION BRIEF (what was known prior to insertion):\n";
    cout << "- Target: 'Al-Farid' (alias), suspected at a fortified safehouse in Sector Delta-3 near the Bakara-style market (fictionalized)\n";
    cout << "- Primary insertion plan: Two Blackhawk-type birds (Viper flights), fast-rope insertion of Alpha and Bravo teams; ground QRF (Falcon 3-2) to link up via Route Echo.\n";
    cout << "- Intel: HUMINT from local asset 'Dogan' assessed target presence with reliability 'Fair' (single-source). SIGINT indicated increased chatter, possible force concentration ~40-60 personnel.\n";
    cout << "- Overwatch: Raven 5 (JTAC) and one sniper pair on rooftop overwatch.\n";
    cout << "- Planned timeline: Brief at 0100Z, watch to LZ 0200Z, insert 0210Z, action on target 0220Z, extract by 0330Z.\n";
    cout << "- Rules of Engagement: Positive ID required before lethal force in proximity to civilian structures. CASEVAC & MEDEVAC available with 15–30 minute ETA once LZ secured.\n\n";
    pause();

    // Question 1: Timeline style (more granular options)
    cout << "PANEL CHAIR: Commander, provide a concise but specific timeline and include call-sign events (timestamps) from insertion to the moment you called the extraction. Use the provided format.\n";
    cout << "1) Provide an exact minute-by-minute timeline with call signs and grid bearings.\n";
    cout << "2) Provide a narrative timeline emphasizing intent, contingencies, and deviations from plan.\n";
    cout << "3) Provide a short timeline but offer to present log excerpts (you can choose which) to validate your timeline.\n";
    cout << "Choice: ";
    int c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 8; o.intel += 3;
        o.notes.push_back("Provided minute-by-minute timeline with call signs and grid references.");
        cout << "\nYou recite: 0100Z brief; 0200Z airborne; 0206Z LZ inbound; 0210Z fast-rope insertion of Bravo 4; 0212Z Viper 2-1 provides overwatch; 0213Z contact reported; 0214Z Viper 2-1 hit; 0215Z mayday from Viper 2-1; 0218Z ground elements engaged; 0220Z CASEVAC request; 0240Z attempted vehicle recovery; 0400Z extraction call.\n";
    } else if (c == 2) {
        o.credibility += 6; o.intel += 6; o.transparency += 4;
        o.notes.push_back("Narrative timeline showed reasoning behind each deviation.");
        cout << "\nYou narrate with intent: insertion to minimize civilian exposure, anticipated overwatch suppression, but heavy crowding in the marketplace forced changes. You explain each deviation and the ad-hoc decisions.\n";
    } else {
        o.credibility -= 5; o.intel -= 5; o.notes.push_back("Asked to present excerpts later, which made panel wary.");
        cout << "\nYou provide a terse timeline and offer to present excerpts. Panel expects the commander to own the verbal account now.\n";
    }
    pause();
    show_status(o);

    // Question 2: Route choice specifics (A & B)
    cout << "\nPANEL MEMBER A: Why did the convoy / ground element (Falcon 3-2) choose the Hawlwadig Road approach through sector Delta-3 instead of the alternate alley approach (Route Foxtrot) which was deemed slower but more constrained and arguably safer from RPG fields of fire?\n";
    cout << "1) Route chosen due to a time-sensitive window to avoid target escape, supported by HUMINT placing target at 0205Z—fastest route prioritized.\n";
    cout << "2) Route chosen to maintain BFT and comm LOS — Route Foxtrot has comm blackspots that would sever JTAC link.\n";
    cout << "3) Route chosen after on-scene driver reported congestion on Route Foxtrot and we adjusted on the fly (improvisation).\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.intel += 6; o.credibility += 3; o.tactical -= 2;
        o.notes.push_back("Route justified to capitalize on narrow window; risk trade-off noted.");
        cout << "\nYou explain you had a narrow window of opportunity from HUMINT and elected the faster route to deny the target escape. Panel asks to see the HUMINT reliability notes.\n";
    } else if (c == 2) {
        o.tactical += 4; o.credibility += 2; o.intel -= 2; o.political_risk += 3;
        o.notes.push_back("Comm/LOS justification understood but panel questions force protection trade-offs.");
        cout << "\nYou discuss comm architecture and survivability of command link. Chair asks whether comm considerations overrode force protection priorities.\n";
    } else {
        o.credibility -= 4; o.tactical -= 6; o.intel -= 3; o.political_risk += 8;
        o.notes.push_back("Improvisation on route reduced perceived planning rigor.");
        cout << "\nYou say driver reported congestion and you adjusted. Panel is concerned that contingencies should have included alternate vetted routes.\n";
    }
    pause();
    show_status(o);

    // Question 3: Helicopter hit specifics (B, F)
    cout << "\nPANEL MEMBER B: Describe the moment Viper 2-1 was hit. Provide the call-sign details, approximate altitude, and immediate actions taken by the flight and by you.\n";
    cout << "1) Give exact actions: 'Viper 2-1 reported left-engine fire at 0212Z, altitude ~1500 ft, declared Mayday, egress vector south; I ordered immediate suppression and recovery elements to the crash site.'\n";
    cout << "2) Emphasize crew survivability attempt: 'I ordered Bravo 4 to the downed crew's last ping to attempt recovery despite the risk.'\n";
    cout << "3) Emphasize force protection: 'I initially held ground QRF to overwatch to avoid further aircraft being targeted while I established a secure LZ plan.'\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 6; o.unit_care += 3; o.tactical += 2;
        o.notes.push_back("Clear, specific actions after helo hit improved credibility.");
        cout << "\nYou describe the telemetry report and immediate orders: Raven 5 directed suppression; Falcon 3-2 diverted to secure crash perimeter; Bravo 4 executed an immediate casualty recovery attempt at 0218Z.\n";
    } else if (c == 2) {
        o.unit_care += 8; o.credibility += 2; o.tactical -= 3;
        o.notes.push_back("Aggressive recovery prioritized lives but increased tactical risk.");
        cout << "\nYou state you ordered Bravo 4 to attempt immediate recovery of crew despite hostile presence. Panel respects intent but notes heightened risk to rescuers.\n";
    } else {
        o.tactical += 5; o.credibility -= 2; o.unit_care -= 4; o.political_risk += 5;
        o.notes.push_back("Prioritizing overwatch seen as cautious but may have delayed rescue.");
        cout << "\nYou explain a cautious stance to avoid compounding losses. Panel questions whether risk-aversion delayed life-saving actions.\n";
    }
    pause();
    show_status(o);

    // Question 4: Comm delays and JTAC discrepancy (B & C)
    cout << "\nPANEL MEMBER C (legal/JTAC oversight): The JTAC audio (Raven 5) shows a possible earlier warning at 0213:45Z recommending suppressive fires. Why is there a discrepancy between the JTAC's audio log and your SITREP which shows a later request time?\n";
    cout << "1) Communications were degraded briefly; the JTAC call was intermittent and may not have reached all nets. Provide logs if helpful.\n";
    cout << "2) I assessed that the JTAC warning did not change risk calculus at the time; we were already executing a planned movement and could not pause without jeopardizing containment.\n";
    cout << "3) I mis-sequenced the communications in the heat of battle — we will review and correct internal logging.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.intel += 4; o.credibility += 3; o.tactical += 1;
        o.notes.push_back("Comm degradation plausible; logs requested by panel.");
        cout << "\nYou describe a brief comm fade on one frequency; Raven 5's warning may not have been received by the maneuver net. Panel asks for radio logs.\n";
    } else if (c == 2) {
        o.tactical += 2; o.credibility -= 3; o.unit_care -= 4;
        o.notes.push_back("Prioritizing movement over JTAC guidance raised questions about judgement.");
        cout << "\nYou justify that stopping movement was assessed as higher risk and the team executed. Panel will examine whether that judgement was sound.\n";
    } else {
        o.credibility -= 5; o.intel -= 2; o.notes.push_back("Admitted mis-sequencing; panel notes need for better SOP adherence.");
        cout << "\nYou admit the sequence error. Panel notes this candid admission but sees risk to accountability.\n";
    }
    pause();
    show_status(o);

    // Option to present log excerpts (E)
    cout << "\nPANEL MEMBER D: We will now allow you to present up to THREE log excerpts or transcripts to corroborate your account. You may choose any combination from the following list (some are classified):\n";
    for (size_t i = 0; i < excerpts.size(); ++i) {
        cout << (i+1) << ") " << excerpts[i].id << " - " << excerpts[i].title;
        if (excerpts[i].classified) cout << " [CLASSIFIED]";
        cout << "\n";
    }
    cout << "0) Present none (decline to release now)\n";
    cout << "Select up to 3 excerpts separated by spaces (e.g., '1 3 5') or '0' to skip: ";
    string line;
    getline(cin, line);
    vector<int> picks;
    {
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v == 0) { picks.clear(); break; }
            if (v >= 1 && v <= (int)excerpts.size()) picks.push_back(v-1);
        }
    }
    if (!picks.empty()) {
        int presented = 0;
        for (int idx : picks) {
            if (presented >= 3) break;
            auto &ex = excerpts[idx];
            cout << "\n---- PRESENTING " << ex.id << " : " << ex.title << " ----\n";
            cout << ex.content << "\n";
            presented++;
            // Effects: releasing classified reduces political risk if properly authorized, else increases
            if (ex.classified) {
                cout << "(This excerpt is classified; did you assert release authority? 1) Yes (I authorize release)  2) No)\n";
                cout << "Choice: ";
                int auth = get_choice(1,2);
                if (auth == 1) {
                    o.transparency += 8; o.credibility += 6; o.political_risk -= 8;
                    o.notes.push_back("Authorized classified log release: " + ex.id);
                } else {
                    o.transparency += 2; o.credibility += 1; o.political_risk += 10;
                    o.notes.push_back("Refused classified release for " + ex.id + " — raised political suspicion.");
                    cout << "Panel notes refusal to release classified material. They will request chain-of-command authorization.\n";
                }
            } else {
                o.transparency += 5; o.credibility += 4; o.notes.push_back("Released unclassified log: " + ex.id);
                cout << "(Unclassified excerpt presented.)\n";
            }
        }
    } else {
        cout << "\nYou declined to release excerpts now. Panel marks this for follow-up subpoena.\n";
        o.credibility -= 6; o.political_risk += 8; o.notes.push_back("Declined to release excerpts — raised suspicion.");
    }
    pause();
    show_status(o);

    // Question 6: CASEVAC specifics (F)
    cout << "\nPANEL MEMBER E (medical): There was a delay in CASEVAC for two wounded (one with femoral artery injury). Explain the timeline of the medevac request and why CASEVAC ETA extended beyond the doctrinal 15 minutes.\n";
    cout << "1) The LZ was constrained and hot; Raven 5 could not clear a safe approach immediately; we delayed landing until suppression achieved.\n";
    cout << "2) We requested CASEVAC immediately, but available MEDEVAC assets were engaged elsewhere; our call for dedicated CASEVAC came with 18-minute ETA.\n";
    cout << "3) We moved casualties to a holding point to stabilize before CASEVAC to increase survivability; this consumed additional time but was deliberate.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.unit_care -= 2; o.tactical += 3; o.civilian_impact += 1;
        o.notes.push_back("LZ safety cited; panel will review medical timelines.");
        cout << "\nYou explain LZ constraints and that the landing zone could not be cleared safely. Panel acknowledges constraint but asks whether different tactic could have reduced delay.\n";
    } else if (c == 2) {
        o.credibility += 3; o.unit_care -= 1; o.notes.push_back("MEDEVAC availability problem documented; external factor.");
        cout << "\nYou state MEDEVAC assets were tied up; panel will cross-check theater medevac busy logs.\n";
    } else {
        o.unit_care += 5; o.civilian_impact += 2; o.credibility += 2;
        o.notes.push_back("Stabilization prioritized before CASEVAC improved perceived care.");
        cout << "\nYou prioritized stabilization in a relative safehold to increase survival odds. Panel praises focus on lives but again examines trade-offs.\n";
    }
    pause();
    show_status(o);

    // Question 7: ROE and use of heavy force near civilian structures (C)
    cout << "\nPANEL CHAIR: There are allegations of excessive force near the market stalls and family dwellings. How do you account for this while complying with ROE that requires PID near civilian structures?\n";
    cout << "1) All use of heavy suppressive fire was in direct response to hostile fire originating from fortified positions; we complied with ROE.\n";
    cout << "2) In a few cases we may have used heavier suppression than intended; I accept responsibility and will support after-action review.\n";
    cout << "3) I maintain that in split-second life-or-death choices, our actions were proportional — hindsight is easier.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 4; o.civilian_impact -= 2; o.notes.push_back("Asserts ROE compliance; legal office will audit fire logs.");
        cout << "\nYou maintain compliance; panel asks for weapon logs and sensor footage to verify.\n";
    } else if (c == 2) {
        o.transparency += 6; o.credibility += 3; o.civilian_impact += 4;
        o.notes.push_back("Accepted possible excess force — increased transparency.");
        cout << "\nYou acknowledge possible excess. Panel appreciates candor but notes the seriousness.\n";
    } else {
        o.credibility -= 2; o.transparency -= 3; o.political_risk += 8;
        o.notes.push_back("Defensive posture may be perceived as evasive.");
        cout << "\nPanel acknowledges stress of combat but warns that dismissive answers will not satisfy public scrutiny.\n";
    }
    pause();
    show_status(o);

    // Question 8: Chain of command & request for reinforcements timing
    cout << "\nPANEL MEMBER F: Why did you not request theater-level reinforcement (additional rotary-wing support and armored vehicles) until 0250Z when initial contact began at ~0212Z? Could earlier request have altered outcome?\n";
    cout << "1) I did request additional assets at 0216Z but the request was vectored through theater nets and confirmation came later; logs will show.\n";
    cout << "2) I judged that immediate local QRF with stealth insertion would limit footprint and that theater reinforcements risked escalation and civilian harm.\n";
    cout << "3) I wanted to minimize air signatures to avoid political escalation given nearby diplomatic zones; I accepted higher tactical risk temporarily.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 6; o.intel += 2; o.notes.push_back("Claims early request; panel will verify with theater logs.");
        cout << "\nYou state you made an earlier theater request and ordered local QRF. Panel will check theater asset request timestamps.\n";
    } else if (c == 2) {
        o.tactical += 2; o.unit_care -= 3; o.political_risk -= 2;
        o.notes.push_back("Tried to limit footprint; panel worries about under-resourcing immediate fight.\n");
        cout << "\nYou explain prioritizing limited footprint; panel debates whether that was the correct calculus given casualties.\n";
    } else {
        o.political_risk -= 3; o.tactical -= 5; o.credibility -= 3;
        o.notes.push_back("Political considerations prioritized; panel concerned of undue political influence on tactical decisions.");
        cout << "\nYou indicate political sensitivity shaped your decision. Panel is wary when politics drives immediate tactical choices.\n";
    }
    pause();
    show_status(o);

    // Question 9: Handling of local civilians & rumor control (D)
    cout << "\nPANEL MEMBER G (civil affairs): A local journalist reported civilian casualties and alleges a cover-up. Describe how you handled civilian casualty reporting and local engagement—did you send civil affairs or control rumors?\n";
    cout << "1) We immediately dispatched a Civil Affairs node and an interpreter to document and provide humanitarian assistance where safe.\n";
    cout << "2) We sanitized initial statements to prevent panic and protect sources; full disclosure came after classification review.\n";
    cout << "3) We prioritized operational security; rumor control was handled at higher echelons, not by our element.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.civilian_impact += 8; o.credibility += 4; o.notes.push_back("Immediate civil affairs response increased perceived care.");
        cout << "\nYou describe deploying civil affairs and medical NGOs to the area once the perimeter was stable. Panel notes this as a positive mitigating action.\n";
    } else if (c == 2) {
        o.transparency -= 2; o.credibility -= 1; o.political_risk += 5;
        o.notes.push_back("Sanitized initial statements raised suspicion despite intended stability reasons.");
        cout << "\nYou say statements were limited to prevent panic. Panel will evaluate whether that equated to concealment.\n";
    } else {
        o.credibility -= 6; o.political_risk += 8; o.civilian_impact -= 5;
        o.notes.push_back("Deferring rumor control reduced perceived accountability.");
        cout << "\nPanel frowns: leaving rumor control solely to higher echelons can be perceived as avoidance of responsibility.\n";
    }
    pause();
    show_status(o);

    // Question 10: If you could change one tactical SOP (closing question)
    cout << "\nPANEL CHAIR: If you could change one SOP or tactical choice you made on this mission to improve outcomes, what is it?\n";
    cout << "1) Institute a dedicated downed-aircraft immediate-recovery element with predefined CASEVAC LZs and armored support.\n";
    cout << "2) Require two-source HUMINT confirmation for HVT operations in dense urban markets before kinetic action.\n";
    cout << "3) Prioritize expanding comm architecture with redundant satcom and relay nodes to avoid JTAC/maneuver disconnects.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.tactical += 8; o.unit_care += 6; o.credibility += 4;
        o.notes.push_back("Recommend pre-staged recovery element for future ops.");
        cout << "\nYou propose pre-staged recovery elements and armored support for downed aircraft; panel notes this as a valuable doctrinal change.\n";
    } else if (c == 2) {
        o.intel += 9; o.credibility += 3;
        o.notes.push_back("Recommend stricter HUMINT vetting for urban raids.");
        cout << "\nYou propose stricter HUMINT confirmation for urban HVT ops. Panel sees systemic benefit.\n";
    } else {
        o.intel += 5; o.tactical += 3; o.notes.push_back("Recommend better comm redundancy.");
        cout << "\nYou recommend improved comm redundancy; panel will forward this to communications command.\n";
    }
    pause();
    show_status(o);

    // Final statement options
    cout << "\nPANEL: Final statement before we adjourn. Choose your tone and content.\n";
    cout << "1) Full apology and pledge to cooperate fully with investigators, including immediate release of unclassified logs and chain-of-command authorization for classified logs.\n";
    cout << "2) Firm defense of decisions with an assertive request that operational context be considered before public judgment.\n";
    cout << "3) Decline to make substantive comments without legal counsel and delegate to staff.\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.transparency += 10; o.credibility += 6; o.unit_care += 5; o.political_risk -= 5;
        o.notes.push_back("Apology + cooperation improved outcomes.");
        cout << "\nYou apologize for any harm, pledge full cooperation, and offer to immediately release unclassified logs and request chain-of-command approval for classified ones.\n";
    } else if (c == 2) {
        o.credibility += 4; o.transparency -= 3; o.political_risk += 4;
        o.notes.push_back("Defensive posture left mixed impressions.");
        cout << "\nYou defend your decisions and ask that context be considered. Panel accepts but warns that evidence must support the narrative.\n";
    } else {
        o.credibility -= 6; o.transparency -= 8; o.political_risk += 12;
        o.notes.push_back("Declining comment after intense questioning raised red flags.");
        cout << "\nYou decline substantive comment without legal counsel. Panel notes your legal prerogative but marks this in the record.\n";
    }
    pause();

    // Random external influences
    int randmod = (rand() % 21) - 10; // -10..+10
    o.credibility = clamp(o.credibility + randmod, 0, 100);
    o.political_risk = clamp(o.political_risk - randmod/2, 0, 100);

    cout << "\nThe panel will consult theater logs, witness statements, and independent ISR. Based on the metrics accumulated, an adjudication will be delivered.\n";
    pause();
    final_adjudication(o);

    cout << "\nDEBRIEF SUMMARY NOTES:\n";
    for (auto &n: o.notes) {
        cout << "- " << n << "\n";
    }

    cout << "\nSimulation complete. Thank you. End of exercise.\n";
    return 0;
}