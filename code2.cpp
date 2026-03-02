#include <iostream>
#include <cstdint>

using namespace std;

union FloatBits {
    float f;
    uint32_t u;
};

uint32_t addIEEE754(uint32_t a, uint32_t b) {

    int signA = (a >> 31) & 1;
    int signB = (b >> 31) & 1;

    int expA = (a >> 23) & 0xFF;
    int expB = (b >> 23) & 0xFF;

    uint32_t mantA = (a & 0x7FFFFF) | 0x800000; 
    uint32_t mantB = (b & 0x7FFFFF) | 0x800000;

    
    if (expA > expB) {
        mantB >>= (expA - expB);
        expB = expA;
    } else if (expB > expA) {
        mantA >>= (expB - expA);
        expA = expB;
    }

    uint32_t mantResult;
    int signResult = signA; 

  
    if (signA == signB) {
        mantResult = mantA + mantB;
    } else {
        if (mantA > mantB) {
            mantResult = mantA - mantB;
        } else {
            mantResult = mantB - mantA;
            signResult = signB;
        }
    }

    int expResult = expA;

  
    if (mantResult & 0x1000000) { 
        mantResult >>= 1;
        expResult++;
    }

    while ((mantResult & 0x800000) == 0 && expResult > 0) {
        mantResult <<= 1;
        expResult--;
    }

    
    mantResult &= 0x7FFFFF;

    
    return (signResult << 31) | (expResult << 23) | mantResult;
}

int main() {
    FloatBits a, b, result;

    cout << "‚Ά¥¤¨β¥ ¤Ά  η¨α« : ";
    cin >> a.f >> b.f;

    result.u = addIEEE754(a.u, b.u);

    cout << "¥§γ«μβ β: " << result.f << endl;

    return 0;
}
