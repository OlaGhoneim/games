
// File:  A1_T1_NoSection_20231232.cpp
// Purpose: problem 3,6,9,12
// Author:Ola Ghoneim Hammad Ahmed Salama
// Section: N0 section
// ID: 20231232

#include <bits/stdc++.h>
using namespace std;
# include <fstream>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tests int t; cin >> t; while(t--)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define ll long long
#define el '\n'

// problem 3
void p1() {
    string s;    string d;

    cout << "Please enter the target: " << el;

    getline(cin, s); // Get the target string
    getline(cin, s); // Get the target string

    cout << "Please enter the delimiter: " << el;
  getline(cin, d);; // Get the delimiter

    vector<string> v;
   int position = 0;

    // While there is a delimiter in the string
    while ((position = s.find(d)) != string::npos) {
        v.push_back(s.substr(0, position));  // Add substring before the delimiter
        s.erase(0, position + d.length());   // Remove the finished part including the delimiter
    }

    // Push the last remaining part of the string
    v.push_back(s);

    // Print the result with the required format
    for (int i = 0; i < v.size(); i++) {
        if (i != (v.size() - 1)) {
            cout << "\"" << v[i] << "\"" << ",";
        } else {
            cout << "\"" << v[i] << "\"";
        }
    }
    cout << el;
}

// problem 6-a

ll recg(ll n){
// base function
    if (n == 0)
    {
        return 0;
    }
// transition state
    return 10*recg(n / 2)+n % 2;

}
void p2a() {
    cout<<"please : Enter the decimal number :";
    ll n;
    cin >> n;
// calling recursion fn
    cout<<recg(n)<<endl;
}
// problem 6-b
void p2b() {
    vector <ll >po;


    string s;int k;
    cout<<"please : Enter the string :";
    cin>>s;
    cout<<"please : Enter k :";
cin>>k;
    ll l=1<<k;// 2^k
    for (int i = 0; i < l; i++) {     // convert from decimal to binary in the range of[0-2^k] and assign to the prefix
        bitset<32> result(i);
        string num = result.to_string();  // Get the full binary representation
        num = num.substr(32 - k);  // Extract the last k bits (cutting the extra leading zeros)

        cout << s << num << el;  // Print the string and binary representation
    }

}
// problem 9
bool re(int n)
{
    //  base case
    if (n == 42) {
        return true;
    }
   else if(n<42) {
        return false;
    }
    //  transition
    // backtracking technique

    else if(n%5==0) {
        if(re(n-42)) {
            return( true);

        }
    }
    if(n%2==0 && re(n/2)) {

            return(true);

        }

    else if(n%3==0||n%4==0) {
        int p=((n % 10 )*((n % 100)/10));
        if(p>0 && re(n-p)) {
            return (true);

        }
    }

    return false;

}
void p3() {
    cout<<"Now, we can check if the entered number could be 42 or not "<<el;
    cout<<"Enter the number :"<<el;
    int n;
    cin>>n;

    if(re(n)) { // calling the fn that follow backtracking technique
        cout<<"true"<<el;
    }
    else
        cout<<"false"<<el;
}
// problem 12: files
void p4() {
    cout << "Please write the filename : " <<" "<<"it is caled \"email.txt \"  : "<< el;
    string filename;
  cin>>filename;
    // create list of 30 words and store in the map
    map<string ,int>mp;
    mp["account"] = 3;
    mp["credit card"] = 3;
    mp["password"] = 3;
    mp["verify"] = 3;
    mp["urgent"] = 3;
    mp["login"] = 2;
    mp["bank"] = 2;
    mp["security alert"] = 3;
    mp["confirm"] = 2;
    mp["social security"] = 3;
    mp["click here"] = 2;
    mp["update"] = 2;
    mp["limited time"] = 3;
    mp["free"] = 1;
    mp["suspicious activity"] = 3;
    mp["promotion"] = 2;
    mp["congratulations"] = 1;
    mp["check"] = 2;
    mp["money order"] = 3;
    mp["social security number"] = 3;
    mp["investment portfolio"] = 2;
    mp["giveaway"] = 1;
    mp["get out of debt"] = 2;
    mp["security update"] = 3;
    mp["fraudulent activity"] = 3;
    mp["prize"] = 1;
    mp["limited offer"] = 2;
    mp["unauthorized transaction"] = 3;
    mp["reset password"] = 3;
    mp["risk"] = 2;
    mp["immediate attention"] = 3;

    map<string ,int>rp; // map stores  words" required to check it's points" in the text enterd by user
    ll sm=0;

    ifstream myfile (filename);
    string s;
    if(!myfile.is_open()) {
        cout<<"File does not exist"<<endl;
    }

    if (myfile.is_open()) {
        string line;
        while(myfile>>line) {     // read each word in the file
            if(mp.find(line)!=mp.end()) { // check if the word is one of the 30 words in the list
                rp[line]++;
            }
        }
    }
    myfile.close();
    for(auto e:rp) {   // loop on words in the user's email that aren't safe
        sm+=mp[e.first]*e.second;
        cout << "Keyword: " << e.first << " | Occurrences: " << e.second << " | Points: " << mp[e.first] << el;
    }
    cout<<"total points : "<<sm<<el;
}

signed main() {
    bool validInput = false;

    int choice;
    int close;
while (true) {
    cout << "Welcome to my program" << endl;
    cout << "Please select an option" << endl;
    cout << "1 > splitting function" << endl;
    cout << "2 > convert to binary" << endl;
    cout << "3 > Append to the string" << endl;
    cout << "4 > teddy Bear Picnic." << endl;
    cout << "5 > files" << endl;
    cout << "6 > End" << endl;

    // menue
    while (!validInput)
    {
        try
        {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 6)
            {
                throw invalid_argument("Invalid input: Please choose a valid option");
            }
            validInput = true;
        }

        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    validInput = false;

    if (choice == 1)
    {
        p1();
    }
    else if (choice == 2)
    {
        p2a();
    }
    else if (choice == 3)
    {
        p2b();
    }
    else if (choice == 4)
    {
        p3();
    }
    else if (choice == 5)
    {
        p4();
    }
    else if ( choice == 6)
    {
        cout << "----------END PROGRAM----------" << endl;
        break;
    }

    cout << "Do you want to end the program?" << endl;
    cout << "1 > End" << endl;
    cout << "2 > continue" << endl;

    while (!validInput)
    {
        try
        {
            cin >> close;
            if (cin.fail() || close < 1 || close > 2)
            {
                throw invalid_argument("Invalid input: Please choose a valid option");
            }
            validInput = true;
        }

        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    validInput = false;

    if (close == 1)
    {
        cout << "----------END PROGRAM----------" << endl;
        break;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
    }
}

    return 0;
}