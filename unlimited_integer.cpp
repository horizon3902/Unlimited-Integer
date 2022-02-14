/* AKA Coders 
* BT20CSE216 A bhishek Kanojia
* BT20CSE209 K shitij Agarkar
* BT20CSE214 A viral Verma
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class akaBigInt
{
private:
    string s;
    vector<long long int> lli1;
    vector<long long int> lli2;

public:
    akaBigInt()
    {
        string s = "";
    }

    akaBigInt(string s)
    {
        this->s = s;
    }

    string leadingzero(string s)
    {
        int i = 0;

        while (s[i] == '0')
        {
            i++;
        }
        if (i == 18)
        {
            return "0";
        }

        return s.substr(i);
    }

    string fixsize(long long int x)
    {
        string s = to_string(x);
        string s1 = "";
        int limit = 18 - s.length();
        for (int i = 0; i < limit; i++)
        {
            s1 = "0" + s1;
        }
        s = s1 + s;

        return s;
    }

    void chunking(akaBigInt s1, akaBigInt s2)
    {

        int sz1 = s1.s.size();
        int sz2 = s2.s.size();

        int i, j;
        // chunking the string s1
        for (i = sz1 - 18; i >= 0; i -= 18)
        {
            // breaking the string >>>> converting into integer >>>> pushing into the vector lli1
            lli1.push_back(stoll(s1.s.substr(i, 18)) + 1000000000000000000);
            // cout<<" ";
        }
        if (i < 0 && i != -18)
        {

            lli1.push_back(stoll(s1.s.substr(0, 18 + i)));
        }

        for (j = sz2 - 18; j >= 0; j -= 18)
        {
            // breaking the string >>>> converting into integer >>>> pushing into the vector lli1
            lli2.push_back(stoll(s2.s.substr(j, 18)) + 1000000000000000000);
        }
        if (j < 0 && j != -18)
        {

            lli2.push_back(stoll(s2.s.substr(0, 18 + j)));
        }

        reverse(lli1.begin(), lli1.end());
        reverse(lli2.begin(), lli2.end());
    }
    void chunkingspecial(akaBigInt s1, akaBigInt s2)
    {

        int sz1 = s1.s.size();
        int sz2 = s2.s.size();

        int i, j;
        // chunking the string s1
        for (i = sz1 - 18; i >= 0; i -= 18)
        {
            // breaking the string >>>> converting into integer >>>> pushing into the vector lli1
            lli1.push_back(stoll(s1.s.substr(i, 18)) + 1000000000000000000);
            // cout<<" ";
        }
        if (i < 0 && i != -18)
        {

            lli1.push_back(stoll(s1.s.substr(0, 18 + i)) + 1000000000000000000);
        }

        for (j = sz2 - 18; j >= 0; j -= 18)
        {
            // breaking the string >>>> converting into integer >>>> pushing into the vector lli1
            lli2.push_back(stoll(s2.s.substr(j, 18)) + 1000000000000000000);
        }
        if (j < 0 && j != -18)
        {
            lli2.push_back(stoll(s2.s.substr(0, 18 + j)) + 1000000000000000000);
        }

        reverse(lli1.begin(), lli1.end());
        reverse(lli2.begin(), lli2.end());
    }

    string addOp(akaBigInt s1, akaBigInt s2)
    {
        chunking(s1, s2);
        // Addition of two vectors
        vector<string> lli3;
        int carry = 0;

        int l1, l2, op = 0, g = 0;
        for (l1 = lli1.size() - 1, l2 = lli2.size() - 1; (l1 >= 0) && (l2 >= 0); l1--, l2--)
        {

            lli3.insert(lli3.begin(), 1, to_string(carry + lli1[l1] + lli2[l2]));
            if (lli3[0].size() == 19)
            {
                if (lli3[0][0] == '2')
                {
                    /* code */
                    lli3[op] = lli3[op].substr(1, 18);

                    // cout << lli3[0] << endl;
                }
                else if (lli3[0][0] == '3')
                {
                    lli3[op] = lli3[op].substr(1, 18);
                    // cout << lli3[0] << endl;
                    carry = 1;
                }

                else
                {
                    lli3[op] = lli3[op].substr(1, 18);
                    // cout << lli3[0] << endl;
                    // carry = 1;
                }
            }
            else
            {
                // cout << lli3[0] << endl;
                ;
                carry = 0;
            }
        }
        if (l1 >= 0)
        {
            while (l1 >= 0)
            {
                lli3.insert(lli3.begin(), 1, to_string(carry + lli1[l1--]));
                if (lli3[0].size() == 19)
                {
                    if (lli3[0][0] >= '2')
                    {
                        /* code */
                        lli3[0][0] = lli3[0][0] - '2';
                        // cout << lli3[0] << endl;
                        ;
                    }
                    else
                    {
                        lli3[op] = lli3[op].substr(1, 18);
                        // cout << lli3[0] << endl;
                        ;

                        // carry = 1;
                    }
                }
                // cout << lli3[0] << endl;
                ;
            }
        }
        else if (l2 >= 0)
        {
            while (l2 >= 0)
            {
                lli3.insert(lli3.begin(), 1, to_string(carry + lli2[l2--]));
                if (lli3[0].size() == 19)
                {
                    if (lli3[0][0] >= '2')
                    {
                        /* code */
                        lli3[0][0] = lli3[0][0] - '2';
                        // cout << lli3[0] << endl;
                    }
                    else
                    {
                        lli3[op] = lli3[op].substr(1, 18);
                        cout << lli3[0] << endl;

                        // carry = 1;
                    }
                }
            }
        }
        string outpt = "";
        for (int i = 0; i < lli3.size(); i++)
        {
            outpt += lli3[i];
        }
        return outpt;
    }
    int ii = 0;
    string subOp(akaBigInt s1, akaBigInt s2)
    {
        chunkingspecial(s1, s2);
        // Subtraction of two vectors
        vector<string> lli3;
        int borrow = 0;

        int l1, l2, op = 0, g = 0;
        for (l1 = lli1.size() - 1, l2 = lli2.size() - 1; (l1 >= 0) && (l2 >= 0); l1--, l2--)
        {
            long long int temp = lli1[l1] - lli2[l2];
            if (temp == 0)
            {
                lli3.insert(lli3.begin(), 1, "000000000000000000");
            }
            else if (temp < 0)
            {

                temp = lli1[l1] - lli2[l2] + 1000000000000000000;
                lli1[l1 - 1] = lli1[l1 - 1] - 1;
                lli3.insert(lli3.begin(), 1, fixsize(temp));
            }
            else
                lli3.insert(lli3.begin(), 1, fixsize(temp));
        }
        if (l1 >= 0)
        {
            while (l1 >= 0)
            {
                long long int temp = lli1[l1];
                if (temp < 0)
                {
                    lli1[l1] = lli1[l1] + 1000000000000000000;
                    temp = lli1[l1];
                    lli1[l1 - 1] = lli1[l1 - 1] - 1;
                    lli3.insert(lli3.begin(), 1, fixsize(lli1[l1]));
                }
                else if (temp == 0)
                {
                    lli3.insert(lli3.begin(), 1, "000000000000000000");
                }
                else if (temp == 999999999999999999)
                {
                    lli3.insert(lli3.begin(), 1, fixsize(temp));
                    lli1[l1 - 1] = lli1[l1 - 1] - 1;
                }
                else if (l1 == 0)
                {
                    // when to execute?
                    lli3.insert(lli3.begin(), 1, fixsize(temp - 1000000000000000000));
                }
                else
                {
                    // when to execute?
                    lli3.insert(lli3.begin(), 1, fixsize(temp));
                }

                l1--;
                /* code */
            }
        }

        string outpt = "";
        for (int i = 0; i < lli3.size(); i++)
        {
            outpt += lli3[i];
        }

        string res = leadingzero(outpt);
        return res;
    }

    akaBigInt &operator=(string s1)
    {
        this->s = s1;
        return *this;
    }

    akaBigInt operator=(akaBigInt s1)
    {
        this->s = s1.s;
        return *this;
    }

    void print()
    {
        cout << this->s;
    }

    int BIGcmp(string s1, string s2)
    {

        if (s1.size() > s2.size())
        {
            return 1;
        }
        else if (s1.size() < s2.size())
        {
            return -1;
        }
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] > s2[i])
                {
                    return 1;
                }
                else if (s1[i] < s2[i])
                {
                    return -1;
                }
            }
        }
        return 0;
    }

    string driver(akaBigInt s1, akaBigInt s2, string operation)
    {

        if (operation == "+")
        {
            if (s1.s[0] != '-' && s2.s[0] != '-')
            {

                return addOp(s1, s2);
            }
            else if (s1.s[0] == '-' && s2.s[0] == '-')
            {
                // substr karna hai
                s1.s = s1.s.substr(1, s1.s.size() - 1);
                s2.s = s2.s.substr(1, s2.s.size() - 1);

                return "-" + addOp(s1, s2);
            }
            else if (s1.s[0] == '-' && s2.s[0] != '-')
            {
                s1.s = s1.s.substr(1, s1.s.size() - 1);
                if (BIGcmp(s1.s, s2.s) == 1)
                {
                    return "-" + subOp(s1, s2);
                }
                else if (BIGcmp(s1.s, s2.s) == -1)
                {
                    return subOp(s2, s1);
                }
                else
                {
                    return "0";
                }
            }
            else
            {
                s2.s = s2.s.substr(1, s2.s.size() - 1);
                if (BIGcmp(s1.s, s2.s) == 1)
                {
                    return subOp(s1, s2);
                }
                else if (BIGcmp(s1.s, s2.s) == -1)
                {
                    return "-" + subOp(s2, s1);
                }
                else
                {
                    return "0";
                }
            }
        }
        else
        {
            if (s1.s[0] != '-' && s2.s[0] != '-')
            {
                if (BIGcmp(s1.s, s2.s) == 1)
                {
                    return subOp(s1, s2);
                }
                else if (BIGcmp(s1.s, s2.s) == -1)
                {
                    return "-" + subOp(s2, s1);
                }
                else
                {
                    return "0";
                }
            }
            else if (s1.s[0] == '-' && s2.s[0] == '-')
            {
                s1.s = s1.s.substr(1, s1.s.size() - 1);
                s2.s = s2.s.substr(1, s2.s.size() - 1);
                if (BIGcmp(s1.s, s2.s) == 1)
                {
                    return "-" + subOp(s1, s2);
                }
                else if (BIGcmp(s1.s, s2.s) == -1)
                {
                    return subOp(s2, s1);
                }
                else
                {
                    return "0";
                }
            }
            else if (s1.s[0] == '-' && s2.s[0] != '-')
            {
                s1.s = s1.s.substr(1, s1.s.size() - 1);
                return "-" + addOp(s1, s2);
            }
            else
            {
                s2.s = s2.s.substr(1, s2.s.size() - 1);
                return addOp(s1, s2);
            }
        }
    }

    string add(akaBigInt s1, akaBigInt s2)
    {
        string ans = driver(s1, s2, "+");
        return ans;
    }

    string sub(akaBigInt s1, akaBigInt s2)
    {
        string ans = driver(s1, s2, "-");
        return ans;
    }
};

int main()
{
    int choice=0;
    string s1,s2;
    akaBigInt num1, num2;
    cout<<"Welcome!";
    while(choice!=-1){
        cout<<"\nEnter First Number: ";
        cin>>s1;
        cout<<"\nEnter Second Number: ";
        cin>>s2;
        num1 = s1;
        num2 = s2;
label:  cout<<"\nEnter number of your choice: \n1) Add\n2) Subtract\n3) Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<num1.add(num1,num2);
            break;
            case 2:
            cout<<num1.sub(num1,num2);
            break;
            case 3:
            choice = -1;
            break;
            default:
            cout<<"Invalid Choice! Try Again!";
            goto label;
            break;
        }
    }
    return 0;
}
