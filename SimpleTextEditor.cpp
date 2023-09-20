#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function accepts following parameters:
 *  1. STRING q
 *  2. STACK<STRING> &stringHistory
 */
void editText(string q, stack<string> &stringHistory) {
    char query = q.at(0);
    string w;
    int k;
    string s;
    if(!stringHistory.empty()) {
        s = stringHistory.top();
    } else {
        s = "";
    }
    switch (query)
    {
    case '1':
        w = q.substr(2, q.size() - 2);
        stringHistory.push(s.append(w));
        break;
    case '2':
        k = stoi(q.substr(2, q.size() - 2));
        if(k <= s.size()) {
            stringHistory.push(s.substr(0, s.size() - k));
        } else {
            stringHistory.push("");
        }
        break;
    case '3':
        k = stoi(q.substr(2, q.size() - 2));
        if(k <= s.size()) cout << s.at(k - 1) << endl;
        break;
    case '4':
        if(!stringHistory.empty()) stringHistory.pop();
        break;
    default:
        break;
    }
}

int main()
{
    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp))); // Number of operations

    stack<string> stringHistory;

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string q_temp;
        getline(cin, q_temp);

        string q = ltrim(rtrim(q_temp));

        editText(q, stringHistory);
    }
    cout << "TERMINADO";
    return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}