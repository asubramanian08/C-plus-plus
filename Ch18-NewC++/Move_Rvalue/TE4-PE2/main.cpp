// Cpmv class skeleton given
#include <string>
#include <iostream>

class Cpmv // Given
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
        // Added
        Info(std::string qc, std::string zc) : qcode(qc), zcode(zc) {}
        void set(std::string qc, std::string zc) { qcode = qc, zcode = zc; }
    };

private:
    Info *pi;

public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv &&mv);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &cp);
    Cpmv &operator=(Cpmv &&mv);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};

// My implementation of methods
Cpmv::Cpmv() { pi = new Info("", ""); }
Cpmv::Cpmv(std::string q, std::string z) { pi = new Info(q, z); }
Cpmv::Cpmv(const Cpmv &cp) { pi = new Info(cp.pi->qcode, cp.pi->zcode); }
Cpmv::Cpmv(Cpmv &&mv) { pi = mv.pi, mv.pi = nullptr; }
Cpmv::~Cpmv() { delete pi; }
Cpmv &Cpmv::operator=(const Cpmv &cp)
{
    cp.pi->set(cp.pi->qcode, cp.pi->zcode);
    return *this;
}
Cpmv &Cpmv::operator=(Cpmv &&mv)
{
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}
Cpmv Cpmv::operator+(const Cpmv &obj) const { return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode); }
void Cpmv::Display(void) const { std::cout << "Qcode: " << pi->qcode << ", "
                                           << "Zcode" << pi->zcode << std::endl; }

int main(void)
{
    Cpmv c1("hi", "bob");
    c1.Display();
    Cpmv c2 = c1;
    c2.Display();
    c2 = Cpmv(" bye", " brown");
    c2.Display();
    Cpmv c3 = c1 + c2;
    c3.Display();
    c1 = c3;
    c1.Display();
    return 0;
}