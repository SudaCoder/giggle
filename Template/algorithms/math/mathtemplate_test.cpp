#include "mathtemplate.cpp"
using namespace std;

void runtest() {
    Math::init(100000);
    assert(Math::qp(19260817, 1145141919810) == 506560500);
    assert(Math::gcd(12345, 54321) == 3);
    assert(Math::getInv(998244353) == 4924091);
    assert(Math::lcm(12345, 54321) == 223530915);
    assert(Math::Perm(7, 3) == 210);
    assert(Math::Perm(233, 23) == 289853392);
    assert(Math::Comb(7, 3) == 35);
    assert(Math::Comb(233, 23) == 858813418);
    cout << "All Tests Passed!" << endl;
}

int main() {
    runtest();
}