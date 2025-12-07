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

    cout <<

