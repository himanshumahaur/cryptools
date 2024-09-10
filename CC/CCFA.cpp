#include <bits/stdc++.h>
using namespace std;

vector<float> stdFat = {8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};
string LOGO = "\n                 ______   ______   ______   ___\n                / ____/  / ____/  / ____/  /   |\n  Himanshu     / /      / /      / /_     / /| | > Message: [A-Z][a-z] Other symbols are ignored.\n   Mahaur     / /___   / /___   / __/    / ___ | > Key: Numeric & Alphabet keys supported.\n 2024PIS5020  \\____/   \\____/  /_/      /_/  |_|\n               CAESAR CIPHER FREQUENCY ANALYSIS\n";

void error(string e) {
    string red = "\033[31m";
    string rem = "\033[0m";
    cout << red + e + rem;
}

void success(string e) {
    string grn = "\033[32m";
    string rem = "\033[0m";
    cout << grn + e + rem;
}

string encr(string msg, int key) {
    string cip;
    for(auto i:msg) isalpha(i) ? cip += char((toupper(i) - 'A' + key) % 26 + 'A') : cip += ' ';
    return cip;
}

string decr(string cip, int key) {
    string msg;
    for(auto i:cip) isalpha(i) ? msg += char((26 + toupper(i) - 'A' - key) % 26 + 'A') : msg += ' ';
    return msg;
}

string clnr(string msg) {
    string clnMsg;
    for(auto i:msg) if(isalpha(i)) clnMsg += toupper(i);
    return clnMsg;
}

vector<float> fanr(string msg) {
    vector<float> fat(26);
    for(auto i:msg) fat[i-'A']++;
    for(int i=0; i<26; i++) fat[i] = 100 * fat[i] / msg.length();
    return fat;
}

bool cmp(const pair<char, float> &a, const pair<char, float> &b) {
    return b.second > a.second;
}

