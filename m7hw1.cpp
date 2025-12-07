// debrief.cpp
// Single-file interactive text game: "After Action — Mogadishu Debrief (inspired by Black Hawk Down)"
// Compile: g++ -std=c++17 -O2 -o debrief debrief.cpp
// Run: ./debrief

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

void pause() {
    cout << "\n(press Enter to continue)";
    std::string tmp;
    std::getline(cin, tmp);
}

int get_choice(int minc, int maxc) {
    while (true) {
        string line;
        std::getline(cin, line);
        try {
            int c = std::stoi(line);
            if (c >= minc && c <= maxc) return c;
        } catch(...) {}
        cout << "Please enter a number between " << minc << " and " << maxc << ": ";
    }
}

struct Outcome {
    int credibility = 50;   // 0-100
    int transparency = 50;  // 0-100
    int unit_care = 50;     // 0-100
    int political_risk = 50; // 0-100 (higher = worse)
    vector<string> notes;
};

void show_status(const Outcome &o) {
    cout << "\n--- Current Debrief Status ---\n";
    cout << "Credibility: " << o.credibility << "/100\n";
    cout << "Transparency: " << o.transparency << "/100\n";
    cout << "Unit care (perceived): " << o.unit_care << "/100\n";
    cout << "Political risk: " << o.political_risk << "/100\n";
    cout << "-------------------------------\n";
}

void final_adjudication(const Outcome &o) {
    cout << "\n--- PANEL ADJUDICATION ---\n";
    if (o.credibility >= 70 && o.transparency >= 60 && o.unit_care >= 60 && o.political_risk <= 60) {
        cout << "Panel decision: CLEARED WITH RECOMMENDATION.\n";
        cout << "Summary: Your account was credible, transparent, and showed command concern. Recommendations: debrief improvements and tactical refinements.\n";
    } else if (o.credibility >= 50 && o.transparency >= 40 && o.unit_care >= 40) {
        cout << "Panel decision: FORMAL REPRIMAND.\n";
        cout << "Summary: Questions remain about decisions and risk management. You will receive a formal reprimand and corrective action orders.\n";
    } else {
        cout << "Panel decision: RELIEVED OF COMMAND / FURTHER INVESTIGATION.\n";
        cout << "Summary: The panel found serious issues with judgement and transparency. You are relieved pending formal investigation.\n";
    }
    cout << "--------------------------\n\n";
}

