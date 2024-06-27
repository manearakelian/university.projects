//   /////////////////////////////////////////////////////////////////////////////////// 
//  //////////////////////////   Qarakusi havasarum   ///////////////////////////////// 
// /////////////////////////////////////////////////////////////////////////////////// 

#include <iostream> 
#include <cmath> 
using namespace std;

class QH {
public:
    QH(float = 0, float = 0, float = 0);
    float D();
    void Xi();
    void Xa();
private:
    int a, b, c;
};
QH::QH(float i, float j, float k) {
    a = i; b = j; c = k;
    cout << "Qarakusi havasarumy hetevyaln e\n" << a << "*x*x + " << b << "*x + " << c << " = 0\n";
}
float QH::D() {
    return b * b - 4 * a * c;
}
void QH::Xi() {
    float x1, x2;
    if (a == 0 && b != 0) {
        x1 = (-c) / b;
        cout << x1;
    }
    else if (a != 0 && b == 0) {
        x1 = (-c) / a;
        if (x1 < 0) {
            x1 = -x1;
            cout << "x = " << sqrt(x1) << "i";
        }
        else cout << x1;
    }
    else if (a != 0 && b != 0 && c != 0) {
        // x1 = (-b + D()) / (2 * a); 
        // x2 = (-b - D()) / (2 * a); 
        if (D() >= 0) {
            float d = sqrt(D());
            x1 = -b / (2.0 * a) + d / (2.0 * a);
            x2 = -b / (2.0 * a) - d / (2.0 * a);
            cout << "x1 = " << -b << "/" << (2.0 * a) << " + " << d << "/" << (2.0 * a) << " = " << -b / (2.0 * a) << " + " << d / (2.0 * a) << x1 << endl;
            cout << "x2 = " << -b << "/" << (2.0 * a) << " - " << d << "/" << (2.0 * a) << " = " << -b / (2.0 * a) << " - " << d / (2.0 * a) << x2 << endl;
        }
        else {
            // ete D < 0 
            // x1 = -b / (2 * a) + D() / (2 * a); 
            // x2 = -b / (2 * a) - D() / (2 * a); 
            float d = sqrt(D() * -1);
            cout << "x1 = " << -b << "/" << (2.0 * a) << " + " << d << "i/" << (2.0 * a) << " = " << -b / (2.0 * a) << " + i" << d / (2.0 * a) << endl;
            cout << "x2 = " << -b << "/" << (2.0 * a) << " - " << d << "i/" << (2.0 * a) << " = " << -b / (2.0 * a) << " - i" << d / (2.0 * a) << endl;
        }
    }
    else if (a == 0 && b == 0 && c == 0) {
        cout << "Anverj bazmutyamb lucumner (x E R)";
    }
}
void QH::Xa() {
    // anirakan 
    float x1, x2;
    if (a == 0 && b == 0 && c != 0) {
        cout << "Datark bazmutyun";
    }
    else if (a == 0 && b == 0 && c == 0) {
        cout << "Anverj bazmutyamb lucumner (R)";
    }
}

int main() {
    float a, b, c;
    cout << "Enter a, b, c ";
    cin >> a >> b >> c;
    QH q1(a, b, c);
    cout << "D = " << q1.D() << endl;
    q1.Xi();

    return 0;
}