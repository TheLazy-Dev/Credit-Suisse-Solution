#include <bits/stdc++.h>

using namespace std;
int fun(int n, vector<vector<int>> a,int m , vector<vector<int>> b)
{
        map<int,set<int>> mp;
        long unsigned int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(auto j: a[i-1])
            {
                mp[j].insert(i);
                if(sum < mp[j].size())
                {
                    sum=mp[j].size();
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(auto j:b[i-1])
            {
                mp[i].insert(j);
               if(sum<mp[i].size())
                        sum=mp[i].size();
            }
        }
     
        return sum;
}
int calculateMinimumSession(int numOfBankers, int numOfParticipants, vector<vector<int>> bankersPreferences, vector<vector<int>> participantsPreferences) {
    // Participant's code will go here 
    int ans=0;
    if(numOfParticipants>numOfBankers)
    {
        ans=fun(numOfParticipants,participantsPreferences,numOfBankers,bankersPreferences);
    }
    else
    {
       ans= fun(numOfBankers,bankersPreferences,numOfParticipants,participantsPreferences);
    }
    return ans;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    int numOfBankers, numOfParticipants;
    vector<vector<int>> bankersPreferences, participantsPreferences;

    cin >> numOfBankers;

    string bankersPreferencesStr;
    cin >> bankersPreferencesStr;
    vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

    for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin(); i != bankersPreferencesVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
        bankersPreferences.push_back(bankerPreferenceVecByAnd);
    }

    string participantsPreferencesStr;
    cin >> numOfParticipants;
    cin >> participantsPreferencesStr;
    vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

    for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin(); i != participantsPreferencesVecByComma.end(); ++i) {
        vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
        participantsPreferences.push_back(participantPreferenceVecByAnd);
    }

    int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