int main() {
    cout << LOGO;

    string stdMsg = "IN A WORLD WHERE TECHNOLOGY DRIVES PROGRESS AND INNOVATION LEADS THE WAY PEOPLE FIND THEMSELVES IMMERSED IN A CONSTANT STREAM OF INFORMATION EVERY DAY BRINGS NEW DISCOVERIES CHALLENGES AND OPPORTUNITIES PUSHING HUMANITY TO REACH GREATER HEIGHTS THE RISE OF ARTIFICIAL INTELLIGENCE AND MACHINE LEARNING TRANSFORMS INDUSTRIES AND SHAPES THE FUTURE IN WAYS UNIMAGINABLE JUST A FEW YEARS AGO AS WE EMBARK ON THIS JOURNEY INTO THE UNKNOWN WE MUST REMEMBER THE IMPORTANCE OF ETHICS RESPONSIBILITY AND COLLABORATION EVERY ADVANCEMENT WHETHER IN MEDICINE COMMUNICATION OR ENERGY COMES WITH ITS OWN SET OF CONSEQUENCES IT IS OUR DUTY TO ENSURE THAT THESE CONSEQUENCES ARE UNDERSTOOD AND MANAGED EFFECTIVELY KNOWLEDGE IS POWER BUT WISDOM IS THE KEY TO USING THAT POWER FOR THE GREATER GOOD AS WE NAVIGATE THIS NEW ERA WE MUST BALANCE INNOVATION WITH CONSIDERATION FOR THE ENVIRONMENT AND THE WELL BEING OF ALL LIVING BEINGS SCIENTISTS ENGINEERS AND THINKERS FROM AROUND THE GLOBE WORK TOGETHER TO SOLVE SOME OF THE WORLDS MOST PRESSING PROBLEMS WHETHER IT IS CLIMATE CHANGE RESOURCE SCARCITY OR SOCIAL INEQUALITY THESE CHALLENGES REQUIRE A UNIFIED AND HOLISTIC APPROACH THE FUTURE IS NOT SOMETHING THAT SIMPLY HAPPENS TO US IT IS SOMETHING WE CREATE THROUGH OUR ACTIONS DECISIONS AND COLLECTIVE VISION AS WE MOVE FORWARD LET US STRIVE TO BUILD A WORLD THAT IS NOT ONLY MORE ADVANCED BUT ALSO MORE COMPASSIONATE JUST AND SUSTAINABLE LET US FOSTER A CULTURE OF CURIOSITY AND LIFELONG LEARNING ENCOURAGING PEOPLE OF ALL AGES TO QUESTION EXPLORE AND GROW IN THIS AGE OF RAPID CHANGE ADAPTABILITY AND RESILIENCE ARE CRUCIAL WE MUST EMBRACE DIVERSITY IN ALL ITS FORMS RECOGNIZING THAT DIFFERENT PERSPECTIVES LEAD TO RICHER SOLUTIONS AND MORE INCLUSIVE OUTCOMES TECHNOLOGY ALONE CANNOT SOLVE THE WORLDS PROBLEMS IT IS THE HUMAN SPIRIT WITH ITS INNATE CREATIVITY AND COMPASSION THAT WILL ULTIMATELY GUIDE US TOWARD A BRIGHTER FUTURE WE MUST NOT LOSE SIGHT OF THE VALUES THAT DEFINE US AS A SPECIES EMPATHY COOPERATION AND THE DESIRE TO LEAVE THE WORLD A BETTER PLACE FOR FUTURE GENERATIONS AS WE STAND ON THE CUSP OF NEW DISCOVERIES AND POSSIBILITIES LET US REMEMBER THAT THE TRUE MEASURE OF PROGRESS IS NOT JUST IN THE TECHNOLOGIES WE DEVELOP BUT IN HOW WE USE THEM TO ENRICH THE HUMAN EXPERIENCE IN THE END IT IS NOT THE MACHINES THAT WILL SHAPE OUR DESTINY BUT THE HEARTS AND MINDS OF THE PEOPLE WHO DESIGN BUILD AND INTERACT WITH THEM LET US EMBRACE THE CHALLENGES AHEAD WITH COURAGE CREATIVITY AND A DEEP COMMITMENT TO THE COMMON GOOD THE FUTURE IS OURS TO SHAPE AND TOGETHER WE CAN CREATE A WORLD THAT REFLECTS THE BEST OF HUMANITY";
    
    string rawMsg;
    string encMsg;

    string clnMsg;
    string cenMsg;

    string keyInp;

    int key;

    while(true) {
        cout << "\nEnter Message (RETURN FOR DEFAULT): ";
        getline(cin, rawMsg);

        if(!rawMsg.length()) rawMsg = stdMsg;
        
        clnMsg = clnr(rawMsg);

        if(clnMsg.length()) {
            break;
        }
        else {
            error("Error: No alphabets found.\n");
        }
    }

    while(true) {
        cout << "\nEnter Key: ";
        getline(cin, keyInp);
        try {
            if(isalpha(keyInp[0])) key = toupper(keyInp[0]) - 'A';
            else if(isdigit(keyInp[0])) key = stoi(keyInp);
            else throw invalid_argument("NaN");
            break;
        }
        catch(invalid_argument& e) {
            error("Error: The key entered is not a number.\n");
        }
    }

    encMsg = encr(rawMsg, key);

    cout << "\nOriginal Message\t:\t" << (rawMsg.size() < 40 ? rawMsg : rawMsg.substr(0, 40) + "...") << endl;
    cout << "Encrypted Message\t:\t" << (encMsg.size() < 40 ? encMsg : encMsg.substr(0, 40) + "...") << endl;

    clnMsg = clnr(rawMsg);
    cenMsg = encr(clnMsg, key);

    vector<pair<char, float>> resFat;

    for(int k=0; k<26; k++) {
        string curMsg = decr(encMsg, k);
        vector<float> curFat= fanr(curMsg);
        resFat.push_back({'A'+k, 0});
        for(int i=0; i<26; i++) resFat[k].second += pow(curFat[i] - stdFat[i], 2)/stdFat[i];
    }

    sort(resFat.begin(), resFat.end(), cmp);

    cout << "\n|\t" << "ORDER" << "\t|\t" << "KEY" << "\t|\t" << "SHIFT" << "\t\t|\n";
    for(int i=0; i<26; i++) cout << "|\t" << i + 1 << "\t|\t" << resFat[i].first << "\t|\t" << resFat[i].second << "\t\t|\n";

    success("\nSuccess: Table generatated.\n");
    return 0;
}