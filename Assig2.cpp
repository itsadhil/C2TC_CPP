#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    friend istream& operator>>(istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream &out, const Complex &c) {
        if (c.imag >= 0)
            out << c.real << " + " << c.imag << "i";
        else
            out << c.real << " - " << -c.imag << "i";
        return out;
    }

    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex &c) const {
        float r = (real * c.real) - (imag * c.imag);
        float i = (real * c.imag) + (imag * c.real);
        return Complex(r, i);
    }

    bool operator==(const Complex &c) const {
        return (real == c.real && imag == c.imag);
    }
};

int main() {
    Complex c1, c2, result;
    int choice;

    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    do {
        cout << "\n--- Complex Number Calculator ---\n";
        cout << "1. Add (+)\n2. Subtract (-)\n3. Multiply (*)\n4. Compare (==)\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                result = c1 + c2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                result = c1 - c2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                result = c1 * c2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                if (c1 == c2)
                    cout << "Both complex numbers are equal.\n";
                else
                    cout << "Complex numbers are not equal.\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