int main() {
    std::srand((unsigned)std::time(nullptr));
    Outcome o;
    cout << "AFTER-ACTION DEBRIEF\n";
    cout << "Mission: Night raid to capture high-value target in a chaotic urban environment.\n";
    cout << "Note: This interactive debrief is inspired by real events (1993 Mogadishu). It is a fictionalized, respectful exercise in leadership, decision-making, and accountability.\n\n";
    cout << "You are the Special Operations commander. A mission to capture a key target went sideways: vehicles were damaged, casualties occurred, and the situation required on-the-spot decisions.\n";
    cout << "A panel of your superiors will ask pointed questions. Your answers will affect whether you are cleared, formally reprimanded, or relieved.\n\n";
    pause();

    cout << "\nPANEL CHAIR: Commander, begin your report. Give us a concise timeline of events from insertion to extraction.\n";
    cout << "You may choose how to present the timeline.\n\n";
    cout << "1) Give a short, factual timeline emphasizing key timestamps.\n";
    cout << "2) Provide a narrative timeline that includes your intentions and reasoning.\n";
    cout << "3) Give a terse timeline and defer many details to the appendix.\n\n";
    cout << "Choice: ";
    int c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 5;
        o.transparency += 0;
        o.notes.push_back("Presented clear times and phases; appreciated by chair.");
        cout << "\nYou deliver clear timestamps: insertion at 0200, link-up at 0235, target secured attempt 0245, contact escalation at 0250, extraction call at 0400.\n";
        cout << "Panel: 'Clear. We'll want supporting logs.'\n";
    } else if (c == 2) {
        o.credibility += 8;
        o.transparency += 8;
        o.notes.push_back("Narrative provided context: intent and decisions were clearer.");
        cout << "\nYou walk the panel through your intent: you explain the phases and why you made hard calls when enemy activity spiked.\n";
        cout << "Panel: 'We appreciate the context; evidence will be cross-checked.'\n";
    } else {
        o.credibility -= 10;
        o.transparency -= 15;
        o.notes.push_back("Deferring details made panel wary.");
        cout << "\nYou provide a terse timeline and say the rest is in the appendix. The panel bristles — they want the commander present and accountable now.\n";
        cout << "Panel: 'This is a live debrief. Be present.'\n";
    }
    pause();
    show_status(o);

    cout << "\nPANEL MEMBER A: Evidence shows two helicopters were shot down and several men were isolated. We need to know why vehicles moved into that intersection instead of holding on the safer alley approaches. What informed your route choice?\n\n";
    cout << "1) I chose the route based on human intelligence placing the target at that compound and minimizing civilian exposure.\n";
    cout << "2) I chose the route to maintain radio line-of-sight and coordinate supporting elements.\n";
    cout << "3) We improvised route due to fast-moving ground congestion and evolving cues on the ground.\n\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 5; o.transparency += 2; o.unit_care += 3;
        o.notes.push_back("Route justified on protecting civilians; partially verified.");
        cout << "\nYou emphasize the attempt to limit collateral harm; panel nods but asks for the intel source and confirmation level.\n";
    } else if (c == 2) {
        o.credibility += 3; o.transparency += 0; o.political_risk += 5;
        o.notes.push_back("Technical communication justification; seen as mixed by panel.");
        cout << "\nYou explain line-of-sight and comm considerations. Panel asks if comm design overrode force protection — they want to ensure priorities were right.\n";
    } else {
        o.credibility -= 5; o.transparency -= 5; o.unit_care -= 5; o.political_risk += 10;
        o.notes.push_back("Improvisation answer raised concerns about planning.");
        cout << "\nYou admit improvisation. Panel is concerned: improvisation is sometimes necessary, but they want to know why contingencies failed.\n";
    }
    pause();
    show_status(o);

    cout << "\nPANEL MEMBER B: Witnesses — including a forward air controller and an interpreter — reported a delay between the first engagement and your decision to request immediate reinforcement. Why the delay?\n\n";
    cout << "1) We assessed the contact as containable while we secured the objective; I chose to hold reinforcement to avoid escalation.\n";
    cout << "2) Communications were degraded temporarily; by the time the scope became clear I had already sent an emergency beacon.\n";
    cout << "3) I prioritized recovering isolated personnel myself before calling larger reinforcements to reduce overall footprint.\n\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility -= 5; o.transparency -= 3; o.unit_care -= 10;
        o.notes.push_back("Holding reinforcements viewed as underestimating risk.");
        cout << "\nYou explain risk-calculation; panel worries that priority may have placed personnel at unnecessary risk.\n";
    } else if (c == 2) {
        o.credibility += 4; o.transparency += 6; o.notes.push_back("Comm failure is plausible; panel will examine logs.");
        cout << "\nYou explain comm degradation. Panel asks for logs; this answer is considered plausible but will be validated.\n";
    } else {
        o.credibility -= 3; o.transparency += 2; o.unit_care += 5; o.political_risk += 5;
        o.notes.push_back("Personal recovery attempt seen as valorous but risky.");
        cout << "\nYou admit you attempted a personal recovery. Panel respects the intent but is concerned about command-level risk-taking.\n";
    }
    pause();
    show_status(o);

    cout << "\nPANEL CHAIR: There are allegations of rules-of-engagement breaches during the urban firefight, including use of heavy force near civilian structures. How do you respond?\n\n";
    cout << "1) We followed ROE; any heavy force was returned fire to suppress threats and protect personnel.\n";
    cout << "2) Some actions exceeded intended thresholds — I accept responsibility and will cooperate with the review.\n";
    cout << "3) The situation on the ground required split-second decisions; applying ROE in hindsight is easier than in contact.\n\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 3; o.transparency -= 2; o.unit_care += 2;
        o.notes.push_back("Strong legal stance; panel will verify with weapons logs.");
        cout << "\nYou assert compliance. The legal officer will request weapons and sensor logs to confirm.\n";
    } else if (c == 2) {
        o.credibility += 5; o.transparency += 8; o.notes.push_back("Accepting responsibility raises transparency and credibility.");
        o.unit_care += 5;
        cout << "\nYou accept that some actions may have exceeded thresholds and pledge cooperation. Panel responds positively to candor but stresses the gravity.\n";
    } else {
        o.credibility -= 2; o.transparency -= 5; o.political_risk += 8;
        o.notes.push_back("Defensive justification seen as potentially evasive.");
        cout << "\nYou emphasize the chaos of combat. Panel is sympathetic but expects clear accounting for each use of force.\n";
    }
    pause();
    show_status(o);

    cout << "\nPANEL MEMBER C: A reporter alleges a cover-up of the extent of casualties and damaged aircraft. You can either open all logs now or push back citing ongoing operations. What do you do?\n\n";
    cout << "1) Open all logs, telemetry, and after-action footage immediately to investigators.\n";
    cout << "2) Provide a summary now and say detailed logs will be provided after classification review.\n";
    cout << "3) Push back: an immediate release would compromise sources; provide only sanitized info.\n\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.transparency += 15; o.credibility += 10; o.political_risk -= 10;
        o.notes.push_back("Full cooperation greatly increased perceived transparency.");
        cout << "\nYou authorize immediate access to logs for the investigating board. Panel is impressed with full cooperation.\n";
    } else if (c == 2) {
        o.transparency += 2; o.credibility += 0; o.political_risk += 5;
        o.notes.push_back("Partial compliance seen as cautious.");
        cout << "\nYou offer a summary and promise a full release after classification checks. Panel accepts but marks this for follow-up.\n";
    } else {
        o.transparency -= 10; o.credibility -= 10; o.political_risk += 20; o.unit_care -= 5;
        o.notes.push_back("Resistance to release raises red flags about cover-up risk.");
        cout << "\nYou resist immediate release citing operational security. Panel grows suspicious and notes press allegations.\n";
    }
    pause();
    show_status(o);

    cout << "\nPANEL CHAIR: Lastly, Governor-level and public attention are increasing. If you could do one thing differently, commander — what would it be?\n";
    cout << "1) I would have staged a more conservative entry and increased overwatch before moving to the objective.\n";
    cout << "2) I would have staged faster casualty extraction and a dedicated recovery element on standby.\n";
    cout << "3) I would have insisted on different human-intel vetting before action.\n\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.credibility += 6; o.unit_care += 5; o.transparency += 2;
        o.notes.push_back("Conservative entry shows force protection awareness.");
        cout << "\nYou show humility and a force-protection lesson. Panel values the measured after-action learning.\n";
    } else if (c == 2) {
        o.credibility += 4; o.unit_care += 10; o.transparency += 2;
        o.notes.push_back("Prioritizing casualty extraction shows concern for personnel.");
        cout << "\nYou emphasize prioritizing lives and MEDEVAC readiness. Panel notes this positively.\n";
    } else {
        o.credibility += 2; o.transparency += 6; o.notes.push_back("Intel vetting focus indicates systemic improvement.");
        cout << "\nYou pin the issue on intel reliability and suggest procedural reforms. Panel will consider intel-side recommendations.\n";
    }
    pause();

    cout << "\nPANEL: Any final statement before we adjourn?\n";
    cout << "1) Short apology and pledge to cooperate fully.\n";
    cout << "2) Forceful defense of decisions and request for operational context to be considered publicly.\n";
    cout << "3) Refuse to comment further until counsel and legal review.\n\n";
    cout << "Choice: ";
    c = get_choice(1,3);
    if (c == 1) {
        o.transparency += 8; o.credibility += 5; o.unit_care += 5;
        o.notes.push_back("Apology softened panel and increased faith in leadership.");
        cout << "\nYou apologize to any affected parties, pledge to answer all questions, and emphasize lessons learned.\n";
    } else if (c == 2) {
        o.credibility += 3; o.transparency -= 5; o.political_risk += 5;
        o.notes.push_back("Forceful defense left mixed impressions.");
        cout << "\nYou defend your decisions strongly; panel takes note but asks for supporting evidence.\n";
    } else {
        o.credibility -= 5; o.transparency -= 8; o.political_risk += 10;
        o.notes.push_back("Refusal to comment raised significant concerns.");
        cout << "\nYou decline further comment pending counsel. Panel notes your legal prerogative but expects cooperation.\n";
    }
    pause();
    show_status(o);

    // small random modifier to emulate external political pressure or mitigating evidence
    int rand_mod = (std::rand() % 21) - 10; // -10..+10
    o.credibility = std::clamp(o.credibility + rand_mod, 0, 100);
    o.political_risk = std::clamp(o.political_risk - rand_mod/2, 0, 100);

    cout << "\nThe investigating board will now consult classified logs, witness statements, and intelligence reports. Your immediate fate will be determined.\n";
    pause();

    final_adjudication(o);

    cout << "DEBRIEF NOTES (for records):\n";
    for (const auto &n : o.notes) {
        cout << "- " << n << "\n";
    }
    cout << "\nThank you. End of exercise.\n";
    return 0;
}
