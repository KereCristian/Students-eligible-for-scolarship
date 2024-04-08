#include <cstring>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


class Student{
public:
    string nume;
    string prenume;
    vector <int> note;
    Student(string nume1, string prenume1, vector<int> note1){
        nume = nume1;
        prenume = prenume1;
        note = note1;
    }
    bool Integralist(){
        for(int i = 0; i<note.size(); i++){
            if(note[i] < 5) return false;
        }
        return true;
    }
    float Medie(){
        float suma=0;
        for(int i = 0; i<note.size(); i++){
            suma+=note[i];
        }
        return suma/(float)note.size();
    }
};

int main(){
    int m,n,p;
    cin >> m >> n >> p;
    vector<Student> v;
    string nume, prenume;

    int nota;
    for(int i = 0; i<m; i++){
        cin >> nume >> prenume;
        vector<int> note;
        for(int j = 0; j<n; j++){
            cin >> nota;
            note.push_back(nota);
        }
        v.push_back(Student(nume,prenume,note));
    }
    int k = 0,indexMax;
    float max = -1;
    for(int i = 0; i<v.size(); i++){
        if(v[i].Integralist() == true && v[i].Medie() >=8){
            k++;
            if(v[i].Medie() > max){
                max = v[i].Medie();
                indexMax = i;
            }
        }
    }
    k--;
    if(k<=p){
        cout << k << endl;
    }
    else{
        cout << p << endl;
    }
    cout << fixed << setprecision(2) << v[indexMax].nume << " " << v[indexMax].prenume << " " << v[indexMax].Medie();
    return 0;
}
