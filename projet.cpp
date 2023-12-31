#include <bits/stdc++.h>
#include <string.h>

using namespace std;
bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return is_leap_year(year) ? 29 : 28;
    default:
        return 0;
    }
}

int elapsed_days(int day, int month, int year)
{
    int days = 0;
    for (int y = 1; y < year; y++)
    {
        days += is_leap_year(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++)
    {
        days += days_in_month(m, year);
    }
    days += day;
    return days;
}

int difference_in_days(int day1, int month1, int year1, int day2, int month2, int year2)
{
    return abs(elapsed_days(day1, month1, year1) - elapsed_days(day2, month2, year2));
}
int datediff(const string & date1, const string & date2) {
    int j1,j2,m1,m2,a1,a2;
        j1 =stoi(date1.substr(0,2));
        j2 =stoi(date2.substr(0,2));
        m1 =stoi(date1.substr(3,2));
        m2 =stoi(date2.substr(3,2));
        a1 =stoi(date1.substr(6,4));
        a2 =stoi(date2.substr(6,4));
        return (difference_in_days(j1,m1,a1,j2, m2,a2));
    return 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int e,i,nb;
    string besc,lesc,date_esc;
    float t,tend;
    float pd,pn,dd,dn,tva1,tva2,tva3,tva4;
    cout<<"la banque d'escompte:"<<endl;
    cin>>besc;
    cout<<"le lieu d'escompte:"<<endl;
    cin>>lesc;
    cout<<"donner la date de l'escompte(jj/mm/aaaa):"<<endl;
    cin>>date_esc;
    cout<<"Conditions d escompte :"<<"\n"<<"- le taux (%):"<<endl;
    cin>>t;
    cout<<"-Commission d'endos (%):"<<endl;
    cin>>tend;
    cout<<"- nbre de jour de banque:"<<endl;
    cin>>nb;
    cout<<"- Commission fixe effet sur place domicilie :"<<endl;
    cin>>pd;
    cout<<"- Commission fixe effet sur place non-domicilie :"<<endl;
    cin>>pn;
    cout<<"- Commission fixe effet deplace domicilie :"<<endl;
    cin>>dd;
    cout<<"- Commission fixe effet deplace non-domicilie :"<<endl;
    cin>>dn;
    cout<<"- Taux de la TVA est de 18%."<<endl;
    cout<<"nbre d'effets:"<<endl;
    cin>>e;
    tva1=0.18*pd;
    tva2=0.18*pn;
    tva3=0.18*dd;
    tva4=0.18*dn;
    float v[e];
    int nje[e];
    string date_ech[e];
    string l[e];
    string b[e];
    float ag[e],agb[e],agend[e];
    for (int i=0;i<e;i++) {
        cout << "* Effet " << i + 1 << ":" << endl;
        cout << "Donner la valeur nominale " << i + 1 << " : "<<endl;
        cin >> v[i];
        cout << "Donner la date d'echeance (jj/mm/aaaa):"<<endl;
        cin >> date_ech[i];
        cout << "Donner le lieu d'echeance:"<<endl;
        cin >> l[i];
        cout << "Donner la banque d'echeance : "<<endl;
        cin >> b[i];
        nje[i]=datediff(date_esc,date_ech[i]);
        ag[i]=((v[i]*nje[i]*t)/36000);
        agb[i]=((v[i]*nb*t)/36000);
        agend[i]=((v[i]*(nje[i]+nb)*tend)/36000);
    }
    cout<<"      ------------"<<endl;
    cout<<"       Bordereau"<<endl;
    cout<<"Effet(s) remis a l'escompte"<<endl;
    cout<<"le "<<date_esc<<" de taux: "<<t<<endl;
    if (tend>0){
        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"| |"<<"Vn   |"<<"Echeance |"<<"Dom|"<<"pla|"<<"njE|"<<"AgjE|"<<"njB|"<<"AgjB |"<<"AgE1 |"<<"njend|"<<"Agend |"<<"AgE2 |"<<"AgCD |"<<"TotAgHT |"<<"TVA |"<<"TotAg TTC |"<<"Net Escompte|"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
        for (i=0;i<e;i++){
            if(lesc==l[i] && besc==b[i]){
                cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"oui"<<'|'<<"oui"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<nb+nje[i]<<'|'<<agend[i]<<'|'<<ag[i]+agb[i]+agend[i]<<'|'<<pd<<'|'<<ag[i]+agb[i]+agend[i]+pd<<'|'<<tva1<<'|'<<ag[i]+agb[i]+agend[i]+pd+tva1<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva1)<<'|'<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;}
            else{
                if (lesc==l[i]&& besc!=b[i]){
                     cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"non"<<'|'<<"oui"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<nb+nje[i]<<'|'<<agend[i]<<'|'<<ag[i]+agb[i]+agend[i]<<'|'<<pn<<'|'<<ag[i]+agb[i]+agend[i]+pn<<'|'<<tva2<<'|'<<ag[i]+agb[i]+agend[i]+pn+tva2<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva2)<<'|'<<endl;
                     cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;}
                else{
                    if (lesc!=l[i]&& besc==b[i]){
                        cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"oui"<<'|'<<"non"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<nb+nje[i]<<'|'<<agend[i]<<'|'<<ag[i]+agb[i]+agend[i]<<'|'<<dd<<'|'<<ag[i]+agb[i]+agend[i]+dd<<'|'<<tva3<<'|'<<ag[i]+agb[i]+agend[i]+dd+tva3<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva3)<<'|'<<endl;
                        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;}
                    else{
                        cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"non"<<'|'<<"non"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<nb+nje[i]<<'|'<<agend[i]<<'|'<<ag[i]+agb[i]+agend[i]<<'|'<<dn<<'|'<<ag[i]+agb[i]+agend[i]+dn<<'|'<<tva3<<'|'<<ag[i]+agb[i]+agend[i]+dn+tva4<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva4)<<'|'<<endl;
                        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
                    }
                }
            }
        }
    }
    else{
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
        cout<<"| |"<<"Vn   |"<<"Echeance |"<<"Dom|"<<"pla|"<<"njE|"<<"AgjE|"<<"njB|"<<"AgjB|"<<"AgE1|"<<"AgCD|"<<"TotAgHT|"<<"TVA|"<<"TotAg TTC |"<<"Net Escompte|"<<endl;
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
        for (i=0;i<e;i++)
            if(lesc==l[i] && besc==b[i]){
                cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"oui"<<'|'<<"oui"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<pd<<'|'<<ag[i]+agb[i]+agend[i]+pd<<'|'<<tva1<<'|'<<ag[i]+agb[i]+agend[i]+tva1+pd<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva1)<<'|'<<endl;
                cout<<"--------------------------------------------------------------------------------------------"<<endl;}
            else{
                if (lesc==l[i]&& besc!=b[i]){
                     cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"non"<<'|'<<"oui"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<pn<<'|'<<ag[i]+agb[i]+agend[i]+pn<<'|'<<tva2<<'|'<<ag[i]+agb[i]+agend[i]+tva2+pn<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva2)<<'|'<<endl;
                     cout<<"--------------------------------------------------------------------------------------------"<<endl;}
                else{
                    if (lesc!=l[i] && besc==b[i]){
                        cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"oui"<<'|'<<"non"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<dd<<'|'<<ag[i]+agb[i]+agend[i]+dd<<'|'<<tva3<<'|'<<ag[i]+agb[i]+agend[i]+tva3+dd<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva3)<<'|'<<endl;
                        cout<<"--------------------------------------------------------------------------------------------"<<endl;}
                    else{
                        cout<<'|'<<i+1<<'|'<<v[i]<<'|'<<date_ech[i]<<'|'<<"non"<<'|'<<"non"<<'|'<<nje[i]<<'|'<<ag[i]<<'|'<<nb<<'|'<<agb[i]<<'|'<<agb[i]+ag[i]<<'|'<<dn<<'|'<<ag[i]+agb[i]+agend[i]+dn<<'|'<<tva4<<'|'<<ag[i]+agb[i]+agend[i]+tva4+dn<<'|'<<v[i]-(ag[i]+agb[i]+agend[i]+tva4)<<'|'<<endl;
                        cout<<"--------------------------------------------------------------------------------------------"<<endl;;
                    }
                }
            }
    }
    return 0;
}
